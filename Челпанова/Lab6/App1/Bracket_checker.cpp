#include "Bracket_checker.hpp"
#include <vector>

bool checkBrackets(const std::string& text, int& errorPos, char& errorType) {
    std::vector<int> openBracketPositions;

    for (int i = 0; i < static_cast<int>(text.length()); ++i) {
        if (text[i] == '(') {
            openBracketPositions.push_back(i);
        }
        else if (text[i] == ')') {
            if (openBracketPositions.empty()) {
                errorType = ')';
                errorPos = i + 1;
                return false;
            }
            else {
                openBracketPositions.pop_back();
            }
        }
    }

    if (!openBracketPositions.empty()) {
        errorType = '(';
        errorPos = openBracketPositions[0] + 1;
        return false;
    }

    return true;
}