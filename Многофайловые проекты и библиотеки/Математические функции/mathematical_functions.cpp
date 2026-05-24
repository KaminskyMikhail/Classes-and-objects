
#include "mathematical_functions.h"
#include <iostream>

Calc::Calc() {
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
}

double Calc::get_a() {
    return a;
}
double Calc::get_b() {
    return b;
}
double Calc::addition() {
    return a + b;
}

double Calc::subtraction() {
    return a - b;
}

double Calc::multiplication() {
    return a * b;
}

double Calc::division() {
    if (b != 0) {
        return a / b;
    }
    else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
}

double Calc::exponentiation() {
    double result = a; 
    for (int i = 1; i < b; i++) {
        result *= a;
    }
    return result;
}

