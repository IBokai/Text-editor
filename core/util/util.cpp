#include "util.h"
namespace util {
size_t word_size(const char* word){
    size_t word_size = 0;
    for(size_t i = 0; word[i] != '\0'; i++){
        word_size++;
    }
    return word_size;
}
}  // namespace util
