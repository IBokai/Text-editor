#include "text.hpp"

void Text::replace(const char& x, const char& y, std::set<int>& highlighted){
    for(int i = 0; i < size; i++){
        if(text[i] == x){
            highlighted.insert(i);
            text[i] = y;
        }
    }
}