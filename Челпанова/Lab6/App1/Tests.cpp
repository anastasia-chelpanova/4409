#include "Tests.hpp"
#include "Bracket_checker.hpp"
#include <iostream>
#include <string>

void runTests() {
    std::cout << "\n=== Запуск 10 проверок ===" << std::endl;

    std::string tests[10] = {
        "()", "(a + b)", "((()))", "())", ")(",
        "(", "a)b", "(()", "text without brackets", "(test)(ok)"
    };

    bool expectedResults[10] = {
        true, true, true, false, false, false, false, false, true, true
    };

    int passedCount = 0;

    for (int i = 0; i < 10; ++i) {
        int errPos = 0;
        char errType = ' ';
        bool result = checkBrackets(tests[i], errPos, errType);

        std::cout << "Тест " << (i + 1) << ": \"" << tests[i] << "\" -> ";

        if (result == expectedResults[i]) {
            std::cout << "PASS (Успешно)" << std::endl;
            passedCount++;
        }
        else {
            std::cout << "FAIL (Провал)" << std::endl;
            if (!result) {
                std::cout << "   -> Ошибка: скобка '" << errType << "' на позиции " << errPos << std::endl;
            }
        }
    }

    std::cout << "\nПройдено тестов: " << passedCount << " из 10" << std::endl;
}