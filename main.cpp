#include "include/converters/text_converter.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " input.txt output.csv" << std::endl;
        return 1;
    }
    
    TextConverter converter;
    
    ConversionTask task;
    task.inputPath = argv[1];
    task.outputPath = argv[2];
    task.inputFormat = "txt";
    task.outputFormat = "csv";
    
    auto result = converter.convert(task);
    
    if (result.success) {
        std::cout << "Success!" << std::endl;
    } else {
        std::cout << "Error: " << result.message << std::endl;
        return 1;
    }
    
    return 0;
}
