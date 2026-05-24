#include "class_triangle.h"
	triangle::triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C)
	{
		name = "Triangle";
	}
	void triangle::print() {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}
