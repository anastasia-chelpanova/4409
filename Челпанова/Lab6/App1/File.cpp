#include "File.hpp"
#include "Bracket_checker.hpp"
#include <iostream>
#include <fstream>
#include <string>


void processFileTask() {

    if (!std::ifstream("input.txt")) {
        std::cout << "Файл input.txt не найден. Создаю пример..." << std::endl;
        std::ofstream createFile("input.txt");
        createFile << "(Test String)";
        createFile.close();
    }

    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cout << "Ошибка: Не удалось открыть файл input.txt" << std::endl;
        std::cout << "Создайте файл input.txt в папке с программой." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);
    inputFile.close();

    if (line.length() > 255) {
        std::cout << "Предупреждение: Строка длиннее 255 символов." << std::endl;
    }

    int errorPos = 0;
    char errorType = ' ';

    bool isCorrect = checkBrackets(line, errorPos, errorType);

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cout << "Ошибка: Не удалось создать файл output.txt" << std::endl;
        return;
    }

    if (isCorrect) {
        std::cout << "Скобки расставлены правильно." << std::endl;
        outputFile << "OK: Скобки расставлены правильно." << std::endl;
    }
    else {
        std::cout << "Найдена ошибка!" << std::endl;
        std::cout << "Тип скобки: " << errorType << ", Позиция: " << errorPos << std::endl;

        outputFile << "ERROR: Неправильно расставлены скобки." << std::endl;
        outputFile << "Тип ошибочной скобки: " << errorType << std::endl;
        outputFile << "Позиция (номер символа): " << errorPos << std::endl;
    }

    outputFile.close();
    std::cout << "Результат записан в output.txt" << std::endl;
}

