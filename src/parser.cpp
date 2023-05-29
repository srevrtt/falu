#include <iostream>
#include <string>

#include "include/parser.hpp"

int parserIdx;
std::vector<Token> tkns;

static Node genNode() {
    Node node;

    if (tkns[parserIdx].name == "$T_LETTERS") {
        parserIdx++;

        // Function call
        if (tkns[parserIdx].name == "$T_LPAREN") {
            node.name = "fn:" + tkns[parserIdx - 1].value;

            Node lparen;
            lparen.name = "(";
            node.nodes.push_back(lparen);

            parserIdx++;

            while (parserIdx < tkns.size() - 1 && tkns[parserIdx].name != "$T_RPAREN") {
                Node param;
                param.name = tkns[parserIdx].value;
                node.nodes.push_back(param);

                parserIdx++;
            }

            if (parserIdx < tkns.size() - 1) {
                Node rparen;
                rparen.name = ")";
                node.nodes.push_back(rparen);
            }
        }
    }

    return node;
}

Node Parser::parse(std::vector<Token> tokens) {
    tkns = tokens;
    parserIdx = 0;

    Node tree;
    tree.name = "prog";
    tree.nodes.push_back(genNode());

    return tree;
}
