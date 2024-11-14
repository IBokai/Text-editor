#include <iostream>
#include <string>

#include "editor/editor.hpp"

int main() {
    std::string text = "Lorem Ipsum";
    char* ctext = new char[text.size()];
    for (size_t i = 0; i < text.size(); i++) {
        ctext[i] = text[i];
    }
    Editor e(ctext);
    e.run();
}
