#include <iostream>
#include <string>
#include "HEADERS/Library.h"
#include "HEADERS/Parser.h"
using namespace std;
const int libStartSize = 3;
Library library(libStartSize);

void invalidInputError(string badIn){
    cout << "Input Error: \"" << badIn << "\" not understood." << endl;
}

int UI(){
    string line;
    cout << "Enter text: ";
    getline(cin, line);
    Parser command(line);
    string op = command.getOperation();
    string arg1 = command.getArg1();
    string arg2 = command.getArg2();
    // cout << "  op:" << op << endl;
    // cout << "arg1:" << arg1 << endl;
    // cout << "arg2:" << arg2 << endl;
    if(op.compare("select") == 0){
        
        return 0;
    }else if(op.compare("add") == 0){
        
        return 0;
    }else if(op.compare("remove") == 0){
        
        return 0;
    }else if(op.compare("show") == 0){
        
        return 0;
    }else if(op.compare("clone") == 0){
        
        return 0;
    }else if(op.compare("import") == 0){
        
        return 0;
    }else if(op.compare("exit") == 0){
        
        return 1;
    }else{
        invalidInputError(op);
        return 0;
    }
}

int main(){
    cout<<"\nHello and welcome to Nikofy!\n";
    while(UI() == 0);
    cout << "Ending Program" << endl;
}