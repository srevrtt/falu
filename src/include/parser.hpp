#pragma once

#include <vector>
#include <string>
#include "lexer.hpp"

struct Node {
    std::vector<Node> nodes;
    std::string name;
};

namespace Parser {
    Node parse(std::vector<Token> tokens);
}
