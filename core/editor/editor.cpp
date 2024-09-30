#include "editor.hpp"

Editor::Editor(char* text, size_t cursor_pos) : text(Text(text)), cursor_pos(cursor_pos){}

Editor::~Editor(){}

void Editor::print(){
    text.print();
}

size_t Editor::get_pos(){
    return cursor_pos;
}

void Editor::move(size_t new_pos){
    cursor_pos = new_pos;
}

void Editor::remove(size_t start_pos, size_t end_pos){
    text.remove(start_pos, end_pos);
}

void Editor::add(char* word){
    size_t word_size = 0;
    for(int i = 0; word[i] != '\0'; i++){
        word_size++;
    }
    text.add(word, word_size);
}

void Editor::insert(char* word, size_t pos){
    size_t word_size = 0;
    for(size_t i = 0; word[i] != '\0'; i++){
        word_size++;
    }
    text.insert(word, pos, word_size);
}

void Editor::put(char* word){
    size_t word_size = 0;
    for(size_t i = 0; word[i] != '\0'; i++){
        word_size++;
    }
    text.insert(word, cursor_pos, word_size);
    cursor_pos += word_size;
}

void Editor::del(){
    text.del(cursor_pos);
}
