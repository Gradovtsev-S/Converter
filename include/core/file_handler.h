#pragma once
#include <string>
#include <vector>

class FileHandler {
public:
    // Чтение файла построчно
    static bool readLines(const std::string& path, std::vector<std::string>& lines);
    
    // Запись строк в файл
    static bool writeString(const std::string& path, const std::string& content);
    
    // Проверка существования файла
    static bool exists(const std::string& path);
    
};