#include <iostream>
#include <fstream>
#include <stdexcept>

int ReadSteps()
{
    int n;

    std::cout << "Enter the number of steps (n >= 0): ";
    std::cin >> n;

    // Проверка корректности ввода
    if (n < 0) {
		throw std::runtime_error("The number of steps cannot be negative!");
    }

    return n;
}

void PrintResult(int n, int result)
{
    std::cout << std::endl;
    std::cout << "Result:" << std::endl;
    std::cout << "Number of ways to climb the stairs from " << n << " steps = " << result << std::endl;
}

// Запись результата в файл
void PrintResultToFile(int n, int result, const std::string& fileName)
{
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << "Number of steps: " << n << std::endl;
        outFile << "Number of ways: " << result << std::endl;
        outFile.close();

        std::cout << "The result has been successfully written to the file \"" << fileName << "\"" << std::endl;
    }
    else {
		throw std::runtime_error("Failed to create file to write result to.");
    }
}

void PrintMessage(const std::string& message)
{
	std::cout << message << std::endl;
}

void PrintError(const std::string& message)
{
	std::cerr << "Error: " << message << std::endl;
}

void PrintTestResult(int testNumber, bool passed, int n, int actual, int expected)
{
    if (passed) {
        std::cout << "Test " << testNumber << ": PASSED | "
            << "countWays(" << n << ") = " << actual
            << " (expected " << expected << ")" << std::endl;
    }
    else {
        std::cout << "Test " << testNumber << ": FAILED | "
            << "countWays(" << n << ") = " << actual
            << " (expected " << expected << ")" << std::endl;
	}
}

void PrintTestsSummary(int total, int passed)
{
    std::cout << std::endl;
	std::cout << "Tests summary: " << passed << " out of " << total << " tests passed." << std::endl;
}
