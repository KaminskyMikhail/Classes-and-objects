#include "class_parallelogram.h"

parallelogram::parallelogram(int a, int b, int A, int B) : quadrilateral(a, b, a, b, A, B, A, B) {
		name = "Paralleloqram: ";
	}
	void parallelogram::print() {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
