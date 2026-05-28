#include "class_quadrilateral.h"
#include "class_myexception.h"

quadrilateral::quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		name = "Quadrilateral: ";
		if ((A + B + C + D) != 360) {
			throw MyException("Error creating shape. Reason: The sum of the angles does not equal 360.");
		}
	}
	void quadrilateral::print() {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << ", " << d << "; ahgels " << A << ", " << B << ", " << C << ", " << D << ") create\n" << std::endl;
	}
