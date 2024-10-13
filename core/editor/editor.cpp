#include "editor.hpp"
//TODO: cursor position change
Editor::Editor(char* text, size_t cursor_pos) : text(Text(text)), cursor_pos(cursor_pos){
    
}

Editor::~Editor(){}

void Editor::print(){
    text.print(false);
}

size_t Editor::get_pos(){
    return cursor_pos;
}

void Editor::move(std::vector<char*> arguments){
    cursor_pos = std::stoi(arguments[0]);
}

void Editor::remove(std::vector<char*> arguments){
    text.remove(std::stoi(arguments[0]), std::stoi(arguments[1]));
}

void Editor::add(std::vector<char*> arguments){
    size_t word_size = 0;
    for(int i = 0; arguments[0][i] != '\0'; i++){
        word_size++;
    }
    text.add(arguments[0], word_size);
}

void Editor::insert(std::vector<char*> arguments){
    size_t word_size = 0;
    for(size_t i = 0; arguments[1][i] != '\0'; i++){
        word_size++;
    }
    text.insert(arguments[1], std::stoi(arguments[0]), word_size);
}

void Editor::put(std::vector<char*> arguments){
    size_t word_size = 0;
    for(size_t i = 0; arguments[0][i] != '\0'; i++){
        word_size++;
    }
    text.insert(arguments[0], cursor_pos, word_size);
    cursor_pos += word_size;
}

void Editor::del(){
    if(cursor_pos == 0){}
    else{
        text.remove(cursor_pos - 1, cursor_pos - 1);
    }
}

void Editor::del(std::vector<char*> arguments){
    if(cursor_pos == 0){}
    else{
        for(size_t i = 0; i < std::stoi(arguments[0]); i++){
            del();
        }
    }
}

void Editor::movelw(std::vector<char*> arguments){
    size_t n = std::stoi(arguments[0]);
    while(n > 0){
        cursor_pos--;
        if(text[cursor_pos] == ' '){
            n--;
        }
    }
}

void Editor::moverw(std::vector<char*> arguments){
    size_t n = std::stoi(arguments[0]);
    while(n > 0){
        cursor_pos++;
        if(text[cursor_pos] == ' '){
            n--;
        }
    }
}

void Editor::upcase(){
    size_t start_pos = cursor_pos;
    size_t end_pos = cursor_pos;
    for(start_pos; text[start_pos] != ' '; start_pos--);
    for(end_pos; text[end_pos] != ' '; end_pos++);
    text.upcase(start_pos, end_pos);
}

void Editor::lowcase(){
    size_t start_pos = cursor_pos;
    size_t end_pos = cursor_pos;
    for(start_pos; text[start_pos] != ' '; start_pos--);
    for(end_pos; text[end_pos] != ' '; end_pos++);
    text.lowcase(start_pos, end_pos);
}

void Editor::replace(std::vector<char*> arguments){
    text.replace(arguments[0][0], arguments[1][0]);
};

void Editor::find(std::vector<char*> arguments){
    text.find(arguments[0][0]);
}
