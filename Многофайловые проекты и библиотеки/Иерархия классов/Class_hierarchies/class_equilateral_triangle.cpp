#include "class_equilateral_triangle.h"

equilateral_triangle::equilateral_triangle(int a, int A) : triangle(a, a, a, A, A, A) {
		name = "Equilateral triangle: ";
	}
	void equilateral_triangle::print()  {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}

