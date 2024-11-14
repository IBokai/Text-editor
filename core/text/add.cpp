#include "../util/util.hpp"
#include "text.hpp"

void Text::add(const char* word, size_t word_size) {
    char* temp = new char[size];
    util::memcpy(temp, text, size);
    delete[] text;
    text = new char[size + word_size + 1];
    util::memcpy(text, temp, size);
    delete[] temp;
    util::memcpy(text + size, word, word_size);
    text[size + word_size] = '\0';
    size += word_size;
}
