#include <iostream>
#include <limits>
#include <cmath>
#include "header_header.h"

int main() {
    double x, y, z;
do {
    std::cout << "Enter x: ";
        if (std::cin >> x)
            break;
std::cerr << "Error! Enter number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);
    do {
        std::cout << "Enter y: ";
        if (std::cin >> y)
            break;
std::cerr << "Error!Enter number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);
if (check(x,y)) {
z = calculate(x,y);
std::cout << "z = " << z << std::endl;
}
else{
    std::cout << "Error" << std::endl;
}
return 0;
 }
