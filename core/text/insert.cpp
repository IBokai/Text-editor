#include "../util/util.hpp"
#include "text.hpp"

void Text::insert(const char* word, size_t pos, size_t word_size) {
    char* temp_left = new char[pos];
    char* temp_right = new char[size - pos];
    util::memcpy(temp_left, text, pos);
    util::memcpy(temp_right, text + pos, size - pos);
    text = new char[size + word_size + 1];
    util::memcpy(text, temp_left, pos);
    delete[] temp_left;
    util::memcpy(text + pos, word, word_size);
    util::memcpy(text + pos + word_size, temp_right, size - pos);
    delete[] temp_right;
    text[size + word_size] = '\0';
    size += word_size;
}
