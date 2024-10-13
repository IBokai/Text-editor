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

void Text::find(const char& x){
    is_highlighted = new bool[size];
    for(int i = 0; i < size; i++){
        if(text[i] == x){
            is_highlighted[i] = true;
        }
    }
    print(true);
    delete[] is_highlighted;
}

char Text::operator[](size_t index) const{
    return text[index];
};