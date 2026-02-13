#include <iostream>
#include <cmath>
#include "header.h (10).h"

void enter_dannih(double &x, double &y)
{
    std::cout << "enter x: ";
    std::cin >> x;
    std::cout << "enter y: ";
    std::cin >> y;
}

double raschet(double x, double y)
{
    if (x <= 0)
    {
        return cbrt(x*x*x + y*y);
    }
    else if (x > 0 && std::fabs(y) >= x)
    {
        return acos(x / y);
    }
    else
    {
        return log(5*x - 3*std::fabs(y)) / log(5*x + 1);
    }
}

void vivod_dannih(double z)
{
    std::cout << "result z = " << z << std::endl;
}
