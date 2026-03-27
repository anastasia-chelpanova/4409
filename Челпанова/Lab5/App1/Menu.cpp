#include "Menu.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void showMenu() {
    std::cout << "\n====== Menu ======\n";
    std::cout << "1. Generate a matrix\n";
    std::cout << "2. Show all checks\n";
    std::cout << "3. Exit\n";
    std::cout << "====================\n";
    std::cout << "Your choice: ";
}

void showChecks() {
    std::cout << "\n====== Tasts results ======\n";

    int passedCount = 0;
    int totalCount = 10;

    // Проверка 1: Число в диапазоне
    {
        int value = 5;
        bool result = (value >= 3 && value <= 23);
        std::cout << "1. Number " << value << " in the range [3, 23]: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed)\n";
        }
    }

    // Проверка 2: Число нечётное
    {
        int value = 7;
        bool result = (value % 2 != 0);
        std::cout << "2. Number " << value << " odd: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed)\n";
        }
    }

    // Проверка 3: Число больше 2 (ПРОВАЛ - специальное значение)
    {
        int value = 2;  // Специально неправильное значение
        bool result = (value > 2);
        std::cout << "3. Number " << value << " more than 2: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed) - the number is equal 2\n";
        }
    }

    // Проверка 4: Число меньше 24
    {
        int value = 15;
        bool result = (value < 24);
        std::cout << "4. Number " << value << " less than 24: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed)\n";
        }
    }

    // Проверка 5: Строка не пустая
    {
        std::string text = "Hello";
        bool result = !text.empty();
        std::cout << "5. The line is not empty: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed)\n";
        }
    }

    // Проверка 6: Строка содержит только цифры (ПРОВАЛ)
    {
        std::string text = "abc123";  // Специально неправильное значение
        bool result = true;
        for (char c : text) {
            if (!isdigit(c)) {
                result = false;
                break;
            }
        }
        std::cout << "6. Line \"" << text << "\" only numbers: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed) - there are letters\n";
        }
    }

    // Проверка 7: Положительное число
    {
        int value = 10;
        bool result = (value > 0);
        std::cout << "7. Number " << value << " positive: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed)\n";
        }
    }

    // Проверка 8: Выбор меню корректный (ПРОВАЛ)
    {
        int choice = 5;  // Специально неправильное значение
        bool result = (choice >= 1 && choice <= 3);
        std::cout << "8. Menu selection " << choice << " in the range [1, 3]: ";
        if (result) {
            std::cout << "PASS(passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed) - out of range\n";
        }
    }

    // Проверка 9: Число нечётное И в диапазоне
    {
        int value = 9;
        bool result = (value % 2 != 0) && (value >= 3 && value <= 23);
        std::cout << "9. Number " << value << " odd and in [3, 23]: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed)\n";
        }
    }

    // Проверка 10: Массив не null (ПРОВАЛ)
    {
        int* arr = nullptr;  // Специально неправильное значение
        bool result = (arr != nullptr);
        std::cout << "10. The pointer is not null: ";
        if (result) {
            std::cout << "PASS (passed)\n";
            passedCount++;
        }
        else {
            std::cout << "FAIL (not passed) - pointer null\n";
        }
    }

    // Итоговая статистика
    std::cout << "  Passed: " << passedCount << " from " << totalCount;

    if (passedCount == totalCount) {
        std::cout << "Status: ALL CHECKS PASSED!\n";
    }
    else {
        std::cout << "Status: THERE ARE FAILED CHECKS\n";
    }

    std::cout << "\nPress Enter to continue...";
    std::string dummy;
    std::getline(std::cin, dummy);
}