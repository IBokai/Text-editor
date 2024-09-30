#include <iostream>
#include <string>
#include "editor/editor.hpp"
int main(){
    std::string s = "Some Text";
    char* char_str = new char[s.size() + 1];
    for(size_t i = 0; i < s.size(); i++){
        char_str[i] = s[i];
    }
    char_str[s.size()] = '\0';
    Editor e(char_str);
    e.print();
}