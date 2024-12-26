#include "arb.h"
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <iostream>

bool isOperator(char ch) {
    return strchr("+-*/%!&|><=", ch) != nullptr;
}

bool isUnaryOperator(string op) {
    return op == "!" || op == "-";
}

// Constructori
arb::arb() {
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

arb::arb(string token, string type, arb* left, arb* right)
{
    this->left = left;
    this->right = right;
    this->token = token;
    this->type = type;
}
// Getters și setters
arb* arb::getRoot() {
    return this;
}


// Funcția pentru verificarea conflictelor de tip
bool arb::hasConflictingTypes() {
    // Dacă nodul este o valoare literală (număr, string, etc.)
    if (isalnum(token[0])) {
        return false;
    }
    // Dacă nodul este un operator unar
    else if (isUnaryOperator(token)) {
        String type = left->getExpressionType();
        if (type == "bool" && token == "-")
            return true;
        return left->hasConflictingTypes(); // Verificăm doar copilul stâng
    }
    // Dacă nodul este un operator binar
    else if (isOperator(token[0])) {
        bool leftConflict = left->hasConflictingTypes();
        bool rightConflict = right->hasConflictingTypes();
        String leftType=left->getExpressionType();
        String rightType = right->getExpressionType();
        return leftConflict || rightConflict || (left->type != right->type) 
        || ((leftType=="bool" || rightType=="bool") && strchr("+-/*%=<",token[0]));
    }
    return false;
}

// Determinarea tipului expresiei
String arb::getExpressionType() {
  
    if (type != "")
        return type;
    // Operatorii unari
    if (isUnaryOperator(token)) {
        String operandType = left->getExpressionType();

        if (token == "!") {
            return "bool";
        }
        else if (token == "-") {
            return operandType;
        }
    }

    // Operatorii binari
    if (isOperator(token[0])) {
        String leftType = left->getExpressionType();
        String rightType = right->getExpressionType();

        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
            return leftType;
        }
        else if (token == "&&" || token=="||" || token== ">=" || token == ">" || token == "==" || token == "<=" || token == "<") {
            return "bool";
        }
    }

    return "unknown";
}
// Evaluarea expresiei
// Evaluarea expresiei
String arb::getExpressionResult() {
    if (isdigit(token[0])) {
        return token;
    }

    // Valori booleene
    if (token == "true" || token == "false") {
        return token;
    }

    // Operatorii unari
    if (isUnaryOperator(token)) {
        String operandResult = left->getExpressionResult();
        left->type = left->getExpressionType();
        if (token == "!") {
            if (left->type!="bool" && (left->token == "0" || operandResult == "0")) {
                return "true";
            }
            else if(left->type != "bool")
            return "false";
            else {
                if (operandResult == "true") return "false";
                return "true";
            }
        }
        else if (token == "-") {
            return to_string(-stoi(operandResult));
        }
    }

    // Operatorii binari
    if (isOperator(token[0])) {
        String leftResult = left->getExpressionResult();
        left->type = left->getExpressionType();
        String rightResult = right->getExpressionResult();
        right->type = right->getExpressionType();
        if (token == "+") {
            return to_string(stoi(leftResult) + stoi(rightResult));
        }
        if (token == "-") {
            return to_string(stoi(leftResult) - stoi(rightResult));
        }
        if (token == "*") {
            return to_string(stoi(leftResult) * stoi(rightResult));
        }
        if (token == "/") {
            if (stoi(rightResult) == 0) {
                throw runtime_error("Division by zero");
            }
            return to_string(stoi(leftResult) / stoi(rightResult));
        }
        else if (token == "&&") {
            return (leftResult == "true" && rightResult == "true") ? "true" : "false";
        }
        else if (token == "||") {
            return (leftResult == "true" || rightResult == "true") ? "true" : "false";
        }
        else if (token == ">") {
            if (stoi(leftResult) > stoi(rightResult))
                return "true";
            return "false";
        }
        else if (token == ">=") {
            if (stoi(leftResult) >= stoi(rightResult))
                return "true";
            return "false";
        }
        else if (token == "<") {
            if (stoi(leftResult) < stoi(rightResult))
                return "true";
            return "false";
        }
        else if (token == "<=") {
            if (stoi(leftResult) <= stoi(rightResult))
                return "true";
            return "false";
        }
    }

    return "unknown";
}

