#pragma once

#include <string>
#include <vector>

struct Token {
    std::string name;
    std::string value;
};

namespace Lexer {
    std::vector<Token> tokenize(std::string luaSrc);
}
