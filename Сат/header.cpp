#include <iostream>
#include <cmath>
#include "header.h"

void enter_dannih(double &x, double &y)
{
    std::cout << "enter x: ";
    std::cin >> x;
    std::cout << "enter y: ";
    std::cin >> y;
}

double reshenie(double x, double y)
{
    double z;
    z = (x * x - y * y + 2 * std::fabs(x * y)) /
        (1 + x * x + y * y);
    return z;
}

void vivod_dannih(double z)
{
    std::cout << "z = " << z << std::endl;
}
