#include "parser.h"

#include <cstring>
#include <map>
#include <regex>
#include <string>
#include <vector>

#include "parsercommandinfo.h"
#include "parserparameter.h"
// TODO: rewrite split logic?
Parser::Parser(std::map<std::string, ParserCommandInfo>& parsingScheme)
    : parsingScheme(std::move(parsingScheme)) {}
// Look into string library functions for split. Can't solve: no split function implementation, to
// implement split with std functions, need to use a lot of standard functions(substr, std::find,
// etc.)
std::vector<std::string> Parser::split(const std::string& input) {
    size_t pos = 0;
    std::string current;
    std::vector<std::string> splited;
    while (input[pos] != ')') {
        if (input[pos] == ' ' || input[pos] == '(' || input[pos] == ')') {
            if (!current.empty()) {
                splited.push_back(current);
            }
            current = "";
            pos++;
            continue;
        }
        current += input[pos];
        pos++;
    }
    if (!current.empty()) {
        splited.push_back(current);
    }
    return splited;
}

bool Parser::validateParameters(std::vector<const char*> input_parameters,
                                ParserCommandInfo command) {
    if (input_parameters.size() != command.get_argc()) {
        return false;
    }
    for (int i = 0; i < input_parameters.size(); i++) {
        if (!command[i].validate(input_parameters[i])) {
            return false;
        }
    }
    return true;
}

EditorMethod Parser::parse(const std::string& input, std::vector<const char*>& arguments) {
    std::vector<std::string> splited = split(input);
    if (splited.empty()) {
        return nullptr;
    }
    std::string command_name = splited[0];
    for (int i = 1; i < splited.size(); i++) {
        // still, use smart pointers or standart containers
        char* argument = new char[splited[i].size() + 1];
        // memcpy. solved
        std::memcpy(argument, splited[i].c_str(), splited[i].size());
        argument[splited[i].size()] = '\0';
        arguments.push_back(argument);
    }
    if (!parsingScheme.count(command_name)) {
        return nullptr;
    }
    if (!validateParameters(arguments, parsingScheme.at(command_name))) {
        return nullptr;
    }
    return parsingScheme.at(command_name).get_Executable();
}