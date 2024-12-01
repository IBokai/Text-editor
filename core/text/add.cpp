#include "../util/util.h"
#include "text.h"

void Text::add(const char* word, size_t word_size) {
    char* temp = new char[size];
    std::memcpy(temp, text, size);
    delete[] text;
    text = new char[size + word_size + 1];
    std::memcpy(text, temp, size);
    delete[] temp;
    std::memcpy(text + size, word, word_size);
    text[size + word_size] = '\0';
    size += word_size;
}
