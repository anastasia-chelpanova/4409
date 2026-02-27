#include <iostream>      // для cin, cout
#include <iomanip>       // для fixed, setprecision
#include "header.h"

int main() {

    // ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ

    int choice;                     // выбор меню
    int n;                          // количество элементов
    double arr[100];                // массив (макс. 100 элементов)
    double Xmin, Xmax;              // границы для случайных чисел

    // Переменные для результатов

    double S1, S2, S3, S4;
    int max_i, min_i;
    int count;

    // ГЛАВНЫЙ ЦИКЛ С МЕНЮ

    do {

        // Вывод меню

        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Vvod s klaviatury\n";
        std::cout << "2. Sluchaynye chisla\n";
        std::cout << "3. Vyhod\n";
        std::cout << "Vash vybor: ";
        std::cin >> choice;

        // Обработка выбора

        switch (choice) {

            // СЛУЧАЙ 1: ВВОД С КЛАВИАТУРЫ

            case 1: {

                // Ввод данных

                vvod_klav(arr, n);

                // Вычисления

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);

                // Анализ

                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                // Вывод

                std::cout << std::fixed << std::setprecision(4);
                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                break;
            }

            // СЛУЧАЙ 2: СЛУЧАЙНАЯ ГЕНЕРАЦИЯ

            case 2: {

                // Случайная генерация

                vvod_rand(arr, n, Xmin, Xmax);

                // Вычисления

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);

                // Анализ

                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                // Вывод

                std::cout << std::fixed << std::setprecision(4);
                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                break;
            }

            // СЛУЧАЙ 3: ВЫХОД

            case 3: {
                std::cout << "Programma zavershena.\n";
                break;
            }

            // НЕПРАВИЛЬНЫЙ ВЫБОР

            default: {
                std::cout << "Oshibka! Viberite 1-3.\n";
            }
        }

    } while (choice != 3);

    return 0;
}
