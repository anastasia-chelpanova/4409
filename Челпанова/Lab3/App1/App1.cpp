#include <iostream>
#include <cmath>


// функция вычисляет n-е слагаемое ряда
double getTern(int n, double x) 
{
    double tern = x;       // первое слагаемое равно x

    // вычисление n-го слагаемого
    for (int i = 2; i <= n; i++) 
    {
        tern = tern * (-x * x) / ((2 * i - 2) * (2 * i - 1));
    }

    return tern;
}

// функция вычисления суммы первых n слагаемых
double getSum(int n, double x) 
{
    double sum = 0;
    double tern = x;      // первое слагаемое
    for (int i = 1; i <= n; i++) 
    {
        if (i == 1)
        {
            tern = x;         // первое слагаемое
        }
        else 
        {
            tern = tern * (-x * x) / ((2 * i - 2) * (2 * i - 1));
        }
        sum = sum + tern;
    }
    return sum;
}

// функция ввода данных
void inputData(int& n, double& x) 
{
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter x: ";
    std::cin >> x;

}

// функция вывода результатов
void outputData(double Q, double S) 
{
    std::cout << "Q= " << Q  << std::endl;
    std::cout << "S= " << S  << std::endl;
    
}

// функция проверки ввода
bool validateInput(int n)
{
    if (n <= 0) {
        std::cout << "Error: n must be > 0\n";
        return false;
    }
    if (n >= 10000) {
        std::cout << "Error: n must be < 10000\n";
        return false;
    }
    return true;
}

// функция отображения меню
void showMenu()
{
    std::cout << std::endl;
    std::cout << "        Menu        " << std::endl;
    std::cout << "1. Calculate Q and S" << std::endl;
    std::cout << "2. Tests" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "4. Select variant: " << std::endl;
}

// обработчик расчета
void handleCalculate()
{
    int n;
    double x;
    inputData(n, x);

    // Проверки входных данных
    if (!validateInput(n)) {
        return;
    }
    if (std::abs(x) > 100) {
        std::cout << "Warning: large x value, results may be inaccurate\n";
    }

    double Q = getTern(n, x);
    double S = getSum(n, x);
    outputData(Q, S);
}

