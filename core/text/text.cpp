#include "text.h"

Text::Text(const char* text) {
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

Text::Text() {
    text = nullptr;
    size = 0;
}

Text::~Text() { delete[] text; }

Text& Text::operator=(const Text& other) {
    if (this == &other) {
        return *this;
    }
    // First we need to do operations that doesnt change object fields and can produce exceptions,
    // like copying then we can change object state. Some questions
    delete[] text;
    text = new char[other.get_size() + 1];
    for (size_t i = 0; i < other.get_size(); i++) {
        text[i] = other[i];
    }
    text[other.get_size()] = '\0';
    size = other.get_size();
    return *this;
}

void Text::save(const char* path) {
    std::ofstream file;
    file.open(path);
    file << text;
    file.close();
    delete[] text;
    text = nullptr;
    size = 0;
}