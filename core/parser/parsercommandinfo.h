#ifndef PARSERCOMMANDINFO_H
#define PARSERCOMMANDINFO_H
#include <functional>
#include <iostream>
#include <vector>

#include "parserparameter.h"

class Editor;
// use using. solved
using EditorMethod = void (Editor::*)(std::vector<char const*>&);

class ParserCommandInfo {
public:
    ParserCommandInfo(std::vector<ParserParameter> parameters, EditorMethod);
    int get_argc() const { return argc; }
    ParserParameter& operator[](int index) { return parameters[index]; };
    EditorMethod get_Executable() { return method; };

private:
    int argc;
    std::vector<ParserParameter> parameters;
    EditorMethod method;
};
#endif
