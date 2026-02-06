#include <iostream>
#include "solve.h"
#include "runChecks.h"
#include "menu.h"

int main() {
    int choice;

    while (true) {
        showMenu();
        choice = getUserChoice();

        if (choice == 1) {
            solve();
        }
        else if (choice == 2) {
            runChecks();
        }
        else if (choice == 3) {
            std::cout << "Exit" << std::endl;
            break;
        }
        else {
            std::cout << "Ochibka! Povtorite popitku." << std::endl;
        }
    }

    return 0;
}
