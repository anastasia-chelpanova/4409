#include "menu.h"
#include <iostream>

void showMenu() {
    std::cout << "========MEEENNNUUU========" << std::endl;
    std::cout << "1.rechit yravnenie" << std::endl;
    std::cout << "2. 5 proverok" << std::endl;
    std::cout << "3. exit" << std::endl;
    std::cout << " viberi (1-3): ";
}

int getUserChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}
