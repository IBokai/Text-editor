#include "util.h"
namespace util {
size_t word_size(const char* word) {
    size_t word_size = 0;
    for (word_size; word[word_size] != '\0'; word_size++);
    return word_size;
}

std::string process_input() {
    std::cout << "Enter the command: ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void clear_argv(std::vector<const char*>& argv) {
    for (auto& arg : argv) {
        delete[] arg;
    }
    argv.clear();
}

}  // namespace util
