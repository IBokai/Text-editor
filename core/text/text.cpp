#include "text.h"

Text::Text(char* text) {
    size = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        size++;
    }
    this->text = new char[size + 1];
    for (size_t i = 0; i < size; i++) {
        this->text[i] = text[i];
    }
    this->text[size] = '\0';
}

Text::~Text() { delete[] text; }

size_t Text::get_size() const { return size; }

char Text::operator[](size_t index) const { return text[index]; };