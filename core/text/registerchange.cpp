#include "text.hpp"

void Text::upcase(size_t start_pos, size_t end_pos){
    for(int i = start_pos; i < end_pos; i++){
        text[i] = toupper(text[i]);
    }
}

void Text::lowcase(size_t start_pos, size_t end_pos){
    for(int i = start_pos; i < end_pos; i++){
        text[i] = tolower(text[i]);
    }
}
