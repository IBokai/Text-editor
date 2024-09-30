#include "../util/util.hpp"
#include "text.hpp"
// "Some Text" size = 9, pos = 2
void Text::del(size_t pos){
    char* temp_left = new char[pos - 1];
    char* temp_right = new char[size-pos];
    memcpy(temp_left, text, pos-1);
    memcpy(temp_right, text + pos, size-pos);
    delete[] text;
    char* text = new char[size-1];
    memcpy(text, temp_left, pos-1);
    delete[] temp_left;
    memcpy(text + pos, temp_right, size-pos);
}
