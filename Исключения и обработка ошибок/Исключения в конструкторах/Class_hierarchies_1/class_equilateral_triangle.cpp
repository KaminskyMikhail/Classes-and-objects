#include "class_equilateral_triangle.h"
#include "class_myexception.h"

equilateral_triangle::equilateral_triangle(int a, int A) : triangle(a, a, a, A, A, A) {
		name = "Equilateral triangle: ";
		if (A != 60 || A != B || A != C || a != b || a != c) {
			throw MyException("Error creating shape. Reason: all sides or angles are not equal.");
		}
		
	}
	void equilateral_triangle::print()  {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << "; ahgels " << A << ", " << B << ", " << C << ") create\n" << std::endl;
	}

