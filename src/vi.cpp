#include <iostream>
#include <string>
#include "../include/editor.hpp"
int main()
{
    std::string string_text = "Some Text";
    char* text = new char[string_text.size() + 1];
    for(size_t i = 0; i < string_text.size(); i++) {text[i] = string_text[i];}
    text[string_text.size()] = '\0';
    Editor e(text);
    e.print();
}