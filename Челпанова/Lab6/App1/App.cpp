#include "App.hpp"
#include "Menu.hpp"
#include "File.hpp"
#include "Tests.hpp"
#include <iostream>
#include <cstdlib>

void runApplication() {
    std::system("chcp 65001 > nul");

    int choice = 0;

    while (true) {
        showMenu();

        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода. Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            processFileTask();
        }
        else if (choice == 2) {
            runTests();
        }
        else if (choice == 3) {
            std::cout << "Выход из программы." << std::endl;
            break;
        }
        else {
            std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        }
    }
}