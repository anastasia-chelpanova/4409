#include <cmath>
#include <stdexcept>

#include "Compute.hpp"

double compute(double x, double y)
{
	double numerator = std::abs(x) + std::abs(y);
	double denominator = 1 + std::abs(x * y);

	// Проверка на деление на ноль
	if (denominator == 0) {
		throw std::runtime_error("Error: Division by zero!");
	}
	return numerator / denominator;
}