// функция запуска тестов
void runTests()
{
    std::cout << "        Tests        " << std::endl;
    int passed = 0;         //счетчик пройденных тестов

    // Тест 1: n=1, x=0, Q=0, S=0
    {
        int n = 1;
        double x = 0;
        double Q = getTern(n, x);
        double S = getSum(n, x);
        double expectedQ = 0;
        double expectedS = 0;

        if (Q == expectedQ && S == expectedS)
        {
            std::cout << "Test 1: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 1: not passed" << std::endl;
            std::cout << "Received: Q=" << Q << ", S=" << S << std::endl;
            std::cout << "Expected: Q= " << expectedQ << ", S=" << expectedS << std::endl;
        }
    }

    // Тест 2: n=1, x=1, Q=1, S=1
    {
        int n = 1;
        double x = 1;
        double Q = getTern(n, x);
        double S = getSum(n, x);
        double expectedQ = 1;
        double expectedS = 1;

        if (Q == expectedQ && S == expectedS)
        {
            std::cout << "Test 2: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 2: not passed" << std::endl;
            std::cout << "Received: Q=" << Q << ", S=" << S << std::endl;
            std::cout << "Expected: Q= " << expectedQ << ", S=" << expectedS << std::endl;
        }
    }

    // Тест 3: n=2, x=1, Q=-0,166667, S=0,833333
    {
        int n = 2;
        double x = 1;
        double Q = getTern(n, x);
        double S = getSum(n, x);
        double expectedQ = -0.166667;
        double expectedS = 0.833333;

        if (Q == expectedQ && S == expectedS)
        {
            std::cout << "Test 3: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 3: not passed" << std::endl;
            std::cout << "Received: Q=" << Q << ", S=" << S << std::endl;
            std::cout << "Expected: Q= " << expectedQ << ", S=" << expectedS << std::endl;
        }
    }

    // Тест 4: n=3, x=1, Q=-0,00833333, S=0,841667
    {
        int n = 3;
        double x = 1;
        double Q = getTern(n, x);
        double S = getSum(n, x);
        double expectedQ = -0.00833333;
        double expectedS = 0.841667;

        if (Q == expectedQ && S == expectedS)
        {
            std::cout << "Test 4: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 4: not passed" << std::endl;
            std::cout << "Received: Q=" << Q << ", S=" << S << std::endl;
            std::cout << "Expected: Q= " << expectedQ << ", S=" << expectedS << std::endl;
        }
    }

    // Тест 5: n=5, x=0,5, провепка суммы (должно быть S = 0,479426)
    {
        int n = 5;
        double x = 0.5;
        double S = getSum(n, x);
        double expectedS = 0.479426;

        if (std::abs(S - expectedS) < 0.000001)
        {
            std::cout << "Test 5: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 5: not passed" << std::endl;
            std::cout << "Received: S= " << S << std::endl;
            std::cout << "Expected: S= " << expectedS << std::endl;
        }
    }

    // Тест 6: n=10, x=0,5, большая точность
    {
        int n = 10;
        double x = 0.5;
        double S = getSum(n, x);
        double expectedS = std::sin(0.5);

        if (std::abs(S - expectedS) < 0.000000001)
        {
            std::cout << "Test 6: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 6: not passed" << std::endl;
            std::cout << "Received: S= " << S << std::endl;
            std::cout << "Expected: S= " << expectedS << std::endl;
        }
    }

    // Тест 7: n=5, x=0, sin(0)=0
    {
        int n = 5;
        double x = 0;
        double S = getSum(n, x);
        double expectedS = 0;

        if (std::abs(S - expectedS))
        {
            std::cout << "Test 7: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 7: not passed" << std::endl;
            std::cout << "Received: S= " << S << std::endl;
            std::cout << "Expected: S= " << expectedS << std::endl;
        }
    }

    // Тест 8: n=7, x=3.14/2, sin(3.14/2)=1
    {
        int n = 7;
        double x = 3.14/2;
        double S = getSum(n, x);
        double expectedS = 1.0;

        if (std::abs(S - expectedS) < 0.001)
        {
            std::cout << "Test 8: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 8: not passed" << std::endl;
            std::cout << "Received: S= " << S << std::endl;
            std::cout << "Expected: S= " << expectedS << std::endl;
        }
    }

    // Тест 9: n=4, x=2, проверка слагаемого
    {
        int n = 4;
        double x = 2;
        double Q = getTern(n, x);
        double expectedQ = -0.0253968;

        if (std::abs(Q - expectedQ) < 0.000001)
        {
            std::cout << "Test 9: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 9: not passed" << std::endl;
            std::cout << "Received: Q= " << Q << std::endl;
            std::cout << "Expected: Q= " << expectedQ << std::endl;
        }
    }


    // Тест 10: n=15, x=1, высокая точность
    {
        int n = 10;
        double x = 1;
        double S = getSum(n, x);
        double expectedS = std::sin(1.0);

        if (std::abs(S - expectedS) < 0.0000000001)
        {
            std::cout << "Test 10: passed" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "Test 10: not passed" << std::endl;
            std::cout << "Received: S= " << S << std::endl;
            std::cout << "Expected: S= " << expectedS << std::endl;
        }
    }

    // итог тестов

    std::cout << "Passed tests: " << passed << "out of 10" << std::endl;

}

// главный цикл меню
void menuLoop()
{
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            handleCalculate();
            break;
        case 2:
            runTests();
            break;
        case 3:
            std::cout << "\nExit..." << std::endl;
            break;
        default:
            std::cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 3);
}


int main()
{
    menuLoop();
    return 0;
}

