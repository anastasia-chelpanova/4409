#include "App.hpp"
#include "Menu.hpp"
#include "Matrix.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>

// Простые проверки прямо здесь
bool checkNotEmpty(const std::string& str) {
    return !str.empty();
}

bool checkIsNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

bool checkInRange(int val, int min, int max) {
    return val >= min && val <= max;
}

void runProgram() {
    int choice;
    std::string input;

    std::cout << "Program: Square Matrix (Option 4)\n";

    while (true) {
        showMenu();
        std::getline(std::cin, input);

        if (!checkNotEmpty(input) || !checkIsNumber(input)) {
            std::cout << "Input error! Enter 1, 2, or 3.\n";
            continue;
        }

        choice = std::stoi(input);

        if (!checkInRange(choice, 1, 3)) {
            std::cout << "Error! Select option 1, 2, or 3.\n";
            continue;
        }

        if (choice == 1) {
            int n = getMatrixSize();
            int** matrix = createMatrix(n);
            fillMatrix(matrix, n);
            printMatrix(matrix, n);
            deleteMatrix(matrix, n);

            std::cout << "Press Enter to continue...";
            std::getline(std::cin, input);

        }
        else if (choice == 2) {
            showChecks();

        }
        else if (choice == 3) {
            std::cout << "The program is over. Goodbye!\n";
            break;
        }
    }
}