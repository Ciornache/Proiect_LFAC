#include <string>
#include <variant>
#include <map>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Complex
{
    int real;
    int imag;
    Complex(int real, int imag) : real(real), imag(imag) {};
};

struct Symbol
{
    std::string type;
    std::variant<int, float, char, bool, std::string, Complex> value;
};

typedef std::variant<int, float, char, bool, std::string, Complex> value;

class SymTable
{
    std::map<std::string, Symbol> symTable;
    std::map<std::string, bool> symExist;
    public:
        static value getDefaultValue(std::string type);
        value getSymbolValue(std::string s);
        Symbol getSymbol(std::string s);
        bool isSymbolValid(std::string s);
        bool addSymbol(std::string name, std::string type);
        void updateSymbol(std::string name, value val);
        void printVariables();
        void printVariable(std::pair<std::string, Symbol> el);
        std::string getSymbolType(std::string s);
};

