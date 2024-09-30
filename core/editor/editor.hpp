#pragma once
#include "../text/text.hpp"

class Editor{
public:
    Editor(char* text, size_t cursor_pos = 0);
    ~Editor();
    void print();
    size_t get_pos();
    void add(char* word);
    void move(size_t new_pos);
    void insert(char* word, size_t pos);
    void put(char* word);
    void remove(size_t start_pos, size_t end_pos);
    void del();
private:
    Text text;
    size_t cursor_pos;
};
