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
    int real;
    int imag;
    Complex(int number) : real(number), imag(number) {};
    Complex(int real, int imag) : real(real), imag(imag) {};
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real << ' ' << c.imag;
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
        return {(this->real * c.real + this->imag * c.imag) / (this->imag * this->imag + c.imag * c.imag), (this->imag * c.real - this->real * c.imag) / (this->imag * this->imag + c.imag * c.imag)};
    }
    Complex operator%(const Complex &c)
    {
        return {this->real % c.real, this->imag % c.imag};
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
    std::string getSymTableName();
    std::string getSymTableType();
    bool isSymbolClassMember(std::string name);
    void addParameter(std::string type);
    bool isParameterMatch(std::vector<std::string> parameters);
    void printFunctionDescription();
    void setFunctionName(std::string name);
    std::vector<std::string> getParameters();
};

class ClassSymTable : public SymTable
{
    std::vector<SymTable *> funcSymTables;

public:
    void addFuncSymTable(SymTable *funcSymTable);
    bool isSymbolInClass(std::string name);
    bool isFunctionValid(std::vector<string> parameters);
    std::vector<SymTable *> getFuncSymTables();
    void printClassAttributes();
    void printClassMethod(SymTable *funcTable);
    virtual bool isSymbolValid(std::string s);
    std::string getSymbolPrivacy(std::string s);
    ClassSymTable(std::string type, std::string name);
    ClassSymTable();
    ~ClassSymTable();
};

value applyOperation(value val, value val2, char op);