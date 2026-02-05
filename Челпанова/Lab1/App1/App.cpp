#include <stdexcept>
#include <iostream>

#include "Compute.hpp"
#include "IO.hpp"

int run()
{
	double x{ 0.0 }, y{ 0.0 }, z{ 0.0 };

	try {

		// Вызов функции ввода
		inputData(x, y);

		// Вызов функции вычисления
		z = compute(x, y);

		// Вызов функции вывода
		outputResult(z);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
