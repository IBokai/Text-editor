#pragma once
#include <iostream>

class Text{
public:
    Text(char* text);
    ~Text();
    size_t get_size();
    void print();
    void add(char* word, size_t word_size);
    void insert(char* word, size_t pos, size_t word_size);
    void remove(size_t start_pos, size_t end_pos);
private:
    char* text;
    size_t size;
};