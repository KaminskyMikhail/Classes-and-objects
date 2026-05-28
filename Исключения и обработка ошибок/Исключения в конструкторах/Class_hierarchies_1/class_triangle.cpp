#include "class_triangle.h"
#include "class_myexception.h"
	triangle::triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C)
	{
		name = "Triangle";
		if ((A + B + C) != 180) {

			throw MyException("Error creating shape. Reason: The sum of the angles does not equal 180.");
		
		}
	}
	void triangle::print() {
		std::cout << name << " (Sides " << a <<", " << b << ", " 
			<< c << "; ahgels " << A << ", " << B << ", " << C << ") create\n" << std::endl;

	}
