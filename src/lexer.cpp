#include <iostream>
#include <string>

#include "include/lexer.hpp"

std::string src;
int idx;

// Skips whitespace
static void skipWhitespace() {
    while (isspace(src[idx])) {
        idx++;
    }
}

// Tokenizes a group of letters (includes underscores)
static std::string tokenizeLetters() {
    std::string letters;

    while (isalpha(src[idx]) || src[idx] == '_') {
        letters += src[idx];
        idx++;
    }

    return letters;
}

// Tokenizes a string - all it does is reads characters until there is another '"'
static std::string tokenizeString() {
    std::string str;
    idx++;

    while (src[idx] != '"') {
        str += src[idx];
        idx++;
    }

    return str;
}

// Tokenizes a Lua source code file
std::vector<Token> Lexer::tokenize(std::string luaSrc) {
    std::vector<Token> tokens;

    src = luaSrc;
    idx = 0;

    skipWhitespace();

    while (idx < src.length() - 1) {
        // Tokenize any letters first
        std::string letters = tokenizeLetters();

        if (letters.length() > 0) {
            tokens.push_back(Token { "$T_LETTERS", letters });
        }

        // Character tokenization
        if (src[idx] == '(') {
            tokens.push_back(Token { "$T_LPAREN", "(" });
        }

        if (src[idx] == ')') {
            tokens.push_back(Token { "$T_RPAREN", ")" });
        }

        // String tokenization
        if (src[idx] == '"') {
            std::string str = tokenizeString();

            if (str.length() > 0) {
                tokens.push_back(Token { "$T_STRING", str });
            }
        }

        idx++;
    }

    return tokens;
}
