#include "runChecks.h"
#include "expression.h"
#include "check.h"
#include <iostream>

void runChecks() {
    std::cout << "========5 PROVEROK========" << std::endl;

    // 5 тестовых случаев
    double tests[5][2] = {
        {2.0, 3.0},      // обычные числа
        {1.0, 1.0},      // x = y
        {0.0, 5.0},      // x = 0
        {-2.0, 3.0},     // отрицательное число
        {0.5, 0.2}       // дробные числа
    };

    for (int i = 0; i < 5; i++) {
        double x = tests[i][0];
        double y = tests[i][1];

        std::cout << "primer " << i+1 << ": x = " << x << ", y = " << y << std::endl;

        if (check(x, y)) {
            double z = calculate(x, y);
            std::cout << "z = " << z << std::endl;
        } else {
            std::cout << "delenie na nol!" << std::endl;
        }
    }
}
