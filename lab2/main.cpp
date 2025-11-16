#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;
    std::cout << "6 + 6 = " << calc.Add(6, 6) << std::endl;
    std::cout << "12 - 6 = " << calc.Sub(12, 6) << std::endl;
    return 0;
}
