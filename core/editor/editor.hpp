#ifndef EDITOR_HPP
#define EDITOR_HPP
#include <set>
#include <vector>

#include "../parser/parser.hpp"
#include "../text/text.hpp"

class Editor {
public:
    Editor(char* text, size_t cursor_pos = 0);
    ~Editor();
    void print();
    size_t get_pos() const;
    void add(std::vector<char const*>& arguments);      // char* word
    void move(std::vector<char const*>& arguments);     // int pos
    void insert(std::vector<char const*>& arguments);   // int pos, char* word
    void put(std::vector<char const*>& arguments);      // char* word
    void remove(std::vector<char const*>& arguments);   // int start_pos, int end_pos
    void del(std::vector<char const*>& arguments);      // no args
    void deln(std::vector<char const*>& arguments);     // int n
    void movelw(std::vector<char const*>& arguments);   // int n
    void moverw(std::vector<char const*>& arguments);   // int n
    void upcase(std::vector<char const*>& arguments);   // no args
    void lowcase(std::vector<char const*>& arguments);  // no args
    void replace(std::vector<char const*>& arguments);  // char* x, char* y
    void find(std::vector<char const*>& arguments);     // char* x
    void load(std::vector<char const*>& arguments);     // char* path to file
    void save(std::vector<char const*>& arguments);
    void run();

private:
    Text text;
    Parser parser;
    size_t cursor_pos;
    std::set<int> highlighted;
};
#endif
