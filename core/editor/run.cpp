#include "../parser/parser.h"
#include "editor.h"

void Editor::run() {
    std::vector<const char*> arguments;
    std::string input;
    print();
    std::cout << "Enter the command: ";
    std::getline(std::cin, input);
    while (input != "exit") {
        EditorMethod m = parser.parse(input, arguments);
        if (m != nullptr) {
            (this->*m)(arguments);
            for (int i = 0; i < arguments.size(); i++) {
                delete[] arguments[i];
            }
            arguments.clear();
            print();
            std::cout << "Cursor position: " << cursor_pos << '\n';
            highlighted.clear();
        } else {
            std::cout << "Wrong Input" << '\n';
            for (int i = 0; i < arguments.size(); i++) {
                delete[] arguments[i];
            }
            arguments.clear();
        }
        std::cout << "Text size: " <<text.get_size() << '\n';
        std::cout << "Enter the command: ";
        std::getline(std::cin, input);
    }
}
