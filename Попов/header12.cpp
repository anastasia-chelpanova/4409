#include "header12.h"
#include <cmath>
#include <string>
#include <limits>
#include <iomanip>

float safeInput(const std::string& prompt) {
    float number;
// цикл запрашивает значения пока не получит число
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) { //cin.fail() - проверяет, произошла ли ошибка ввода
            showError("ERROR! Please enter a number:");
            std::cin.clear(); // сброс этой ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // удаляет все символы из буфера ввода
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Если ввод успешен, очищает буфер и возвращает число
            return number;
        }
    }
}

bool inputData(float& x, float& y) {
    std::cout << "=== DATA INPUT ===" << std::endl;

    try { // код, который может вызвать исключение
        x = safeInput("Enter x: ");
        y = safeInput("Enter y: ");
        return true;
    }
    catch (...) {  //поймать исключение, если оно возникло/ троеточие означает "любое исключение"
        showError("Error during data input!");
        return false;
    }
}

float solveEquation(float x, float y) {
    float z = 0.0f;

    if (x <= 0) {
        // Первая ветка: x ≤ 0
        z = std::cbrt(std::pow(x, 3) + std::pow(y, 2));
    }
    else if (x > 0 && std::abs(y) >= x) {
        // Вторая ветка: x > 0, |y| ≥ x
        if (y == 0) {
            showError("Division by zero! y cannot be 0 for arccos(x/y)");
            return 0.0f;
        }
        float arg = x / y;
        if (arg < -1.0f || arg > 1.0f) {
            showError("arccos argument out of range! |x/y| must be ≤ 1");
            return 0.0f;
        }
        z = std::acos(arg);
    }
    else if (x > 0 && std::abs(y) < x) {
        // Третья ветка: x > 0, |y| < x
        float base = 5 * x + 1;
        float argument = 5 * x - std::abs(3 * y);

        if (base <= 0 || base == 1) {
            showError("Invalid base for logarithm! Base must be > 0 and ≠ 1");
            return 0.0f;
        }
        if (argument <= 0) {
            showError("Invalid argument for logarithm! Argument must be > 0");
            return 0.0f;
        }

        z = std::log(argument) / std::log(base);
    }
    else {
        showError("No matching condition for the given x and y");
        return 0.0f;
    }

    return z;
}

void outputResult(float result) {
    std::cout << "\n=== RESULT ===" << std::endl;
    std::cout << "z = " << std::fixed << std::setprecision(6) << result << std::endl;
}

void showError(const std::string& message) {
    std::cout << "\n[ERROR] " << message << std::endl;
}

void showMenu() {
    std::cout << "\n===============================" << std::endl;
    std::cout << "        PROGRAM MENU" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "1. Calculate the equation" << std::endl;
    std::cout << "2. Run tests" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Select menu option (1-3): ";
}

void runTests() {
    std::cout << "\n=== RUNNING TESTS ===\n" << std::endl;

    int passed = 0;
    int total = 10;

    // Тест 1: x ≤ 0
    float x1 = -2, y1 = 3;
    float result1 = solveEquation(x1, y1);
    float expected1 = 1.0f;
    std::cout << "Test 1: x = -2, y = 3" << std::endl;
    std::cout << "Expected: " << expected1 << ", Got: " << result1 << std::endl;
    if (std::abs(result1 - expected1) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 2: x > 0, |y| ≥ x (arccos)
    float x2 = 4, y2 = 5;
    float result2 = solveEquation(x2, y2);
    float expected2 = 0.6435f;
    std::cout << "Test 2: x = 4, y = 5" << std::endl;
    std::cout << "Expected: " << expected2 << ", Got: " << result2 << std::endl;
    if (std::abs(result2 - expected2) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 3: x > 0, |y| < x (log)
    float x3 = 2, y3 = 1;
    float result3 = solveEquation(x3, y3);
    float expected3 = 0.861f;
    std::cout << "Test 3: x = 2, y = 1" << std::endl;
    std::cout << "Expected: " << expected3 << ", Got: " << result3 << std::endl;
    if (std::abs(result3 - expected3) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 4: Деление на ноль
    float x4 = 1, y4 = 0;
    float result4 = solveEquation(x4, y4);
    std::cout << "Test 4: x = 1, y = 0 (division by zero)" << std::endl;
    std::cout << "Expected: error (0.0), Got: " << result4 << std::endl;
    if (result4 == 0.0f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 5: arccos с корректными значениями
    float x5 = 1, y5 = 2;
    float result5 = solveEquation(x5, y5);
    float expected5 = 1.0472f;
    std::cout << "Test 5: x = 1, y = 2" << std::endl;
    std::cout << "Expected: " << expected5 << ", Got: " << result5 << std::endl;
    if (std::abs(result5 - expected5) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 6: x ≤ 0 с отрицательными числами
    float x6 = -1, y6 = -1;
    float result6 = solveEquation(x6, y6);
    float expected6 = 0.0f;
    std::cout << "Test 6: x = -1, y = -1" << std::endl;
    std::cout << "Expected: " << expected6 << ", Got: " << result6 << std::endl;
    if (std::abs(result6 - expected6) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 7: x > 0, |y| < x
    float x7 = 3, y7 = 2;
    float result7 = solveEquation(x7, y7);
    float expected7 = 0.732f;
    std::cout << "Test 7: x = 3, y = 2" << std::endl;
    std::cout << "Expected: " << expected7 << ", Got: " << result7 << std::endl;
    if (std::abs(result7 - expected7) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 8: x = 0
    float x8 = 0, y8 = 4;
    float result8 = solveEquation(x8, y8);
    float expected8 = 2.5198f;
    std::cout << "Test 8: x = 0, y = 4" << std::endl;
    std::cout << "Expected: " << expected8 << ", Got: " << result8 << std::endl;
    if (std::abs(result8 - expected8) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 9: arccos с граничными значениями
    float x9 = 0.5f, y9 = 0.6f;
    float result9 = solveEquation(x9, y9);
    float expected9 = 0.5857f;
    std::cout << "Test 9: x = 0.5, y = 0.6" << std::endl;
    std::cout << "Expected: " << expected9 << ", Got: " << result9 << std::endl;
    if (std::abs(result9 - expected9) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Тест 10: log с малыми значениями
    float x10 = 1, y10 = 0.2f;
    float result10 = solveEquation(x10, y10);
    float expected10 = 0.774f;
    std::cout << "Test 10: x = 1, y = 0.2" << std::endl;
    std::cout << "Expected: " << expected10 << ", Got: " << result10 << std::endl;
    if (std::abs(result10 - expected10) < 0.001f) {
        std::cout << "PASSED" << std::endl;
        passed++;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // Итоги
    std::cout << "=== TEST RESULTS ===" << std::endl;
    std::cout << "Passed: " << passed << " out of " << total << std::endl;
    std::cout << "Success rate: " << (passed * 100 / total) << "%" << std::endl;
}

void mainCalculation() {
    float x, y;

    if (inputData(x, y)) {
        float result = solveEquation(x, y);
        outputResult(result);
    }

    std::cout << "\nPress Enter to return to menu...";
    std::cin.get();
}
