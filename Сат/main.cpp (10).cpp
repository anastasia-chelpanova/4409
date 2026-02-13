#include <iostream>
#include <iomanip> //Библиотека для форматирования вывода (например, установка количества знаков после запятой)
#include "header.h (10).h"

//int - целочисленный тип данных, используется для хранения целых чисел без дробной части.

int main() //Главная функция программы, с которой начинается её выполнение.
{
    int choice; //choise - переменная целого типа, предназначенная для хранения выбора пользователя в меню программы.
    double x, y, z; //double - вещественный тип данных двойной точности, используется для хранения дробных чисел с высокой точностью.

    do
    {
        std::cout << "\n   MENU:\n";
        std::cout << "1. Vvesti x, y i proverit uravnenie\n";
        std::cout << "2. Proverka: 10 testov\n";
        std::cout << "3. Vihod\n";
        std::cout << "Vibor: ";
        std::cin >> choice;

        switch (choice) //Оператор выбора, позволяющий выполнять различные действия в зависимости от значения переменной.
        {
        case 1: //Часть оператора switch, соответствующая определённому значению.Если ввели в меню 1,то выполняется case 1.
            enter_dannih(x, y);
            z = raschet(x, y);

            std::cout << std::fixed << std::setprecision(5);
            vivod_dannih(z);
            break; //Оператор прерывания выполнения текущего блока (например, выхода из switch или цикла)

        case 2:
            std::cout << "\n Testirovanie: \n";
            std::cout << std::fixed << std::setprecision(5);

            // TEST 1
            x = -2; y = 1;
            std::cout << "Test 1: x=-2, y=1\n";
            vivod_dannih(raschet(x,y));

            // TEST 2
            x = 0; y = 3;
            std::cout << "Test 2: x=0, y=3\n";
            vivod_dannih(raschet(x,y));

            // TEST 3
            x = 1; y = 2;
            std::cout << "Test 3: x=1, y=2\n";
            vivod_dannih(raschet(x,y));

            // TEST 4
            x = 2; y = -3;
            std::cout << "Test 4: x=2, y=-3\n";
            vivod_dannih(raschet(x,y));

            // TEST 5
            x = 2; y = 1;
            std::cout << "Test 5: x=2, y=1\n";
            vivod_dannih(raschet(x,y));

            // TEST 6
            x = 3; y = 1;
            std::cout << "Test 6: x=3, y=1\n";
            vivod_dannih(raschet(x,y));

            // TEST 7
            x = -1; y = -2;
            std::cout << "Test 7: x=-1, y=-2\n";
            vivod_dannih(raschet(x,y));

            // TEST 8
            x = 0.5; y = -1;
            std::cout << "Test 8: x=0.5, y=-1\n";
            vivod_dannih(raschet(x,y));

            // TEST 9
            x = 4; y = 2;
            std::cout << "Test 9: x=4, y=2\n";
            vivod_dannih(raschet(x,y));

            // TEST 10
            x = -3; y = 0.5;
            std::cout << "Test 10: x=-3, y=0.5\n";
            vivod_dannih(raschet(x,y));

            break;

        case 3:
            std::cout << "programma zavershena.\n";
            break;

        default: //Блок в операторе switch, выполняющийся при отсутствии совпадений с case (оператор).
            std::cout << "OSHIBKA! Viberite ot 1-3.\n";
        }

    } while (choice != 3); //пока значение переменной choice не равно 3 — выполнять цикл

    return 0;
}
