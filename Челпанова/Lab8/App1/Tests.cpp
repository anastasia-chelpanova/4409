#include "Tests.hpp"

#include "Ways.hpp"
#include "IO.hpp"

// Вспомогательная функция для запуска одного теста
bool RunTest(int testNumber, int n, int expected) {
    int actual = CountWays(n);
    if (actual == expected) {
		PrintTestResult(testNumber, true, n, actual, expected);
        return true;
    }
    else {
		PrintTestResult(testNumber, false, n, actual, expected);
        return false;
    }
}

void RunTests()
{
	PrintMessage("Running tests for CountWays function...");

    int passed = 0;

    // Тест 1: граничный случай n = 0
    if (RunTest(1, 0, 1)) {
        passed++;
    }

    // Тест 2: граничный случай n = 1
    if (RunTest(2, 1, 1)) {
        passed++;
    }

    // Тест 3: n = 2 (минимальный рекурсивный случай)
    if (RunTest(3, 2, 2)) {
        passed++;
    }

    // Тест 4: n = 3
    if (RunTest(4, 3, 3)) {
        passed++;
    }

    // Тест 5: n = 4
    if (RunTest(5, 4, 5)) {
        passed++;
    }

    // Тест 6: n = 5
    if (RunTest(6, 5, 8)) {
        passed++;
    }

    // Тест 7: n = 6
    if (RunTest(7, 6, 13)) {
        passed++;
    }

    // Тест 8: n = 10
    if (RunTest(8, 10, 89)) {
        passed++;
    }

    // Тест 9: некорректное значение n = -1
    if (RunTest(9, -1, 0)) {
        passed++;
    }

    // Тест 10: некорректное значение n = -10
    if (RunTest(10, -10, 0)) {
        passed++;
    }

	PrintTestsSummary(10, passed);
}
