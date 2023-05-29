#include <iostream>
#include <string>

#include "include/util.hpp"
#include "include/lexer.hpp"

int main(int argc, char *argv[]) {
    std::string luaSrc = Utilities::readLuaSrc("tests/hello_world.lua");
    std::vector<Token> tokens = Lexer::tokenize(luaSrc);

    return 0;
}
