#include "validation.hpp"
#include <cctype>
#include <iostream>

// БЛОК ПРОВЕРОК

// 1. Проверка: строка не пустая
bool checkNotEmpty(const std::string& str) {
    return !str.empty();
}

// 2. Проверка: строка состоит только из цифр (и, возможно, минуса в начале)
bool checkIsNumber(const std::string& str) {
    if (str.empty()) return false;
    size_t start = 0;
    if (str[0] == '-') start = 1;
    if (start >= str.length()) return false;

    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) return false;
    }
    return true;
}

// 3. Проверка: число больше 2
bool checkGreaterThan2(int n) {
    return n > 2;
}

// 4. Проверка: число меньше 24
bool checkLessThan24(int n) {
    return n < 24;
}

// 5. Проверка: число нечетное
bool checkIsOdd(int n) {
    return (n % 2) != 0;
}

// 6. Проверка: выбор меню (1 или 2)
bool checkMenuChoice(int choice) {
    return (choice == 1 || choice == 2);
}

// 7. Проверка: успешность ввода (не было ли букв)
bool checkInputSuccess() {
    return !std::cin.fail();
}

// 8. Проверка: положительное число
bool checkIsPositive(int n) {
    return n > 0;
}

// 9. Проверка: корректный размер для матрицы (собирает проверки 3, 4, 5)
bool checkValidSize(int n) {
    return checkGreaterThan2(n) && checkLessThan24(n) && checkIsOdd(n);
}

// 10. Проверка: ввод в диапазоне
bool checkInRange(int val, int min, int max) {
    return val >= min && val <= max;
}