#pragma once
#include "../core/iconverter.h"
#include <string>
#include <vector>

class TextConverter : public IConverter {
public:
    TextConverter() = default;
    ~TextConverter() override = default;
    
    ConversionResult convert(const ConversionTask& task) override;
    bool canHandle(const std::string& inputFormat, const std::string& outputFormat) const override;

    std::string getName() const override;
    
private:
    std::string convertToCsv(const std::vector<std::string>& lines);
    
};
