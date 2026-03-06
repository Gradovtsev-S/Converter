#include "../../include/core/file_handler.h"
#include <fstream>
#include <sstream>

bool FileHandler::readLines(const std::string& path, std::vector<std::string>& lines) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }
    
    std::string line;
    lines.clear();
    
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    
    file.close();
    return true;
}

bool FileHandler::writeString(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }
    
    file << content;
    file.close();
    return true;
}

bool FileHandler::exists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}
