#include <iostream>
#include <string>
#include <fstream>

#include "include/util.hpp"

// Reads a .lua source file
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

// Writes a C source file to the disk
void Utilities::writeFile(std::string filepath, std::string content) {
    std::ofstream file(filepath);

    if (!file) {
        std::cout << "Error: Failed to write C source file \"" << filepath << "\"!" << std::endl;
        exit(1);
    }

    file << content;
    file.close();
}
