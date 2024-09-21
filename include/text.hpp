#pragma once
#include <iostream>
class Text{
public:
    Text(char* text);
    ~Text();
    size_t get_size();
    void print();
private:
    char* text;
    size_t size;
};