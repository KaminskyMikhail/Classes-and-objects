#include "class_isosceles_triangle.h"

isosceles_triangle::isosceles_triangle(int a, int b, int A, int B) : triangle(a, b, a, A, B, A) {
		name = "Isosceles triangle: ";
	}
	void isosceles_triangle::print() {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b= " << b << " c= " << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}


