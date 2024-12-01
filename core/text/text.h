#ifndef TEXT_H
#define TEXT_H
#include <cstring>
#include <iostream>
#include <set>

class Text {
public:
    Text(const char* text);
    Text();
    ~Text();
    void add(const char* word, size_t word_size);
    void insert(const char* word, size_t pos, size_t word_size);
    void remove(size_t start_pos, size_t end_pos);
    void replace(const char& x, const char& y, std::set<int>& highlighted);
    void upcase(size_t start_pos, size_t end_pos);
    void lowcase(size_t start_pos, size_t end_pos);
    Text& operator=(const Text& other);
    size_t get_size() const { return size; }
    char operator[](size_t index) const { return text[index]; };

private:
    char* text;
    size_t size;
};
#endif
