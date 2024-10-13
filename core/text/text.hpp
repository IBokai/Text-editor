#pragma once
#include <iostream>

class Text{
public:
    Text(char* text);
    ~Text();
    size_t get_size();
    void print(bool is_highlighted);
    void add(char* word, size_t word_size);
    void insert(char* word, size_t pos, size_t word_size);
    void remove(size_t start_pos, size_t end_pos);
    void replace(const char& x, const char& y);
    void upcase(size_t start_pos, size_t end_pos);
    void lowcase(size_t start_pos, size_t end_pos);
    void find(const char& x);
    char operator[](size_t index) const;
private:
    char* text;
    size_t size;
    bool* is_highlighted;
};