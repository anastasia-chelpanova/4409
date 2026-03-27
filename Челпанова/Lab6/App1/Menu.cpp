#include <iostream> 
#include "Menu.hpp"

// Функция для отображения меню пользователю в терминале
void showMenu() {
    // Выводим разделительную линию
    std::cout << "Menu" << std::endl;
    // Выводим пункт меню 1
    std::cout << "1. Check input.txt file (Manual mode)" << std::endl;
    // Выводим пункт меню 2
    std::cout << "2. Run 10 checks" << std::endl;
    // Выводим пункт меню 3
    std::cout << "3. Exit" << std::endl;
    // Просим пользователя выбрать действие
    std::cout << "Select action: ";
}