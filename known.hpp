#include <iostream>  
#include <vector>  
#include <string>  
#include <algorithm>

using namespace std;

#define search(vec,item) (find(vec.begin(),vec.end(),item)!=vec.end())  

vector<string> keywords = {
    "int",
    "float",
    "if",
    "else",
    "for",
    "while",
    "char",
    "double",
    "string"
};

// int main(){
//     string let ="els";
//     bool t = search(keywords,let);
//     cout << t<< endl;
// }

vector<char> operators = {
    '+', '-', '*','%','='
};
vector<char> specials = {
    '{','}', '(', ')', ',', ';'
};
