
#include <iostream>
#include "header.hpp"

int main() {
    float x, y, z;

    enter_data(x, y);

    try {
        z = reshenie(x, y);
        vivod(z);
    } catch (const std::runtime_error& e) {
        std::cout << "Ошибка вычисления: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
