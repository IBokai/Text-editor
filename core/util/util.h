#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <vector>
namespace util {
size_t word_size(const char* word);

std::string process_input();

void clear_argv(std::vector<const char*>& argv);
}  // namespace util
#endif
