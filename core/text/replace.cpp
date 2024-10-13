#include "text.hpp"

void Text::replace(const char& x, const char& y){
    is_highlighted = new bool[size];
    for(int i = 0; i < size; i++){
        if(text[i] == x){
            text[i] = y;
            is_highlighted[i] = true;
        }
    }
    print(true);
    delete[] is_highlighted;
}