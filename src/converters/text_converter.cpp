#include "../../include/converters/text_converter.h"
#include "../../include/core/file_handler.h"
#include <sstream>
#include <algorithm>

ConversionResult TextConverter::convert(const ConversionTask& task) {
    ConversionResult result;
    
    if (!canHandle(task.inputFormat, task.outputFormat)) {
        result.success = false;
        result.message = "Unsupported conversion: " + task.inputFormat + " -> " + task.outputFormat;
        return result;
    }
    
    if (!FileHandler::exists(task.inputPath)) {
        result.success = false;
        result.message = "Input file does not exist: " + task.inputPath;
        return result;
    }
    
    // Читаем файл
    std::vector<std::string> lines;
    if (!FileHandler::readLines(task.inputPath, lines)) {
        result.success = false;
        result.message = "Cannot read input file";
        return result;
    }
    
    // Конвертируем в CSV
    std::stringstream csv;
    for (const auto& line : lines) {
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string word;
        bool first = true;
        
        while (ss >> word) {
            if (!first) csv << ",";
            csv << word;
            first = false;
        }
        csv << "\n";
    }
    
    // Записываем результат
    if (!FileHandler::writeString(task.outputPath, csv.str())) {
        result.success = false;
        result.message = "Cannot write output file";
        return result;
    }
    
    result.success = true;
    result.message = "Success";
    return result;
}

bool TextConverter::canHandle(const std::string& inputFormat, const std::string& outputFormat) const {

    return inputFormat == "txt" && outputFormat == "csv";
}

std::string TextConverter::getName() const {
    return "txt to cvc converter";
}
