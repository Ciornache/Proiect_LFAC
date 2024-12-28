#include "arb.h"
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include "symtable.h"
using namespace std;
Complex parseComplex(const string &token)
{
    size_t iPos = token.find('i'); // poztia lui i

    size_t plusPos = token.find_last_of('+', iPos); // pozitia lu + si -
    size_t minusPos = token.find_last_of('-', iPos);

    size_t splitPos = (plusPos != string::npos) ? plusPos : minusPos; // vedem care e diferita de npos(care e )

    if (splitPos == string::npos)
    {
        throw runtime_error("Invalid complex number format: " + token); // in teorie nu ar trebuie sa se poata da na just in case
    }
    int real = stoi(token.substr(0, splitPos));
    int imag = stoi(token.substr(splitPos + 1, iPos - splitPos - 1));

    if (token[splitPos] == '-')
    {
        imag = -imag;
    }

    return Complex(real, imag);
}

bool isOperator(char ch)
{
    return strchr("+-*/%!&|><=", ch) != nullptr;
}

bool isUnaryOperator(string op)
{
    return op == "!" || op == "-";
}

// Constructori
arb::arb()
{
    this->left = nullptr;
    this->right = nullptr;
    this->token = "";
    this->type = "";
}

arb::arb(string token, string type)
{
    this->left = nullptr;
    this->right = nullptr;
    this->token = token;
    this->type = type;
}

arb::arb(string token, string type, arb *left, arb *right)
{
    this->left = left;
    this->right = right;
    this->token = token;
    this->type = type;
}
// Getters și setters
arb *arb::getRoot()
{
    return this;
}

// Funcția pentru verificarea conflictelor de tip
bool arb::hasConflictingTypes()
{
    // Dacă nodul este o valoare literală (număr, string, etc.)
    if (isalnum(token[0]) || token.size() > 0 && token[0] == '-' && isalnum(token[1]))
    {
        return false;
    }
    // Dacă nodul este un operator unar
    else if (isUnaryOperator(token))
    {
        String type = left->getExpressionType();
        if ((type == "bool" || type == "string") && token == "-")
            return true;
        return left->hasConflictingTypes(); // Verificăm doar copilul stâng
    }
    // Dacă nodul este un operator binar
    else if (isOperator(token[0]))
    {
        bool leftConflict = left->hasConflictingTypes();
        bool rightConflict = right->hasConflictingTypes();
        String leftType = left->getExpressionType();
        String rightType = right->getExpressionType();

        if (leftType == "string" && rightType == "string" && token != "+" && token != "==" && token != "!=" && token != ">=" && token != "<=" && token != ">" && token != "<")
            return true;

        if (leftType == "float" && rightType == "float" && token == "%")
            return true;

        return leftConflict || rightConflict || (leftType != rightType) || ((leftType == "bool" || rightType == "bool") && strchr("+-/*%=<", token[0]));
    }
    return false;
}

