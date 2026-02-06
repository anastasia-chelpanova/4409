#include <iostream>
#include <cmath>
#include <limits>
#include "header.hpp"

void enter_data(float &x, float &y) {
    std::cout << "vvedite x: ";
    while(!(std::cin >> x)) {
        std::cout << "Error! Enter number: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "vvedite x: ";
    }

    std::cout << "vvedite y: ";
    while(!(std::cin >> y)) {
        std::cout << "Error! Enter number: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "vvedite y: ";
    }
}

float reshenie(float x, float y) {
    return (std::sqrt(1 + std::fabs(x * y))) / (1 + std::sqrt(std::fabs(x) + std::fabs(y)));
}

void vivod(float z) {
    std::cout << "result z = " << z << std::endl;
}
