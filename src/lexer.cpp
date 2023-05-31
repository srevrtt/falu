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

// Tokenizes an integer and returns it as an std::string
static std::string tokenizeInteger() {
    std::string integer;

    while (isdigit(src[idx])) {
        integer += src[idx];
        idx++;
    }

    return integer;
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

        // If there aren't any, try to find any numbers and tokenize them
        if (letters.length() == 0) {
            std::string integer = tokenizeInteger();

            if (integer.length() > 0) {
                tokens.push_back(Token { "$T_NUMBER", integer });
            }
        }

        // Character tokenization
        if (src[idx] == '(') {
            tokens.push_back(Token { "$T_LPAREN", "(" });
        }

        if (src[idx] == ')') {
            tokens.push_back(Token { "$T_RPAREN", ")" });
        }

        if (src[idx] == '=') {
            tokens.push_back(Token { "$T_EQUALS", "=" });
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
