#include "class_rhombus.h"

rhombus::rhombus(int a, int A, int B) : parallelogram(a, a, A, B) {
		name = "Rhombus: ";
	}
	void rhombus::print() {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}



