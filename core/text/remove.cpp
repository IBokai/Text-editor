#include "../util/util.h"
#include "text.h"

void Text::remove(size_t start_pos, size_t end_pos) {
    char* temp_left = new char[start_pos];
    char* temp_right = new char[size - end_pos - 1];
    std::memcpy(temp_left, text, start_pos);
    std::memcpy(temp_right, text + end_pos + 1, size);
    delete[] text;
    text = new char[size - (end_pos - start_pos + 1) + 1];
    std::memcpy(text, temp_left, start_pos);
    delete[] temp_left;
    std::memcpy(text + start_pos, temp_right, size - end_pos - 1);
    delete[] temp_right;
    text[size - (end_pos - start_pos + 1)] = '\0';
    size = size - end_pos + start_pos - 1;
}
