#include "parserparameter.h"

#include <iostream>
#include <regex>

ParserParameter::ParserParameter(std::regex validator) : validator(validator) {}

bool ParserParameter::validate(std::string input_parameter) {
    return std::regex_match(input_parameter, validator);
}
