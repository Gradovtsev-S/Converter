cmake_minimum_required(VERSION 3.10)
project(Converter)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/core/file_handler.cpp
    src/converters/text_converter.cpp
    main.cpp
)

add_executable(converter ${SOURCES})
target_include_directories(converter PRIVATE include)
