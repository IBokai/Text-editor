#include "text.hpp"

Text::Text(char* text) : text(text){
    size = 0;
    for(size_t i = 0; text[i] != '\0'; i++){
        size++;
    }
}

Text::~Text(){
    delete[] text;
}

size_t Text::get_size(){
    return size;
}

void Text::print(){
    std::cout << text << '\n';
}
