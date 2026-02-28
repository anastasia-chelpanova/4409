#pragma once

#include <string>
#include <vector>

void PrintWelcome();

void PrintError(
	const std::string& message);

bool GetInputVariables(
	int& size, 
	float& minVal, 
	float& maxVal);

void PrintResult(
	const std::string& message, 
	float result);

void PrintResult(
	const std::string& message,
	size_t result);

void PrintSample(
	const std::vector<float>& sample, 
	int columns = 6);
