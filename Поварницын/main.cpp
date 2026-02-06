#include "functions.h"
#include "iooperations.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int choice;
    double x, y, z;

    do {
        // Выводим меню
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                // Ввод данных
                inputValues(x, y);

                // Вычисление выражения
                z = calculateExpression(x, y);

                // Вывод результата
                displayResult(z);
                break;

            case 2:
                // Выполнение тестов
                runTests();
                break;

            case 3:
                cout << "Выход из программы." << endl;
                break;

            default:
                cout << "Неверный выбор. Попробуйте снова." << endl << endl;
                break;
        }

        // Очистка буфера ввода
        if (choice != 3) {
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while(choice != 3);

    return 0;
}
