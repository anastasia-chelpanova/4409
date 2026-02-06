#include "expression.h"
#include <cmath>

double calculate(double x, double y) {
    return (1 - fabs(x * y)) / (1 + fabs(x - y));
}
