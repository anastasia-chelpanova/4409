#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>


void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getMatrixSize() {
    std::string input;
    int n = 0;

    while (true) {
        std::cout << "Enter an odd number n (2 < n < 24): ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Error: You have not entered anything!\n";
            continue;
        }

        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            std::cout << "Error: Please enter only numbers!\n";
            continue;
        }

        n = std::stoi(input);

        if (n <= 0) {
            std::cout << "Error: Number must be positive!\n";
            continue;
        }

        if (n <= 2) {
            std::cout << "Error: Number must be greater than 2!\n";
            continue;
        }

        if (n >= 24) {
            std::cout << "Error: Number must be less than 24!\n";
            continue;
        }

        if (n % 2 == 0) {
            std::cout << "Error: Number must be odd!\n";
            continue;
        }

        return n;
    }
}