// Determinarea tipului expresiei
String arb::getExpressionType()
{
    if (type != "")
        return type;
    // Operatorii unari
    if (isUnaryOperator(token))
    {
        String operandType = left->getExpressionType();

        if (token == "!")
        {
            return "bool";
        }
        else if (token == "-")
        {
            return operandType;
        }
    }

    // Operatorii binari
    if (isOperator(token[0]))
    {
        String leftType = left->getExpressionType();
        String rightType = right->getExpressionType();

        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
        {
            return leftType;
        }
        else if (token == "&&" || token == "||" || token == ">=" || token == ">" || token == "==" || token == "<=" || token == "<" || token == "!=")
        {
            return "bool";
        }
    }
    return "unknown";
}
// Evaluarea expresiei
// Evaluarea expresiei
String arb::getExpressionResult()
{
    /// Am adaugat partea a doua din conditie pentru numere negative. Exista unele numere care devin negative pe parcursul executiei programului si nu vor avea minus ca operator unar in fata a.i nu vor fi recunoscute fara partea asta din if
    if (isdigit(token[0]) || token.size() > 1 && token[0] == '-' && isdigit(token[1]))
    {
        return token;
    }
    // Valori booleene
    if (token == "true" || token == "false")
        return token;

    // Operatorii unari
    if (isUnaryOperator(token))
    {
        String operandResult = left->getExpressionResult();
        left->type = left->getExpressionType();

        if (token == "!")
        {
            if (left->type != "bool" && (left->token == "0" || operandResult == "0"))
            {
                return "true";
            }
            else if (left->type != "bool")
            {
                return "false";
            }
            else
            {
                return (operandResult == "true") ? "false" : "true";
            }
        }
        else if (token == "-")
        {
            if (left->type == "int" || left->type == "bool")
            {
                return to_string(-stoi(operandResult));
            }
            else if (left->type == "float")
            {
                return to_string(-stof(operandResult));
            }
            else if (left->type == "compl")
            {
                Complex complexOperand = parseComplex(operandResult);
                Complex negated = Complex(-complexOperand.real, -complexOperand.imag);
                if (negated.imag > 0)
                    return to_string(negated.real) + "+" + to_string(negated.imag) + "i";
                else
                    return to_string(negated.real) + to_string(negated.imag) + "i";
            }
        }
    }

    // Operatorii binari
    if (isOperator(token[0]))
    {
        String leftResult = left->getExpressionResult();
        left->type = left->getExpressionType();
        String rightResult = right->getExpressionResult();
        right->type = right->getExpressionType();
        if (token == "+")
        {
            if (left->type == "float")
                return to_string(stof(leftResult) + stof(rightResult));
            else if (left->type == "compl")
            {
                Complex t1 = parseComplex(leftResult);
                Complex t2 = parseComplex(rightResult);
                Complex result = t1 + t2;
                if (result.imag > 0)
                    return to_string(result.real) + "+" + to_string(result.imag) + "i";
                else
                    return to_string(result.real) + to_string(result.imag) + "i";
            }
            else if (left->type == "int" || left->type == "bool")
                return to_string(stoi(leftResult) + stoi(rightResult));
            else if (left->type == "string")
                return leftResult + rightResult;
            else if (left->type == "char")
                return to_string(char(int(leftResult[0]) + int(rightResult[0])));
        }
        if (token == "-")
        {
            if (left->type == "float")
                return to_string(stof(leftResult) - stof(rightResult));
            else if (left->type == "compl")
            {
                Complex t1 = parseComplex(leftResult);
                Complex t2 = parseComplex(rightResult);
                Complex result = t1 - t2;
                if (result.imag > 0)
                    return to_string(result.real) + "+" + to_string(result.imag) + "i";
                else
                    return to_string(result.real) + to_string(result.imag) + "i";
            }
            else if (left->type == "int" || left->type == "bool")
                return to_string(stoi(leftResult) - stoi(rightResult));
            else if (left->type == "char")
                return to_string(char(int(leftResult[0]) - int(rightResult[0])));
        }
        if (token == "*")
        {
            if (left->type == "float")
                return to_string(stof(leftResult) * stof(rightResult));
            else if (left->type == "compl")
            {
                Complex t1 = parseComplex(leftResult);
                Complex t2 = parseComplex(rightResult);
                Complex result = t1 * t2;
                if (result.imag > 0)
                    return to_string(result.real) + "+" + to_string(result.imag) + "i";
                else
                    return to_string(result.real) + to_string(result.imag) + "i";
            }
            else if (left->type == "int" || left->type == "bool")
                return to_string(stoi(leftResult) * stoi(rightResult));
            else if (left->type == "char")
                return to_string(char(int(leftResult[0]) * int(rightResult[0])));
        }
        if (token == "/")
        {
            if (stoi(rightResult) == 0)
                throw runtime_error("Division by zero");
            if (left->type == "float")
                return to_string(stof(leftResult) / stof(rightResult));
            else if (left->type == "compl")
            {
                Complex t1 = parseComplex(leftResult);
                Complex t2 = parseComplex(rightResult);
                Complex result = t1 / t2;
                if (result.imag > 0)
                    return to_string(result.real) + "+" + to_string(result.imag) + "i";
                else
                    return to_string(result.real) + to_string(result.imag) + "i";
            }
            else if (left->type == "int" || left->type == "bool")
                return to_string(stoi(leftResult) / stoi(rightResult));
            else if (left->type == "char")
                return to_string(char(int(leftResult[0]) / int(rightResult[0])));
        }
        else if (token == "%")
        {
            if (stoi(rightResult) == 0)
                throw runtime_error("Division by zero");
            else if (left->type == "compl")
            {
                Complex t1 = parseComplex(leftResult);
                Complex t2 = parseComplex(rightResult);
                Complex result = t1 % t2;
                if (result.imag > 0)
                    return to_string(result.real) + "+" + to_string(result.imag) + "i";
                else
                    return to_string(result.real) + to_string(result.imag) + "i";
            }
            else if (left->type == "int" || left->type == "bool")
                return to_string(stoi(leftResult) % stoi(rightResult));
            else if (left->type == "char")
                return to_string(char(int(leftResult[0]) % int(rightResult[0])));
        }
        else if (token == "&&")
        {
            return (leftResult == "true" && rightResult == "true") ? "true" : "false";
        }
        else if (token == "||")
        {
            return (leftResult == "true" || rightResult == "true") ? "true" : "false";
        }
        else if (token == ">")
        {
            if (left->type == "int" || left->type == "bool")
            {
                if (stoi(leftResult) > stoi(rightResult))
                    return "true";
                return "false";
            }
            else if (left->type == "string" || left->type == "char")
            {
                if (leftResult > rightResult)
                    return "true";
                return "false";
            }
            else if (left->type == "float")
            {
                if (stof(leftResult) > stof(rightResult))
                    return "true";
                return "false";
            }
        }
        else if (token == ">=")
        {
            if (left->type == "int" || left->type == "bool")
            {
                if (stoi(leftResult) >= stoi(rightResult))
                    return "true";
                return "false";
            }
            else if (left->type == "string" || left->type == "char")
            {
                if (leftResult >= rightResult)
                    return "true";
                return "false";
            }
            else if (left->type == "float")
            {
                if (stof(leftResult) >= stof(rightResult))
                    return "true";
                return "false";
            }
        }
        else if (token == "<")
        {
            if (left->type == "int" || left->type == "bool")
            {
                if (stoi(leftResult) < stoi(rightResult))
                    return "true";
                return "false";
            }
            else if (left->type == "string" || left->type == "char")
            {
                if (leftResult < rightResult)
                    return "true";
                return "false";
            }
            else if (left->type == "float")
            {
                if (stof(leftResult) < stof(rightResult))
                    return "true";
                return "false";
            }
        }
        else if (token == "<=")
        {
            if (left->type == "int" || left->type == "bool")
            {
                if (stoi(leftResult) <= stoi(rightResult))
                    return "true";
                return "false";
            }
            else if (left->type == "string" || left->type == "char")
            {
                if (leftResult <= rightResult)
                    return "true";
                return "false";
            }
            else if (left->type == "float")
            {
                if (stof(leftResult) <= stof(rightResult))
                    return "true";
                return "false";
            }
        }
        else if (token == "!=")
        {
            if (left->type == "int" || left->type == "bool")
            {
                if (stoi(leftResult) != stoi(rightResult))
                    return "true";
                return "false";
            }
            else if (left->type == "string" || left->type == "char")
            {
                if (leftResult != rightResult)
                    return "true";
                return "false";
            }
            else if (left->type == "float")
            {
                if (stof(leftResult) != stof(rightResult))
                    return "true";
                return "false";
            }
        }
    }

    return token;
}
