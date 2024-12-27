#include "symtable.h"


value SymTable::getSymbolValue(std::string s)
{
    return symTable[s].value;
}

bool SymTable::isSymbolValid(std::string s)
{
    return symExist[s];
}

std::string SymTable::getSymbolType(std::string s)
{
    return symTable[s].type;
}

bool SymTable::addSymbol(std::string name, std::string type)
{
    if(symTable.find(name) == symTable.end())
    {    
        symExist[name] = true;
        symTable[name].type = type; symTable[name].value = SymTable::getDefaultValue(type);
        return true;
    }   
    return false;
}

void SymTable::printVariables()
{
    for(auto el : symTable) 
        printVariable(el);
}

void SymTable::printVariable(std::pair<std::string, Symbol> el)
{
    std::ofstream g("log.out", ios_base::app);
    g << "Variable name: " << el.first << ", Type: " << el.second.type << ", Value: ";
    std::string type = el.second.type;
    if(type == "int") 
        g << get<int>(el.second.value) << '\n';
    else if(type == "float")
        g << get<float>(el.second.value) << '\n';
    else if(type == "string")
        g << get<string>(el.second.value) << '\n';
    else if(type == "bool")
        g << get<bool>(el.second.value) << '\n';
    else 
        g << "Undefined\n";
    g.close();
}

bool SymTable::updateSymbol(std::string name, value val)
{
    bool ok = 0;
    if(std::holds_alternative<int>(val) && symTable[name].type == "int") 
        symTable[name].value = val, ok = 1;
    else if(std::holds_alternative<std::string>(val) && symTable[name].type == "string")
        symTable[name].value = val, ok = 1;
    else if(std::holds_alternative<float>(val) && symTable[name].type == "float")
        symTable[name].value = val, ok = 1;
    else if(std::holds_alternative<bool>(val) && symTable[name].type == "bool")
        symTable[name].value = val, ok = 1;
    else if(std::holds_alternative<char>(val) && symTable[name].type == "char")
        symTable[name].value = val, ok = 1;
    else if(std::holds_alternative<Complex>(val) && symTable[name].type == "compl")
        symTable[name].value = val, ok = 1;
    return ok;
}

value SymTable::getDefaultValue(std::string type)
{
    if(type == "int") 
        return 0;
    else if(type == "float")
        return 0.0f;
    else if(type == "bool")
        return false;
    else if(type == "char")
        return ' ';
    else if(type == "string")
        return " ";
    else 
        return Complex(0, 0);
}

Symbol SymTable::getSymbol(std::string s)
{
    return symTable[s];
}

std::string SymTable::getSymTableName()
{
    return name;
}

std::string SymTable::getSymTableType()
{
    return type;
}

bool SymTable::isSymbolClassMember(std::string name)
{
    std::string type = this->getSymbolType(name);
    if(type == "int" || type == "float" || type == "string" || type == "char" || type == "bool" || type == "compl")
        return true;
    return false;
}

void SymTable::addParameter(std::string type)
{
    parameters.push_back(type);
}

bool SymTable::isParameterMatch(std::vector<std::string> parameters)
{
    if(parameters.size() != this->parameters.size())
        return false;
    for(unsigned int j = 0;j < parameters.size(); j++)
        if(parameters[j] != this->parameters[j])
            return false;
    return true;
}

void SymTable::printFunctionDescription()
{
    std::ofstream g("log.out", ios_base::app);
    g << '\n';
    g << "Function name: " << this->name << ", ";
    g << "Return type: " << this->type << ", ";
    if(parameters.size() == 1)
        g << "Function Header contains 1 parameter.\n";
    else 
        g << "Function Header contains " << this->parameters.size() << " parameters.\n";
    if(parameters.size() != 0) 
    {
        g << "Parameter List: ";
        for(auto parameter : parameters)
            g << parameter << ' ';
        g << '\n';
    }
    g << '\n';
    g.close();
}

bool SymTable::updateSymbol(std::string name, value val2, char op)
{
    value val = symTable[name].value;
    bool ok = 0;
    if(std::holds_alternative<int>(val) && symTable[name].type == "int" && std::holds_alternative<int>(val2))
        symTable[name].value = applyOperation(val, val2, op), ok = 1;
    else if(std::holds_alternative<std::string>(val) && symTable[name].type == "string")
        symTable[name].value = applyOperation(val, val2, op), ok = 1;
    else if(std::holds_alternative<float>(val) && symTable[name].type == "float")
        symTable[name].value = applyOperation(val, val2, op), ok = 1;
    else if(std::holds_alternative<bool>(val) && symTable[name].type == "bool")
        symTable[name].value = applyOperation(val, val2, op), ok = 1;
    else if(std::holds_alternative<char>(val) && symTable[name].type == "char")
        symTable[name].value = applyOperation(val, val2, op), ok = 1;
    else if(std::holds_alternative<Complex>(val) && symTable[name].type == "compl")
        symTable[name].value = applyOperation(val, val2, op), ok = 1;
    return ok;
}

