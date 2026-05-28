#include "class_rectangle.h"
#include "class_myexception.h"

rectangle::rectangle(int a, int b) : quadrilateral(a, b, a, b, 90, 90, 90, 90) {
		name = "Rectangle: ";
		if (a != c || b != d || A != 90 || B != 90 || C != 90 || D != 90) {
			throw MyException("Error creating a figure. Reason: sides a, c and b, d are not equal in pairs, or not all angles are equal to 90");
		}
	}
	void rectangle::print()  {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << ", " << d << "; ahgels " << A << ", " << B << ", " << C << ", " << D << ") create\n" << std::endl;
	}
