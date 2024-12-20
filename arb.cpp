#include "arb.h"
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <iostream>

bool isOperator(char ch) {
    return strchr("+-*/%!&|><=", ch) != nullptr;
}

bool isUnaryOperator(string op) {
    return op == "!";
}

// Constructori
arb::arb() {
    this->root = nullptr;
}

arb::arb(nod* root) {
    this->root = root;
}

// Getters și setters
nod* arb::getRoot() {
    return root;
}

void arb::setRoot(nod* root) {
    this->root = root;
}

// Funcția pentru verificarea conflictelor de tip
bool arb::hasConflictingTypes(nod* start) {
    if (!start) return false;

    // Dacă nodul este o valoare literală (număr, string, etc.)
    if (isalnum(start->token[0])) {
        return false;
    }
    // Dacă nodul este un operator unar
    else if (isUnaryOperator(start->token)) {
        return hasConflictingTypes(start->left); // Verificăm doar copilul stâng
    }
    // Dacă nodul este un operator binar
    else if (isOperator(start->token[0])) {
        bool leftConflict = hasConflictingTypes(start->left);
        bool rightConflict = hasConflictingTypes(start->right);
        return leftConflict || rightConflict || (start->left->type != start->right->type);
    }
    return false;
}

// Determinarea tipului expresiei
String arb::getExpressionType(nod* start) {
    if (!start) return "unknown";

    // Verificăm pentru valoare numerică
    if (isdigit(start->token[0])) {
        start->type = "int";
        return "int";
    }

    // Verificăm pentru valori booleene
    if (start->token == "true" || start->token == "false") {
        start->type = "bool";
        return "bool";
    }

    // Verificăm pentru operatorii unari
    if (isUnaryOperator(start->token)) {
        String operandType = getExpressionType(start->left);
        start->type = operandType;
        if (start->token == "!"){
                return "bool";  
        }
        else if (start->token == "-") {
            if (operandType == "int") {
                return "int";
            }
            return "conflict";  // Dacă operandul nu este "int", avem un conflict
        }
    }

    // Verificăm pentru operatorii binari
    if (isOperator(start->token[0])) {
        String leftType = getExpressionType(start->left);
        String rightType = getExpressionType(start->right);
        if (start->token == "&&" || start->token == "||") {
            // Pentru operatorii logici, operanzii trebuie să fie booleeni
            if (leftType == "bool" && rightType == "bool") {
                return "bool";
            }
            return "conflict";
        }
        else if (leftType == rightType) {
            return leftType;  // Tipul expresiei binare va fi același pe ambele laturi
        }
        else {
            return "conflict";
        }
    }
    return start->type;  // Dacă este un nod de tip variabil sau constant, returnăm tipul acestuia
}
// Evaluarea expresiei
// Evaluarea expresiei
String arb::getExpressionResult(nod* start) {
    if (!start) return "";

    // Valori numerice
    if (isdigit(start->token[0])) {
        return start->token;
    }

    // Valori booleene
    if (start->token == "true" || start->token == "false") {
        return start->token;
    }

    // Operatorii unari
    if (isUnaryOperator(start->token)) {
        String operandResult = getExpressionResult(start->left);

        if (start->token == "!") {
            // Modificăm pentru a accepta tipul "int" și a compara cu 0
            if (start->left->token == "0" || operandResult == "0") {
                return "true";
            }
            return "false";
        }
        else if (start->token == "-") {
            return to_string(-stoi(operandResult));
        }
    }

    // Operatorii binari
    else if (isOperator(start->token[0])) {
        String leftResult = getExpressionResult(start->left);
        String rightResult = getExpressionResult(start->right);

        if (start->token == "+") {
            return to_string(stoi(leftResult) + stoi(rightResult));
        }
        if (start->token == "-") {
            return to_string(stoi(leftResult) - stoi(rightResult));
        }
        if (start->token == "*") {
            return to_string(stoi(leftResult) * stoi(rightResult));
        }
        if (start->token == "/") {
            if (stoi(rightResult) == 0) {
                throw runtime_error("Division by zero");
            }
            return to_string(stoi(leftResult) / stoi(rightResult));
        }
        else if (start->token == "&&") {
            return (leftResult == "true" && rightResult == "true") ? "true" : "false";
        }
        else if (start->token == "||") {
            return (leftResult == "true" || rightResult == "true") ? "true" : "false";
        }
    }

    return "unknown";
}

