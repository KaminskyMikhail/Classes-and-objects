#include "class_square.h"

square::square(int a) : rectangle(a, a) {
		name = "Square: ";
	}
	void square::print() {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
