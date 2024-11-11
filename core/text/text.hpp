#ifndef TEXT_HPP
#define TEXT_HPP
#include <iostream>
#include <set>

class Text{
public:
    Text(char* text);
    ~Text();
    size_t get_size() const;
    void print(bool is_highlighted);
    void add(const char* word, size_t word_size); 
    void insert(const char* word, size_t pos, size_t word_size);
    void remove(size_t start_pos, size_t end_pos);
    void replace(const char& x, const char& y, std::set<int>& highlighted);
    void upcase(size_t start_pos, size_t end_pos);
    void lowcase(size_t start_pos, size_t end_pos);
    char operator[](size_t index) const;
private:
    char* text;
    size_t size;
    bool* is_highlighted;
};
#endif
