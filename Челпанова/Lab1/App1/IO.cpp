#include <iostream>
#include <limits>

#include "IO.hpp"

// Функция для проверки корректности ввода
bool checkInput()
{
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error! Please enter a number." << std::endl;
		return false;
	}
	return true;
}

void inputData(double& x, double& y)
{
	// Ввод x
	do {
		std::cout << "Enter x: ";
		std::cin >> x;
		if (checkInput()) {
			break;
		}
	} while (true);

	// Ввод y
	do {
		std::cout << "Enter y: ";
		std::cin >> y;
		if (checkInput()) {
			break;
		}
	} while (true);
}

void outputResult(double z)
{
	std::cout << "Result z= " << z << std::endl;
}
