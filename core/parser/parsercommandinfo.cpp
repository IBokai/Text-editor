#include "parsercommandinfo.h"
// They can be inlined better when left in header. Keep small methods there. solved
ParserCommandInfo::ParserCommandInfo(std::vector<ParserParameter> parameters, EditorMethod method)
    : parameters(parameters), argc(parameters.size()), method(method) {}
