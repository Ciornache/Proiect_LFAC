#include <string>
#include <variant>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

struct Complex
{
    float real;
    float imag;

    Complex(float number) : real(number), imag(number) {};
    Complex(float real, float imag) : real(real), imag(imag) {};
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        if (c.imag == 0 && c.real == 0)
            os << '0';
        else if (c.imag != 0 && c.real == 0)
        {
            os << c.imag << 'i';
        }
        else
        {
            if (c.imag > 0)
                os << c.real << '+' << c.imag << 'i';
            else if (c.imag < 0)
                os << c.real << c.imag << 'i';
            else
                os << c.real;
            
        }
        return os;
    }
    Complex operator+(const Complex &c)
    {
        return {this->real + c.real, this->imag + c.imag};
    }
    Complex operator-(const Complex &c)
    {
        return {this->real - c.real, this->imag - c.imag};
    }
    Complex operator*(const Complex &c)
    {
        return {this->real * c.real - this->imag * c.imag, this->imag * c.real + this->real * c.imag};
    }
    Complex operator/(const Complex &c)
    {
        return {(this->real * c.real + this->imag * c.imag) / (c.real * c.real + c.imag * c.imag), (this->imag * c.real - this->real * c.imag) / (c.real * c.real + c.imag * c.imag)};
    }
    Complex operator%(const Complex &c)
    {
        return {0.0,0.0};
    }
};
struct Symbol
{
    std::string type;
    std::variant<int, float, char, bool, std::string, Complex> value;
};

typedef std::variant<int, float, char, bool, std::string, Complex> value;

class SymTable
{
    protected:
        std::map<std::string, Symbol> symTable;
        std::map<std::string, bool> symExist;
        std::vector<std::string> parameters;
        std::string type, name;
    public:
        static value getDefaultValue(std::string type);
        value getSymbolValue(std::string s);
        Symbol getSymbol(std::string s);
        virtual bool isSymbolValid(std::string s);
        bool addSymbol(std::string name, std::string type);
        bool updateSymbol(std::string name, value val);
        bool updateSymbol(std::string name, value val2, char op);
        void printVariables();
        void printVariable(std::pair<std::string, Symbol> el);
        std::string getSymbolType(std::string s);
        SymTable(std::string type, std::string name) : type(type), name(name) {};
        SymTable() {};
        SymTable(SymTable * symTable);
        std::string getSymTableName();
        std::string getSymTableType();
        bool isSymbolClassMember(std::string name);
        void addParameter(std::string type);
        bool isParameterMatch(std::vector<std::string> parameters);
        void printFunctionDescription();
        void setFunctionName(std::string name);
        std::vector<std::string> getParameters();
        std::map<std::string, bool> getSymExist();
};

class ClassSymTable : public SymTable
{
    std::vector<SymTable*> funcSymTables;
    public:
        void addFuncSymTable(SymTable * funcSymTable);
        bool isSymbolInClass(std::string name);
        bool isFunctionValid(std::vector<string> parameters);
        std::vector<SymTable*> getFuncSymTables();
        void printClassAttributes();
        void printClassMethod(SymTable * funcTable);
        virtual bool isSymbolValid(std::string s);
        std::string getSymbolPrivacy(std::string s);
        ClassSymTable(std::string type, std::string name);
        ClassSymTable();    
        ~ClassSymTable();
        ClassSymTable(ClassSymTable * classSymTable, std::string type, std::string name);
};

value applyOperation(value val, value val2, char op);