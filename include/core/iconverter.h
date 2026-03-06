#pragma once
#include "types.h"
#include <functional>
#include <string>

class IConverter {
public:
    virtual ~IConverter() = default;

    virtual ConversionResult convert(const ConversionTask& task) = 0;
    virtual bool canHandle(const std::string& inputFormat, const std::string& outputFormat) const = 0;
    
    virtual std::string getName() const = 0;
};
