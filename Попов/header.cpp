#include "header.h"
#include <cmath>
#include <string>
#include <limits>
#include <iomanip>

float safeInput(const std::string& prompt) {
    float number;

    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            showError("ERROR! Please enter a number:");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return number;
        }
    }
}


bool inputData(float& x, float& y) {
    std::cout << "=== DATA INPUT ===" << std::endl;

    try {
        x = safeInput("Enter x: ");
        y = safeInput("Enter y: ");
        return true;
    }
    catch (...) {
        showError("Error during data input!");
        return false;
    }
}

float solveEquation(float x, float y) {
    float a = std::sqrt(std::fabs(x) + std::fabs(y));
    float b = 1 + std::fabs(x) + std::fabs(y);

    if (b == 0) {
        showError("Error: Division by zero!");
        return 0;
    }

    return a / b;
}

void outputResult(float result) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\n=== CALCULATION RESULT ===" << std::endl;
    std::cout << "z = " << result << std::endl;
    std::cout << "===========================" << std::endl;
}

void showError(const std::string& message) {
    std::cout << "\n[ERROR] " << message << std::endl;
}

void showMenu() {
    std::cout << "\n===============================" << std::endl;
    std::cout << "        PROGRAM MENU" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "1. Calculate the equation" << std::endl;
    std::cout << "2. Run program tests (5 tests)" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Select menu option (1-3): ";
}

void runTests() {
    std::cout << "\n=== PROGRAM TESTING ===" << std::endl;
    std::cout << "Equation: z = sqrt(|x| + |y|) / (1 + |x| + |y|)" << std::endl;
    std::cout << "===============================" << std::endl;

    float tests[5][3] = {
        {4.0f, 9.0f, 0.257495f},
        {0.0f, 0.0f, 0.0f},
        {-4.0f, 9.0f, 0.257495f},
        {16.0f, 25.0f, 0.200000f},
        {1.0f, 1.0f, 0.414213f}
    };

    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < 5; i++) {
        float x = tests[i][0];
        float y = tests[i][1];
        float expected = tests[i][2];
        float calculated = solveEquation(x, y);

        std::cout << "\nTest " << (i + 1) << ":" << std::endl;
        std::cout << "x = " << x << ", y = " << y << std::endl;
        std::cout << "Expected result: " << expected << std::endl;
        std::cout << "Calculated result: " << calculated << std::endl;

        float difference = std::fabs(calculated - expected);
        if (difference < 0.0001f) {
            std::cout << " TEST PASSED" << std::endl;
        } else {
            std::cout << " TEST FAILED (difference: " << difference << ")" << std::endl;
        }
    }

    std::cout << "\n===============================" << std::endl;
    std::cout << "Testing completed!" << std::endl;
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void mainCalculation() {
    float x, y;

    if (inputData(x, y)) {
        float result = solveEquation(x, y);
        outputResult(result);

        std::cout << "\n=== MANUAL CALCULATION VERIFICATION ===" << std::endl;
        std::cout << "Your values:" << std::endl;
        std::cout << "|x| = " << std::fabs(x) << std::endl;
        std::cout << "|y| = " << std::fabs(y) << std::endl;
        std::cout << "|x| + |y| = " << std::fabs(x) + std::fabs(y) << std::endl;
        std::cout << "sqrt(|x| + |y|) = " << std::sqrt(std::fabs(x) + std::fabs(y)) << std::endl;
        std::cout << "1 + |x| + |y| = " << 1 + std::fabs(x) + std::fabs(y) << std::endl;
        std::cout << "Result (manual): " << std::sqrt(std::fabs(x) + std::fabs(y)) /
            (1 + std::fabs(x) + std::fabs(y)) << std::endl;
    }

    std::cout << "\nPress Enter to return to menu...";
    std::cin.get();
}

