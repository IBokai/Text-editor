#include <map>
#include "editor.hpp"
#include "../parser/parser.hpp"
#include <fstream>
//TODO: cursor position change

std::map<std::string, ParserCommandInfo> ParsingScheme{
    {"add", ParserCommandInfo({ParserParameter(std::regex("^[a-zA-Z]*?$"))}, &Editor::add)},
    {"move", ParserCommandInfo({ParserParameter(std::regex("^[1-9]*?[0-9]*?$"))}, &Editor::move)},
    {"insert", ParserCommandInfo({ParserParameter(std::regex("^[1-9][0-9]*?$")), ParserParameter(std::regex("^[a-zA-Z]*?$"))}, &Editor::insert)},
    {"put", ParserCommandInfo({ParserParameter(std::regex("^[a-zA-Z]*?$"))}, &Editor::put)},
    {"remove", ParserCommandInfo({ParserParameter(std::regex("^[1-9][0-9]*?$")), ParserParameter(std::regex("^[1-9][0-9]*?$"))}, &Editor::remove)},
    {"del", ParserCommandInfo({}, &Editor::del)},
    {"deln", ParserCommandInfo({ParserParameter(std::regex("^[1-9]*?[0-9]*?$"))}, &Editor::deln)},
    {"movelw", ParserCommandInfo({ParserParameter(std::regex("^[1-9][0-9]*?$"))}, &Editor::movelw)},
    {"moverw", ParserCommandInfo({ParserParameter(std::regex("^[1-9][0-9]*?$"))}, &Editor::moverw)},
    {"upcase", ParserCommandInfo({}, &Editor::upcase)},
    {"lowcase", ParserCommandInfo({}, &Editor::lowcase)},
    {"replace", ParserCommandInfo({ParserParameter(std::regex("^[a-zA-Z]*?$")), ParserParameter(std::regex("^[a-zA-Z]*?$"))}, &Editor::replace)},
    {"find", ParserCommandInfo({ParserParameter(std::regex("^[a-zA-Z]*?$"))}, &Editor::find)},
};

Editor::Editor(char* text, size_t cursor_pos) : text(Text(text)), cursor_pos(cursor_pos), parser(Parser(ParsingScheme)){}

Editor::~Editor(){}

size_t Editor::get_pos() const{
    return cursor_pos;
}

void Editor::add(std::vector<const char*>& arguments){
    size_t word_size = 0;
    for(int i = 0; arguments[0][i] != '\0'; i++){
        word_size++;
    }
    text.add(arguments[0], word_size);
}

void Editor::move(std::vector<const char*>& arguments){
    cursor_pos = std::stoi(arguments[0]);
}

void Editor::insert(std::vector<const char*>& arguments){
    size_t word_size = 0;
    for(size_t i = 0; arguments[1][i] != '\0'; i++){
        word_size++;
    }
    text.insert(arguments[1], std::stoi(arguments[0]), word_size);
}

void Editor::put(std::vector<const char*>& arguments){
    size_t word_size = 0;
    for(size_t i = 0; arguments[0][i] != '\0'; i++){
        word_size++;
    }
    text.insert(arguments[0], cursor_pos, word_size);
    cursor_pos += word_size;
}

void Editor::remove(std::vector<const char*>& arguments){
    text.remove(std::stoi(arguments[0]), std::stoi(arguments[1]));
}

void Editor::del(std::vector<const char*>& arguments){
    if(cursor_pos == 0){}
    else{
        text.remove(cursor_pos - 1, cursor_pos - 1);
    }
}

void Editor::deln(std::vector<const char*>& arguments){
    if(cursor_pos == 0){}
    else{
        for(size_t i = 0; i < std::stoi(arguments[0]); i++){
            del(arguments);
        }
    }
}

void Editor::movelw(std::vector<const char*>& arguments){
    size_t n = std::stoi(arguments[0]);
    while(n > 0){
        cursor_pos--;
        if(text[cursor_pos] == ' '){
            n--;
        }
    }
}

void Editor::moverw(std::vector<const char*>& arguments){
    size_t n = std::stoi(arguments[0]);
    while(n > 0){
        cursor_pos++;
        if(text[cursor_pos] == ' '){
            n--;
        }
    }
}

void Editor::upcase(std::vector<const char*>& arguments){
    size_t start_pos = cursor_pos;
    size_t end_pos = cursor_pos;
    for(start_pos; text[start_pos] != ' '; start_pos--);
    for(end_pos; text[end_pos] != ' '; end_pos++);
    text.upcase(start_pos, end_pos);
}

void Editor::lowcase(std::vector<const char*>& arguments){
    size_t start_pos = cursor_pos;
    size_t end_pos = cursor_pos;
    for(start_pos; text[start_pos] != ' '; start_pos--);
    for(end_pos; text[end_pos] != ' '; end_pos++);
    text.lowcase(start_pos, end_pos);
}

void Editor::replace(std::vector<const char*>& arguments){
    text.replace(arguments[0][0], arguments[1][0], highlighted);
};

void Editor::find(std::vector<const char*>& arguments){
    for(size_t i = 0; i < text.get_size(); i++){
        if(text[i] == arguments[0][0]){
            highlighted.insert(i);
        }
    }
}