#include <iostream>
#include <fstream>
#include "lexer.hpp"
using namespace std;


string typeTostring(type Type){
    switch(Type){
        case 0:   return "keyword";  
        case 1:   return "identifier";  
        case 2:   return "number";  
        case 3:   return "string";  
        case 4:   return "character";  
        case 5:   return "operator";  
        case 6:   return "special"; 
        case 7:   return "invalid"; 
    }  
}  
    

// Main function for testing
int main() {
    string line;
    ifstream hin("sample.txt");
    string code ;
    
    
    while(getline(hin, line)){
        code += line;
        code += ' ';
    }
    cout << code<< endl;

    Lexer lexer(code);

    vector< token> tokens;
    token current_token = lexer.next_Token();

    while(current_token.name  != type:: end){ 
        if(current_token.name == invalid){
            return 0;
        }
        tokens.push_back(current_token);
        current_token = lexer.next_Token();
    }


    cout << "Tokens:\n";
    for (const auto& token : tokens) {
        cout << typeTostring(token.name) << ": " << token.lexeme << endl ;
    }

    return 0;

    
}
