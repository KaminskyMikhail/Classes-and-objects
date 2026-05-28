#include "class_right_triangle.h"
#include "class_myexception.h"

right_triangle::right_triangle(int a, int b, int c, int A, int C) : triangle(a, b, c, A, 90, C) {
		name = "Right triangle: ";
		if (B != 90) {
			throw MyException("Angle B is not equal to 90 degrees");
		}
	}
	void right_triangle::print() {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << "; ahgels " << A << ", " << B << ", " << C << ") create\n" << std::endl;
	}
