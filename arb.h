#pragma once
#include <string>
using namespace std;

#define String string

// Structura nod pentru arbore
struct nod {
    String token;
    String type;
    nod* left;
    nod* right;

    // Constructor implicit
    nod() {
        this->left = nullptr;
        this->right = nullptr;
        this->token = "";
        this->type = "";
    }

    // Constructor cu token și tip
    nod(string token, string type) {
        this->left = nullptr;
        this->right = nullptr;
        this->token = token;
        this->type = type;
    }

    // Constructor cu token, tip, stânga și dreapta
    nod(string token, string type, nod* left, nod* right) {
        this->left = left;
        this->right = right;
        this->token = token;
        this->type = type;
    }
};

// Clasa arbore
class arb {
private:
    nod* root;

public:
    arb();
    arb(nod* root);
    nod* getRoot();
    void setRoot(nod* root);
    bool hasConflictingTypes(nod* start);
    String getExpressionType(nod* start);
    String getExpressionResult(nod* start);
    ~arb() {
        delete root;
    }
};
