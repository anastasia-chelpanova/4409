#pragma once

#include <vector>

std::vector<float> GenerateSample(
    size_t count,
    float minVal,
    float maxVal);

size_t CountLessThan(
    const std::vector<float>& sample, 
    float value);

size_t SumNegativeIndices(
    const std::vector<float>& sample);
