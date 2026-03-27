#pragma once

#include <string>
int ReadSteps();

void PrintResult(int n, int result);

void PrintResultToFile(int n, int result, const std::string& fileName);

void PrintMessage(const std::string& message);

void PrintError(const std::string& message);

void PrintTestResult(int testNumber, bool passed, int n, int actual, int expected);

void PrintTestsSummary(int total, int passed);
