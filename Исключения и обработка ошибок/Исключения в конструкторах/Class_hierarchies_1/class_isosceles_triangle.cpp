#include "class_isosceles_triangle.h"
#include "class_myexception.h"

isosceles_triangle::isosceles_triangle(int a, int b, int A, int B) : triangle(a, b, a, A, B, A) {
		name = "Isosceles triangle: ";
		if (a != c || A != C) {
			throw MyException("Error creating shape. Reason: Angles or sides are not equal.");
		}

	}
	void isosceles_triangle::print() {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << "; ahgels " << A << ", " << B << ", " << C << ") create\n" << std::endl;
	}


