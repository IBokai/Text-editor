#include "util.hpp"
namespace util{
    void memcpy(char* dest, const char* src, size_t n){
    for(size_t i = 0; i < n; i++){
        dest[i] = src[i];
    }
}
}

