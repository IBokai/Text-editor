#include "util.hpp"

void memcpy(char* dest, char* src, size_t n){
    for(size_t i = 0; i < n; i++){
        dest[i] = src[i];
    }
}
