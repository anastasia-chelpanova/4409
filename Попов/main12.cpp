#include "header12.h"
#include <iostream>
#include <limits>

int main() {
    int choice; //обозначение переменной  для меню
    bool running = true; // пока true функция работает

    std::cout << "===============================" << std::endl;
    std::cout << "   EQUATION CALCULATION PROGRAM" << std::endl;
    std::cout << "===============================" << std::endl;

    while (running) {
        showMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            showError("Invalid choice! Enter 1, 2, or 3:");
            std::cin.clear(); // сбрасывает флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //cin.ignore(...) - очищает буфер ввода.. игнор пока не встретим новую строку
            std::cout << "Select menu option (1-3): ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                mainCalculation();
                break;

            case 2:
                runTests();
                break;

            case 3:
                std::cout << "\n===============================" << std::endl;
                std::cout << "   Program terminated. Goodbye!" << std::endl;
                std::cout << "===============================" << std::endl;
                running = false;
                break;
        }
    }

    return 0;
}
