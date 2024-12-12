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
    if(symExist.find(name) != symExist.end())
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
    std::cout << "Variable name: " << el.first << ", Value: ";
    std::string type = el.second.type;
    if(type == "int") 
        std::cout << get<int>(el.second.value) << '\n';
    else if(type == "float")
        std::cout << get<float>(el.second.value) << '\n';
    else if(type == "string")
        std::cout << get<string>(el.second.value) << '\n';
    else if(type == "bool")
        std::cout << get<bool>(el.second.value) << '\n';
}

void SymTable::updateSymbol(std::string name, value val)
{
    if(std::holds_alternative<int>(val))
    {
        if(symTable[name].type == "int")
            symTable[name].value = val;
        else if(symTable[name].type == "bool")
            symTable[name].value = get<int>(val) != 0;
    }
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