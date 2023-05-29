#include <iostream>
#include <string>
#include <fstream>

#include "include/util.hpp"

std::string Utilities::readLuaSrc(std::string filepath) {
    std::ifstream file(filepath);
    std::string src, line;

    if (!file.is_open()) {
        std::cout << "Error: Failed to read Lua source file \"" << filepath << "\"! Does it exist?" << std::endl;
        exit(1);
    }

    while (std::getline(file, line)) {
        src += line + '\n';
    }

    file.close();
    return src;
}

void Utilities::writeFile(std::string filepath, std::string content) {
    std::ofstream file(filepath);

    if (!file) {
        std::cout << "Error: Failed to write C source file \"" << filepath << "\"!" << std::endl;
        exit(1);
    }

    file << content;
    file.close();
}
