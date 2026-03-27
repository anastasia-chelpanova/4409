#pragma once

#include <string>

// Объявление функции проверки скобок
// Возвращает true, если скобки расставлены верно
// errorPos и errorType заполняются в случае ошибки
bool checkBrackets(const std::string& text, int& errorPos, char& errorType);