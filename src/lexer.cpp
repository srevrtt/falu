#include <iostream>
#include <string>

#include "include/lexer.hpp"

std::string src;
int idx;

static void skipWhitespace() {
    while (isspace(src[idx])) {
        idx++;
    }
}

static std::string tokenizeLetters() {
    std::string letters;

    while (isalpha(src[idx]) || src[idx] == '_') {
        letters += src[idx];
        idx++;
    }

    return letters;
}

static std::string tokenizeString() {
    std::string str;
    idx++;

    while (src[idx] != '"') {
        str += src[idx];
        idx++;
    }

    return str;
}

std::vector<Token> Lexer::tokenize(std::string luaSrc) {
    std::vector<Token> tokens;

    src = luaSrc;
    idx = 0;

    skipWhitespace();

    while (idx < src.length() - 1) {
        std::string letters = tokenizeLetters();        

        if (letters.length() > 0) {
            tokens.push_back(Token { "$T_LETTERS", letters });
        }

        if (src[idx] == '(') {
            tokens.push_back(Token { "$T_LPAREN", "(" });
        }

        if (src[idx] == ')') {
            tokens.push_back(Token { "$T_RPAREN", ")" });
        }

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
