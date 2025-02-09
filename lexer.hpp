#include <iostream>
#include <string>
#include <cctype>
#include "known.hpp"
#include <algorithm>

using namespace std;



enum type{
    keyword,
    identifier,
    number,
    word,
    letter,
    operater,
    special,
    invalid,
    end
};

struct token {
    type name;
    string lexeme;
};

class Lexer{
    private : 
        int pos;
        string l_input; 

    public:

        Lexer (const string & input ) : pos(0), l_input(input) {}
        
        token next_Token(){

            token result ; 
            string lexeme = "";
            
            // skip the initial space or if there is no token left
            while(isspace(l_input[pos]) && pos!= l_input.size()){
                pos++;
            }
            if(pos >= l_input.size()){                
                return {type :: end, ""};
            }



            char current = l_input[pos];

            if( search(operators,current)){
                lexeme+= current;
                pos++;
                return {type :: operater, lexeme};
            }
            else if(search(specials,current)){
                lexeme+= current;
                pos++;
                return {type :: special, lexeme};
            }

            while(!isspace(current) && !search(operators,current) && !search(specials,current)){
                lexeme += current;
                pos++;
                current = l_input[pos];
            }
            
            result.lexeme = lexeme;

            bool option = isalpha(lexeme[0]) || (lexeme[0] == '_') ? true : false;

            if (option && search(keywords, lexeme)){
                result.name = type :: keyword;
                return result;
            }
            else if(option) return {type :: identifier, lexeme};
            
            
            else { 
                int work = 0; 

                if (isdigit(lexeme[0])) {  
                    work = 1; 
                } else if (lexeme[0] == '\'') {  
                    work = 2; 
                } else if (lexeme[0] == '"') {  
                    work = 3;
                }
                
                switch (work){
                    case 1 : 
                        if( all_of(lexeme.begin(), lexeme.end(), [](char c){ return isdigit(c); }) )
                            result.name = number;
                        else result.name = invalid;                                        
                    break;

                    case 2 :
                        if( lexeme[lexeme.size()-1] == '\'' && lexeme.size() == 3) 
                            result.name = letter;
                        else result.name = invalid;
                    break;

                    case 3 : 
                        if( lexeme[lexeme.size()-1] == '"')
                            result.name = word;
                        else result.name = invalid;
                    break;

                    default: result.name = invalid;
 
                }
                if(result.name == type:: invalid ){
                    cout << endl << "syntax wrong at char : " << pos - lexeme.size() + 2 << endl;
                }
                return result;
            } 

            


        }
};






// int main(){

// }