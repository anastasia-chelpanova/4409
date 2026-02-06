#include "iooperations.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Функция вывода меню
void displayMenu() {
    cout << "===============================" << endl;
    cout << "          МЕНЮ ПРОГРАММЫ       " << endl;
    cout << "===============================" << endl;
    cout << "1. Вычислить выражение" << endl;
    cout << "2. Выполнить тесты" << endl;
    cout << "3. Выйти из программы" << endl;
    cout << "===============================" << endl;
    cout << "Выберите пункт меню: ";
}

// Функция ввода значений x и y
void inputValues(double &x, double &y) {
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите значение y: ";
    cin >> y;
}

// Функция вывода результата
void displayResult(double z) {
    cout << fixed << setprecision(6);
    cout << "Результат: z = " << z << endl << endl;
}
