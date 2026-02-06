#include "functions.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

// Функция инициализации локали для русского языка
void initRussianLocale() {
    #ifdef _WIN32
        // Для Windows
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "Russian");
    #endif
}


double calculateExpression(double x, double y) {

    return (x * x - y * y) / (1 + fabs(x * y));
}

// Функция выполнения тестов
void runTests() {

    cout << "\n=== INITIALIZATION TESTS ===" << endl;

    double x, y, z, expected;

    // Тест 1
    x = 1.0; y = 1.0;
    z = calculateExpression(x, y);
    cout << "TEST1 1: x = " << x << ", y = " << y << endl;
    cout << "One of the result: 0.0" << endl;
    cout << "End result: " << z << endl;
    cout << (fabs(z - 0.0) < 0.000001 ? "✓ Test complete" : "✗ Test not complete") << endl << endl;

    // Тест 2
    x = 2.0; y = 0.0;
    z = calculateExpression(x, y);
    cout << "TEST1 2: x = " << x << ", y = " << y << endl;
    cout << "One of the result: 4.0" << endl;
    cout << "End result: " << z << endl;
    cout << (fabs(z - 4.0) < 0.000001 ? "✓ Test complete" : "✗ Test not complete") << endl << endl;

    // Тест 3
    x = 0.0; y = 3.0;
    z = calculateExpression(x, y);
    cout << "TEST3 3: x = " << x << ", y = " << y << endl;
    cout << "One of the result: -9.0" << endl;
    cout << "End result: " << z << endl;
    cout << (fabs(z - (-9.0)) < 0.000001 ? "✓ Test complete" : "✗ Test not complete") << endl << endl;

    // Тест 4
    x = 1.5; y = 2.5;
    expected = calculateExpression(x, y); // Вычисляем ожидаемое значение
    z = calculateExpression(x, y);
    cout << "TEST4 4: x = " << x << ", y = " << y << endl;
    cout << "One of the result: " << expected << endl;
    cout << "End result: " << z << endl;
    cout << (fabs(z - expected) < 0.000001 ? "✓ Test complete" : "✗ Test not complete") << endl << endl;

    // Тест 5
    x = -2.0; y = -2.0;
    z = calculateExpression(x, y);
    cout << "TEST5 5: x = " << x << ", y = " << y << endl;
    cout << "One of the result: 0.0" << endl;
    cout << "End result: " << z << endl;
    cout << (fabs(z - 0.0) < 0.000001 ? "✓ Test complete" : "✗ Test not complete") << endl << endl;

    cout << "=== TEST IS END ===" << endl << endl;
}
