#include <iostream>      // для cin, cout
#include <iomanip>       // для fixed, setprecision
#include "header.h"

int main() {

    // ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ

    int choice;                     // Целочисленная переменная для хранения выбора пользователя в меню
    int n;                          // Целочисленная переменная для хранения количества элементов в массиве
    double arr[100];                // Массив вещественных чисел на 100 элементов
    double Xmin, Xmax;              // Переменные для хранения границ диапазона случайных чисел

    // Переменные для результатов

    double S1, S2, S3, S4; // Переменные для хранения средних величин
    int max_i, min_i; // Целочисленные переменные для хранения индексов максимального и минимального элементов
    int count;

    // ГЛАВНЫЙ ЦИКЛ С МЕНЮ

    do {

        // Вывод меню

        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Vvod s klaviatury\n";
        std::cout << "2. Sluchaynye chisla\n";
        std::cout << "3. Proverka 10 testov\n";
        std::cout << "4. Vyhod\n";
        std::cout << "Vash vybor: ";
        std::cin >> choice;

        // Обработка выбора

        switch (choice) { // Оператор множественного выбора в зависимости от значения choice

            // ВВОД С КЛАВИАТУРЫ

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

                std::cout << std::fixed << std::setprecision(4); // Установка формата вывода: фиксированная точка, 4 знака после запятой
                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                break; // Выход из switch (предотвращает выполнение следующих case)
            }

            // СЛУЧАЙНАЯ ГЕНЕРАЦИЯ

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

            // ПРОВЕРКА 10 ТЕСТОВ

            case 3: {

                std::cout << "\n====================================\n";
                std::cout << "              10 TESTOV               \n";
                std::cout << "======================================\n";

                // ТЕСТ 1: n = 5, массив: 1, 2, 3, 4, 5

                std::cout << "\n--------- TEST 1: n = 5 ---------\n";
                n = 5;
                double test1[] = {1, 2, 3, 4, 5};
                for (int i = 0; i < n; i++) arr[i] = test1[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                std::cout << std::fixed << std::setprecision(4);
                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 2: n = 5, массив: 1.5, 2.7, 3.2, 4.8, 5.1

                std::cout << "\n--------- TEST 2: n = 5 ---------\n";
                n = 5;
                double test2[] = {1.5, 2.7, 3.2, 4.8, 5.1};
                for (int i = 0; i < n; i++) arr[i] = test2[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 3: n = 6, массив: 10, 20, 30, 40, 50, 60

                std::cout << "\n--------- TEST 3: n = 6 ---------\n";
                n = 6;
                double test3[] = {10, 20, 30, 40, 50, 60};
                for (int i = 0; i < n; i++) arr[i] = test3[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 4: n = 6, массив: 2.2, 4.4, 6.6, 8.8, 10.1, 12.3

                std::cout << "\n--------- TEST 4: n = 6 ---------\n";
                n = 6;
                double test4[] = {2.2, 4.4, 6.6, 8.8, 10.1, 12.3};
                for (int i = 0; i < n; i++) arr[i] = test4[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 5: n = 4, массив: 1, 1, 1, 1

                std::cout << "\n--------- TEST 5: n = 4 ---------\n";
                std::cout << "(vse elementy odinakovye)\n";
                n = 4;
                double test5[] = {1, 1, 1, 1};
                for (int i = 0; i < n; i++) arr[i] = test5[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 6: n = 4, массив: -5, -3, -1, 2

                std::cout << "\n--------- TEST 6: n = 4 ---------\n";
                std::cout << "(s otricatelnymi chislami)\n";
                n = 4;
                double test6[] = {-5, -3, -1, 2};
                for (int i = 0; i < n; i++) arr[i] = test6[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 7: n = 5, массив: 0.1, 0.5, 1.5, 3.0, 5.5

                std::cout << "\n--------- TEST 7: n = 5 ---------\n";
                n = 5;
                double test7[] = {0.1, 0.5, 1.5, 3.0, 5.5};
                for (int i = 0; i < n; i++) arr[i] = test7[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 8: n = 7, массив: 2, 4, 6, 8, 10, 12, 14

                std::cout << "\n--------- TEST 8: n = 7 ---------\n";
                n = 7;
                double test8[] = {2, 4, 6, 8, 10, 12, 14};
                for (int i = 0; i < n; i++) arr[i] = test8[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 9: n = 8, массив: 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8

                std::cout << "\n--------- TEST 9: n = 8 ---------\n";
                n = 8;
                double test9[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
                for (int i = 0; i < n; i++) arr[i] = test9[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                // ТЕСТ 10: n = 3, массив: 100, 200, 300

                std::cout << "\n--------- TEST 10: n = 3 ---------\n";
                n = 3;
                double test10[] = {100, 200, 300};
                for (int i = 0; i < n; i++) arr[i] = test10[i];

                S1 = sred_arifm(arr, n);
                S2 = sred_geom(arr, n);
                S3 = sred_garm(arr, n);
                S4 = sred_kvadr(arr, n);
                max_i = poisk_max(arr, n);
                min_i = poisk_min(arr, n);
                count = bolshe_srednego(arr, n, S1);

                vyvod(arr, n, S1, S2, S3, S4, max_i, min_i, count);

                break;
            }

            // ВЫХОД

            case 4: {
                std::cout << "Programma zavershena.\n";
                break;
            }

            // НЕПРАВИЛЬНЫЙ ВЫБОР

            default: { // Блок кода для всех остальных значений choice (не 1-4)
                std::cout << "Oshibka! Viberite 1-4.\n";
            }
        }

    } while (choice != 4); // Условие продолжения цикла: повторять, пока choice не равен 4

    return 0;
}
