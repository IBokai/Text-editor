#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "../text/text.hpp"
#include "../parser/parser.hpp"
#include <vector>
#include <set>

class Editor{
public:
    Editor(char* text, size_t cursor_pos = 0);
    ~Editor();
    void print();
    size_t get_pos() const;
    void add(std::vector<const char*>& arguments); //char* word
    void move(std::vector<const char*>& arguments); //int pos
    void insert(std::vector<const char*>& arguments); // int pos, char* word
    void put(std::vector<const char*>& arguments); // char* word
    void remove(std::vector<const char*>& arguments); // int start_pos, int end_pos
    void del(std::vector<const char*>& arguments); // no args
    void deln(std::vector<const char*>& arguments); // int n
    void movelw(std::vector<const char*>& arguments); // int n
    void moverw(std::vector<const char*>& arguments); // int n
    void upcase(std::vector<const char*>& arguments); // no args
    void lowcase(std::vector<const char*>& arguments); //no args
    void replace(std::vector<const char*>& arguments); //char* x, char* y
    void find(std::vector<const char*>& arguments); // char* x
    void run();
private:
    Text text;
    Parser parser;
    size_t cursor_pos;
    std::set<int> highlighted;
};
#endif
