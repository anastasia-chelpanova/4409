#include "check.h"
#include <cmath>

bool check(double x, double y) {
    double denominator = 1 + fabs(x - y);
    return denominator != 0;
}
