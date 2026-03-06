#pragma once
#include <functional>
#include <string> 


// ============ Basic types ============

enum class FormatCategory {
    Text,
    Image,
    Audio,
};


// ============ Data structures ============

struct ConversionTask {
    std::string inputPath;
    std::string outputPath;
    std::string inputFormat;
    std::string outputFormat;
    // в будущем можно добавить отслеживание места в очереди
};

struct ConversionResult {
    bool success;
    std::string message;
    // в будущем можно добавить размеры исходных и итоговых файлов, время выполнения
};
