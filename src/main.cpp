#include <iostream>
#include <string>

#include "include/util.hpp"
#include "include/lexer.hpp"
#include "include/parser.hpp"
#include "include/cgen.hpp"

int main(int argc, char *argv[]) {
    std::string luaSrc = Utilities::readLuaSrc("tests/hello_world.lua");
    std::vector<Token> tokens = Lexer::tokenize(luaSrc);
    Node parseTree = Parser::parse(tokens);

    CGen::generateCSrc(parseTree, "compiled.c");

    system("clang -c compiled.c -o compiled.o");
    system("clang compiled.o -o falu_compiled");
    system("rm compiled.c compiled.o");

    return 0;
}
