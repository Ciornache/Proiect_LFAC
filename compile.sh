rm lang.tab.c
rm lang.tab.h
rm lex.yy.c
bison -d lang.y
flex lang.l            
g++ -std=c++17 symtable.cpp lex.yy.c lang.tab.c -o lang -lfl
./lang input.txt