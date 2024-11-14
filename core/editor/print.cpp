#include "editor.h"

void Editor::print() {
    system("clear");
    size_t text_pos = 0;
    for (int i = 0; i < 82; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
    for (int i = 0; i < 25; i++) {
        std::cout << '|';
        for (int i = 0; i < 80; i++) {
            if (text_pos < text.get_size()) {
                if (highlighted.count(text_pos)) {
                    std::cout << "\033[0;31m" << text[text_pos] << "\033[0m";
                }
                if (text_pos == cursor_pos) {
                    std::cout << "\033[36m" << text[text_pos] << "\033[0m";
                } else {
                    std::cout << text[text_pos];
                }

                text_pos++;
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '|' << '\n';
    }
    for (int i = 0; i < 82; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
}
