#pragma once

#include <string>

namespace Utilities {
    std::string readLuaSrc(std::string filepath);
    void writeFile(std::string filepath, std::string content);
}
