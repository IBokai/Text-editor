#include "../util/util.hpp"
#include "text.hpp"

void Text::insert(char* word, size_t pos, size_t word_size){
    char* temp_left = new char[pos];
    char* temp_right = new char[size - pos];
    memcpy(temp_left, text, pos);
    memcpy(temp_right, text + pos, size-pos);
    text = new char[size + word_size + 1];
    memcpy(text, temp_left, pos);
    delete[] temp_left;
    memcpy(text+pos, word, word_size);
    memcpy(text+pos+word_size, temp_right, size-pos);
    delete[] temp_right;
    text[size + word_size] = '\0';
    size+=word_size;
}
