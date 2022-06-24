#include <iostream>
#include "CubicEquationSolver.hpp"

int main(int, char**) {
    ces::number a, b, c, d, x;
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "c = "; std::cin >> c;
    std::cout << "d = "; std::cin >> d;
    std::cout << "x = "; std::cin >> x;

    ces::CubicEquation cubicEquation{ a, b, c, d };
    std::cout << cubicEquation.GetResult(x);

    return 0;
}
