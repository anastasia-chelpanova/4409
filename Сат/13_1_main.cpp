#include <iostream>
#include <iomanip>
#include "header.h"

int main() {
    int choice; // Переменная для хранения выбора пользователя в меню.
    int n; // n - порядок матрицы.
    int matrix[24][24]; // Двумерный массив для хранения матрицы (максимальный размер 24x24)

    // Цикл do-while - выполняется хотя бы один раз, продолжается пока choice не равен 3.

    do {
        std::cout << "-----------------------------------\n";
        std::cout << " MENU:\n";
        std::cout << " 1. Vvesti n i poluchit matricu\n";
        std::cout << " 2. Proverka 10 testov\n";
        std::cout << " 3. Vuhod\n";
        std::cout << "-----------------------------------\n";
        std::cout << " Vybor: ";
        std::cin >> choice; // переменная для хранения выбора пользователя.

        // Оператор множественного выбора switch.
        switch (choice) { // switch - множественный выбор.

            case 1: { // вариант выбора.
                vvod_razmera(n);
                sozdat_matricu(matrix, n);
                vyvod_matricy(matrix, n);
                break; // Выход из switch (предотвращает выполнение следующих case).
            }
            case 2: {
                std::cout << "-----------------------------------\n";
                std::cout << " 10 TESTOV:\n";
                std::cout << "-----------------------------------\n";

                // TEST 1: n = 3

                std::cout << "TEST 1: n = 3";
                sozdat_matricu(matrix, 3);
                vyvod_matricy(matrix, 3);

                // TEST 2: n = 5

                std::cout << "TEST 2: n = 5";
                sozdat_matricu(matrix, 5);
                vyvod_matricy(matrix, 5);

                // TEST 3: n = 7

                std::cout << "TEST 3: n = 7";
                sozdat_matricu(matrix, 7);
                vyvod_matricy(matrix, 7);

                // TEST 4: n = 9

                std::cout << "TEST 4: n = 9";
                sozdat_matricu(matrix, 9);
                vyvod_matricy(matrix, 9);

                // TEST 5: n = 11

                std::cout << "TEST 5: n = 11";
                sozdat_matricu(matrix, 11);
                vyvod_matricy(matrix, 11);

                // TEST 6: n = 13

                std::cout << "TEST 6: n = 13";
                sozdat_matricu(matrix, 13);
                vyvod_matricy(matrix, 13);

                // TEST 7: n = 15

                std::cout << "TEST 7: n = 15";
                sozdat_matricu(matrix, 15);
                vyvod_matricy(matrix, 15);

                // TEST 8: n = 17

                std::cout << "TEST 8: n = 17";
                sozdat_matricu(matrix, 17);
                vyvod_matricy(matrix, 17);

                // TEST 9: n = 19

                std::cout << "TEST 9: n = 19";
                sozdat_matricu(matrix, 19);
                vyvod_matricy(matrix, 19);

                // TEST 10: n = 21

                std::cout << "TEST 10: n = 21";
                sozdat_matricu(matrix, 21);
                vyvod_matricy(matrix, 21);

                break; // выход из цикла/switch.
            }
            case 3: {
                std::cout << " Programma zavershena.\n";
                break;
            }

            default: { // вариант по умолчанию, работает когда выбор не подходит (1-3).
                std::cout << " Oshibka! Viberite 1-3.\n";
            }
        }

    } while (choice != 3); // do while - цикл который выполняется хотя бы 1 раз, цикл выполняется до тех пор, пока выбор не будет равен трем.

    return 0;
}
