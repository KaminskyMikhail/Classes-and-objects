#include "class_rectangle.h"

rectangle::rectangle(int a, int b) : quadrilateral(a, b, a, b, 90, 90, 90, 90) {
		name = "Rectangle: ";
	}
	void rectangle::print()  {
		std::cout << name << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
