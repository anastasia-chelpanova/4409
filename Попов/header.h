#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>


bool inputData(float& x, float& y);
float solveEquation(float x, float y);
void outputResult(float result);
void showError(const std::string& message);
void showMenu();
void runTests();
void mainCalculation();

#endif // HEADER_H_INCLUDED
