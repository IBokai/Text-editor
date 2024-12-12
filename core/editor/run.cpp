#include "../parser/parser.h"
#include "editor.h"
// TODO: make correct run(use load and save of file)

void Editor::run() {
    std::vector<const char*> arguments;
    std::string input;
    EditorMethod m;
    print();
    while (!loaded) {
        input = util::process_input();
        if (input == "exit") {
            return;
        }
        m = parser.parse(input, arguments);
        if (m != &Editor::load) {
            util::clear_argv(arguments);
            std::cout << "Need to load file first" << '\n';
        } else {
            (this->*m)(arguments);
            loaded = true;
            util::clear_argv(arguments);
            print();
        }
    }
    input = util::process_input();
    while (input != "exit") {
        m = parser.parse(input, arguments);
        if (m != nullptr) {
            (this->*m)(arguments);
            util::clear_argv(arguments);
            print();
            std::cout << "Cursor position: " << cursor_pos << '\n';
            highlighted.clear();
        } else {
            std::cout << "Wrong Input" << '\n';
            util::clear_argv(arguments);
        }
        std::cout << "Text size: " << text.get_size() << '\n';
        input = util::process_input();
    }
}
