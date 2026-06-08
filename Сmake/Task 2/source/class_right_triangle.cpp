#include "class_right_triangle.h"

right_triangle::right_triangle(int a, int b, int c, int A, int C) : triangle(a, b, c, A, 90, C) {
		name = "Right triangle: ";
	}
	void right_triangle::print() {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}
