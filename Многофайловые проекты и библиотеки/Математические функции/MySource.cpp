#include <iostream>
#include "mathematical_functions.h"

int main(int argc, char** argv) {
	Calc result; int num;
	std::cout << "Select operation (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - raising to a power): "; std::cin >> num;
	switch (num) {
	case 1: std::cout << result.get_a() << " + " << result.get_b() << " = " << result.addition() << std::endl; break;
	case 2: std::cout << result.get_a() << " - " << result.get_b() << " = " << result.subtraction() << std::endl; break;
	case 3: std::cout << result.get_a() << " * " << result.get_b() << " = " << result.multiplication() << std::endl; break;
	case 4: std::cout << result.get_a() << " / " << result.get_b() << " = " << result.division() << std::endl; break;
	case 5: std::cout << result.get_a() << " to the power of " << result.get_b() << " = " << result.exponentiation() << std::endl; break;
	}
}