value applyOperation(value val1, value val2, char op)
{
    auto applySign = [&](auto e1, auto e2) {
        if(op == '+')
            return e1 + e2;
        else if(op == '-') 
            return e1 - e2;
        else if(op == '*')
            return e1 * e2;
        else if(op == '/')
            return e1 / e2;
        else return e1 % e2;
    };
    if(std::holds_alternative<int>(val1)) 
    {
        int e1 = std::get<int>(val1), e2 = std::get<int>(val2);
        return value(applySign(e1, e2));
    }
    else if(std::holds_alternative<float>(val1)) 
    {
        int e1 = std::get<float>(val1), e2 = std::get<float>(val2);
        return value(applySign(e1, e2));
    }
    else if(std::holds_alternative<char>(val1)) 
    {
        char e1 = std::get<char>(val1), e2 = std::get<char>(val2);
        return value(applySign(e1, e2));
    }
    else if(std::holds_alternative<bool>(val1)) 
    {
        bool e1 = std::get<bool>(val1), e2 = std::get<bool>(val2);
        return value(applySign(e1, e2));
    }
    else if(std::holds_alternative<Complex>(val1))
    {
        Complex e1 = std::get<Complex>(val1), e2 = std::get<Complex>(val2);
        return value(applySign(e1, e2));
    }
    else if(std::holds_alternative<std::string>(val1))
    {
        std::string e1 = std::get<std::string>(val1), e2 = std::get<std::string>(val2);
        if(op != '+') 
        {
            std::cout << "Error: Cannot add two strings together!\n";
            exit(4);
        }
        return e1 + e2;
    }
    return 0;
}

ClassSymTable::ClassSymTable(std::string type, std::string name) : SymTable(type, name) {};

void SymTable::setFunctionName(std::string name)
{
    this->name = name;
}

void ClassSymTable::printClassAttributes()
{
    std::ofstream g("log.out", ios_base::app);
    g << "Class name: " << this->name << '\n';
    g << "######                   Class Attributes                   ######\n\n";
    for(auto [key, value] : symTable)
    {
        std::stringstream ss(key);
        std::string access, name;
        ss >> access >> name;
        g << "Attribute Name: " << name << ", Type: " << value.type << ", Value: ";
        if(std::holds_alternative<int>(value.value)) 
            g << get<int>(value.value) << '\n';
        else if(std::holds_alternative<std::string>(value.value))
            g << get<std::string>(value.value) << '\n';
        else if(std::holds_alternative<float>(value.value))
            g << get<float>(value.value) << '\n';
        else if(std::holds_alternative<char>(value.value))
            g << get<char>(value.value) << '\n';
        else if(std::holds_alternative<Complex>(value.value))
            g << get<Complex>(value.value) << '\n';
        else if(std::holds_alternative<bool>(value.value))
            g << get<bool>(value.value) << '\n';
    }

    for(unsigned int j = 0;j < this->funcSymTables.size(); j++) 
    {
        SymTable * funcTable = funcSymTables[j];
        std::stringstream ss;
        std::string name, access;
        ss << funcTable->getSymTableName();
        ss >> access >> name;
        g << '\n';
        g << "Method Name: " << name << ", ";
        g << "Return Type: " << funcTable->getSymTableType() << ", ";
        g << "Access Type: " << access << ". ";
        std::vector<std::string> parameters = funcTable->getParameters();
        if(parameters.size() == 1)
            g << "Method Header contains 1 parameter.\n";
        else 
            g << "Method Header contains " << this->parameters.size() << " parameters.\n";
        if(parameters.size() != 0) 
        {
            g << "Parameter List: ";
            for(auto parameter : parameters)
                g << parameter << ' ';
            g << '\n';
        }
    }
    g.close();
}

std::vector<SymTable*> ClassSymTable::getFuncSymTables()
{
    return this->funcSymTables;
}

void ClassSymTable::addFuncSymTable(SymTable * funcSymTable)
{
    funcSymTables.push_back(funcSymTable);
}

bool ClassSymTable::isSymbolInClass(std::string name)
{
    if(symExist[name]) 
        return true;
    for(unsigned int i = 0;i < this->funcSymTables.size(); i++) {
        if(this->funcSymTables[i]->getSymTableName() == name)
            return true;
    }
    return false;
}

std::vector<std::string> SymTable::getParameters()
{
    return parameters;
}

bool ClassSymTable::isSymbolValid(std::string s)
{
    for(auto [name, value] : symExist)
    {
        std::stringstream ss;
        std::string newName;
        newName = name; ss << newName;
        ss >> newName >> newName;
        if(newName == s) return true;
    }
    return false;
}

std::string ClassSymTable::getSymbolPrivacy(std::string s)
{
    std::stringstream ss;
    std::string prv;
    ss << s; ss >> prv;
    return prv;
}

ClassSymTable::~ClassSymTable()
{
    for(unsigned int j = 0;j < funcSymTables.size(); j++)
        delete funcSymTables[j];
}