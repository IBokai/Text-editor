#ifndef PARSERPARAMETER_HPP
#define PARSERPARAMETER_HPP
#include <iostream>
#include <regex>

class ParserParameter {
public:
    ParserParameter(std::regex validator);
    bool validate(std::string input_parameter);

private:
    std::regex validator;
};
#endif
