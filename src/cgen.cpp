#include <iostream>
#include <string>

#include "include/cgen.hpp"
#include "include/util.hpp"

// Generate a C source file
void CGen::generateCSrc(Node tree, std::string outFilePath) {
    std::string src;

    // Generate C boilerplate code
    src += "#include <stdio.h>\n";
    src += "#include <stdlib.h>\n\n";

    src += "int main(int argc, char *argv[]) {\n";

    // Loop through each node in the tree
    for (auto &node : tree.nodes) {
        if (node.name.substr(0, 3) == "fn:") {
            std::string fnCallName = node.name.substr(3);

            // We are printing something to the console; use alternative libc function
            if (fnCallName == "print") {
                src += "\tprintf(\"%s\", ";
                std::string str;
                bool first = true;

                // Go through each string provided and concatenate them
                for (auto &param : node.nodes) {
                    if (!first) {
                        str += param.name + " ";
                    }

                    first = false;
                }

                // End the function call
                str.pop_back();
                src += "\"" + str + "\\n\");\n";
            }
        }
    }

    src += "\treturn 0;\n}\n";

    Utilities::writeFile(outFilePath, src);
}
