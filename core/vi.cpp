#include <iostream>
#include <string>

#include "editor/editor.h"

int main() {
    // std::string text = "Lorem Ipsum";
    Editor e = Editor();
    std::vector<char const*> v = {"/home/ivan/vi-git/core/editor/text.txt"};
    e.load(v);
    e.run();
}
