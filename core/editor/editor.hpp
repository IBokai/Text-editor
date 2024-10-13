#pragma once
#include "../text/text.hpp"
#include <vector>

class Editor{
public:
    Editor(char* text, size_t cursor_pos = 0);
    ~Editor();
    void print();
    size_t get_pos();
    void add(std::vector<char*> arguments); //char* word
    void move(std::vector<char*> arguments); //int pos
    void insert(std::vector<char*> arguments); // int pos, char* word
    void put(std::vector<char*> arguments); // char* word
    void remove(std::vector<char*> arguments); // int start_pos, int end_pos
    void del(); // no args
    void del(std::vector<char*> arguments); // int n
    void movelw(std::vector<char*> arguments); // int n
    void moverw(std::vector<char*> arguments); // int n
    void upcase(); // no args
    void lowcase(); //no args
    void replace(std::vector<char*> arguments); //char* x, char* y
    void find(std::vector<char*> arguments); // char* x
private:
    Text text;
    size_t cursor_pos;
};
