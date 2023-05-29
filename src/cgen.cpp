#include <iostream>
#include <string>

#include "include/cgen.hpp"
#include "include/util.hpp"

void CGen::generateCSrc(Node tree, std::string outFilePath) {
    std::string src;

    src += "#include <stdio.h>\n";
    src += "#include <stdlib.h>\n\n";

    src += "int main(int argc, char *argv[]) {\n";

    for (auto &node : tree.nodes) {
        if (node.name.substr(0, 3) == "fn:") {
            std::string fnCallName = node.name.substr(3);

            if (fnCallName == "print") {
                src += "\tprintf(\"%s\", ";
                std::string str;
                bool first = true;

                for (auto &param : node.nodes) {
                    if (!first) {
                        str += param.name + " ";
                        str.pop_back();
                        src += "\"" + str + "\\n\");\n";
                    }

                    first = false;
                }
            }
        }
    }

    src += "\treturn 0;\n}\n";

    Utilities::writeFile(outFilePath, src);
}
