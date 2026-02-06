#include "solve.h"
#include "expression.h"
#include "check.h"
#include <iostream>

void solve() {
    std::cout << "========RECHENIE YRAVNENIA========" << std::endl;
    std::cout << "z = (1 - |x * y|) / (1 + |x - y|)" << std::endl;

    double x, y;

    std::cout << "vvedite x: ";
    std::cin >> x;

    std::cout << "vvedite y: ";
    std::cin >> y;

    if (check(x, y)) {
        double z = calculate(x, y);
        std::cout << "rezyltat: z = " << z << std::endl;
    } else {
        std::cout << "ochibka! " << std::endl;
    }
}
