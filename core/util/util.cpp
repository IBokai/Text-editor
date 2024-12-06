#include "util.h"
namespace util {
size_t word_size(const char* word) {
    size_t word_size = 0;
    for (word_size; word[word_size] != '\0'; word_size++);
    return word_size;
}
}  // namespace util
