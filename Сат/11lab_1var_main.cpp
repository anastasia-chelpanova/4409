#include <iostream>      // для cin, cout
#include <iomanip>       // для fixed, setprecision
#include <cmath>         // для математических функций
#include "header.h"

int main() {

    int choice;         // переменная для выбора пункта меню
    double x;           // аргумент ряда
    double S, Q;        // сумма и последнее слагаемое
    int n;              // количество слагаемых

    // Цикл do-while - выполняется хотя бы один раз

    do {

        // Вывод меню

        std::cout << "\n MENU:\n";
        std::cout << "1. Vvesti x, n i raschitat\n";
        std::cout << "2. Proverka: 10 testov\n";
        std::cout << "3. Vihod\n";
        std::cout << "Vibor: ";
        std::cin >> choice;

        // Оператор switch - выбор действия по значению choice

        switch (choice) {

            // СЛУЧАЙ 1: ВВОД И РАСЧЕТ

            case 1: {

                // Ввод данных (x и n передаются по ссылке)

                enter_dannih(x, n);

                // Вычисление (Q передается по ссылке)

                S = raschet(x, n, Q);

                // Установка формата вывода
                // fixed - фиксированная точка, не научная нотация
                // setprecision(10) - 10 знаков после запятой

                std::cout << std::fixed << std::setprecision(10);

                // Вывод результатов

                vivod_dannih(S, Q);
                break;      // выход из switch
            }

            // СЛУЧАЙ 2: ТЕСТИРОВАНИЕ (10 ТЕСТОВ)

            case 2: {
                std::cout << "\n Testirovanie: \n";
                std::cout << std::fixed << std::setprecision(10);

                // ТЕСТ 1: x = 0.1, n = 5
                x = 0.1; n = 5;
                std::cout << "\nTest 1: x=0.1, n=5\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 2: x = 0.2, n = 5
                x = 0.2; n = 5;
                std::cout << "\nTest 2: x=0.2, n=5\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 3: x = 0.3, n = 5
                x = 0.3; n = 5;
                std::cout << "\nTest 3: x=0.3, n=5\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 4: x = 0.4, n = 10
                x = 0.4; n = 10;
                std::cout << "\nTest 4: x=0.4, n=10\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 5: x = 0.5, n = 10
                x = 0.5; n = 10;
                std::cout << "\nTest 5: x=0.5, n=10\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 6: x = -0.1, n = 5
                x = -0.1; n = 5;
                std::cout << "\nTest 6: x=-0.1, n=5\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 7: x = -0.2, n = 5
                x = -0.2; n = 5;
                std::cout << "\nTest 7: x=-0.2, n=5\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 8: x = 0.7, n = 8
                x = 0.7; n = 8;
                std::cout << "\nTest 8: x=0.7, n=8\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 9: x = 0.9, n = 12
                x = 0.9; n = 12;
                std::cout << "\nTest 9: x=0.9, n=12\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                // ТЕСТ 10: x = -0.5, n = 7
                x = -0.5; n = 7;
                std::cout << "\nTest 10: x=-0.5, n=7\n";
                S = raschet(x, n, Q);
                vivod_dannih(S, Q);

                break;      // выход из switch
            }

            // СЛУЧАЙ 3: ВЫХОД ИЗ ПРОГРАММЫ

            case 3: {
                std::cout << "Programma zavershena.\n";
                break;
            }

            // СЛУЧАЙ ПО УМОЛЧАНИЮ: если выбран не 1, 2 или 3

            default: {
                std::cout << "OSHIBKA! Viberite 1-3.\n";
            }
        }

    } while (choice != 3);    // повторять, пока не выбран 3 (выход)

    return 0;    // успешное завершение программы
}
