#pragma once
#include <string>
using namespace std;
#define String string
// Clasa arbore
class arb
{
private:
    String token;
    String type;
    arb *left;
    arb *right;

public:
    arb();
    arb(string token, string type);
    arb(string token, string type, arb *left, arb *right);
    arb *getRoot();
    bool hasConflictingTypes();
    String getExpressionType();
    String getExpressionResult();
    ~arb()
    {
        delete left;
        delete right;
    }
};
