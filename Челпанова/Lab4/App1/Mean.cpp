#include <stdexcept>
#include <numeric>
#include <cmath>

#include "Mean.hpp"

 /**
  * Вычисляет среднее арифметическое элементов выборки.
  *
  * Принцип работы:
  * Суммируются все элементы вектора, после чего сумма делится на количество элементов.
  * Формула: M = (x1 + x2 + ... + xn) / n
  *
  * Особенности реализации:
  * - Используется std::accumulate для эффективного суммирования.
  * - Инициализация суммы выполнена как 0.0f, чтобы избежать целочисленного переполнения
  *   и обеспечить вычисления в плавающей точке.
  *
  * sample Вектор содержащий выборку чисел (const ссылка для избежания копирования).
  * Результат: Среднее арифметическое значение.
  *
  * Выбрасывает исключение std::runtime_error Если вектор sample пуст (size == 0).
  */
float GetArithmeticMean(
	const std::vector<float>& sample)
{
	if (sample.empty()) {
		throw std::runtime_error("The sample must not be empty");
	}
	// Суммируем все элементы. Начальное значение 0.0f важно для типа float.
	float sum = std::accumulate(sample.begin(), sample.end(), 0.0f);
	return sum / static_cast<float>(sample.size());
}

/**
 * Вычисляет среднее геометрическое модулей элементов выборки.
 *
 * Принцип работы:
 * Классическое среднее геометрическое определяется как корень n-й степени из произведения элементов.
 * Прямое перемножение может быстро привести к переполнению (overflow) или исчезновению порядка (underflow).
 * Поэтому используется логарифмическое тождество:
 * GM = exp( (ln|x1| + ln|x2| + ... + ln|xn|) / n )
 *
 * Особенности реализации:
 * - Перед вычислением от всех элементов берется модуль (std::abs).
 * - Функция поддерживает отрицательные числа (работает с их модулями).
 * - Создается временный вектор absSample для хранения модулей, что увеличивает потребление памяти.
 *
 * sample Вектор содержащий выборку чисел.
 * Результат: Среднее геометрическое модулей значений.
 *
 * Выбрасывает исключение std::runtime_error Если вектор sample пуст.
 * Выбрасывает исключение std::invalid_argument Если хотя бы один элемент равен 0.0f (так как ln(0) не определен,
 *         а произведение, содержащее ноль, обнулит результат).
 */
float GetGeometricMean(
	const std::vector<float>& sample)
{
	if (sample.empty()) {
		throw std::runtime_error("The sample must not be empty");
	}

	// Вектор для хранения модулей значений
	std::vector<float> absSample;
	absSample.reserve(sample.size());

	for (float val : sample) {
		float absVal = std::abs(val);
		// Проверка на ноль критична, так как логарифм от нуля не определен,
		// и геометрическое среднее при наличии нуля всегда равно нулю.
		if (absVal == 0.0f) {
			throw std::invalid_argument("The absolute values ​​must not be equal to zero.");
		}
		absSample.push_back(absVal);
	}

	// Суммируем логарифмы модулей
	float logSum = 0.0f;
	for (float val : absSample) {
		logSum += std::log(val);
	}
	// Возвращаем экспоненту от среднего логарифма
	return std::exp(logSum / static_cast<float>(absSample.size()));
}

/**
 * Вычисляет среднее гармоническое элементов выборки.
 *
 * Принцип работы:
 * Среднее гармоническое равно отношению количества элементов к сумме обратных величин.
 * Формула: H = n / (1/x1 + 1/x2 + ... + 1/xn)
 *
 * Особенности реализации:
 * - Прямое суммирование обратных величин.
 *
 * sample Вектор содержащий выборку чисел.
 * Результат: Среднее гармоническое значение.
 *
 * Выбрасывает исключение std::runtime_error Если вектор sample пуст.
 * Выбрасывает исключение std::invalid_argument Если хотя бы один элемент равен 0.0f (деление на ноль при инверсии).
 */
float GetHarmonicMean(
	const std::vector<float>& sample)
{
	if (sample.empty()) {
		throw std::runtime_error("The sample must not be empty");
	}
	float reciprocalSum = 0.0f;
	for (float val : sample) {
		// Проверка на ноль обязательна, иначе возникнет деление на ноль (inf)
		if (val == 0.0f) {
			throw std::invalid_argument("Values ​​must not be zero");
		}
		reciprocalSum += 1.0f / val;
	}
	return static_cast<float>(sample.size()) / reciprocalSum;
}

/**
 * Вычисляет среднее квадратичное (RMS - Root Mean Square) элементов выборки.
 *
 * Принцип работы:
 * Корень квадратный из среднего арифметического квадратов элементов.
 *
 * Особенности реализации:
 * - Сначала суммируются квадраты, затем берется корень из среднего.
 *
 * sample Вектор содержащий выборку чисел.
 * Результат: Среднее квадратичное значение.
 *
 * Выбрасывает исключение std::runtime_error Если вектор sample пуст.
 */
float GetSquareMean(
	const std::vector<float>& sample)
{
	if (sample.empty()) {
		throw std::runtime_error("The sample must not be empty");
	}
	float sumSquares = 0.0f;
	for (float val : sample) {
		sumSquares += val * val;
	}
	return std::sqrt(sumSquares / static_cast<float>(sample.size()));
}
