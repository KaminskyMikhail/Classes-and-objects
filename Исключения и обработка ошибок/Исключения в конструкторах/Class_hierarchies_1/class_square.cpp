#include "class_square.h"
#include "class_myexception.h"

square::square(int a) : rectangle(a, a) {
		name = "Square: ";
		if (a != b || a != c || a != d || A != 90 || B != 90 || C != 90 || D != 90) {
			throw MyException("Error creating shape. Reason: Either all sides are not equal or not all angles are 90 degrees.");
		}
	}
	void square::print() {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << ", " << d << "; ahgels " << A << ", " << B << ", " << C << ", " << D << ") create\n" << std::endl;
	}
