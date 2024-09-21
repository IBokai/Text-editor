#pragma once
#include "../include/text.hpp"
class Editor{
public:
    Editor(char* text, size_t cursor_pos = 0);
    ~Editor();
    void print();
    size_t get_pos();
private:
    Text text;
    size_t cursor_pos;
};