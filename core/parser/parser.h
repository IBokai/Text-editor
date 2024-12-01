#ifndef PARSER_HPP
#define PARSER_HPP
#include <map>
#include <string>
#include <vector>

#include "parsercommandinfo.h"

class Parser {
public:
    Parser(std::map<std::string, ParserCommandInfo>& parsingScheme);
    EditorMethod parse(const std::string& input, std::vector<const char*>& arguments);

private:
    std::vector<std::string> split(const std::string& input);
    bool validateParameters(std::vector<const char*> parameters, ParserCommandInfo command);
    std::map<std::string, ParserCommandInfo> parsingScheme;
};
#endif
