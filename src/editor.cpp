#include <iostream>
#include "../include/editor.hpp"

Editor::Editor(char* text, size_t cursor_pos) : text(Text(text)), cursor_pos(cursor_pos){}

Editor::~Editor(){}

void Editor::print(){
    text.print();
}

size_t Editor::get_pos(){
    return cursor_pos;
}