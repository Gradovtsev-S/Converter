# Text to CSV Converter

Конвертер файлов на C++.

## Описание

Программа преобразует файлы разных форматов.

## Архитектура

```
Converter/
├── include/
│   ├── core/
│   │   ├── types.h              # структуры ConversionTask и ConversionResult
│   │   ├── iconverter.h         # интерфейс IConverter
│   │   └── file_handler.h       # класс для работы с файлами
│   └── converters/
│       └── text_converter.h     # текстовый конвертер
├── src/
│   ├── core/
│   │   └── file_handler.cpp
│   └── converters/
│       └── text_converter.cpp
├── main.cpp
├── CMakeLists.txt
└── README.md
```

## Сборка

```bash
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
```

## Использование
```bash
cd build
./converter input_file_directory.txt output_file_directory.csv
```
