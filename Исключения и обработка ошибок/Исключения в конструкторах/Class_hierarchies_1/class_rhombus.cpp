#include "class_rhombus.h"
#include "class_myexception.h"

rhombus::rhombus(int a, int A, int B) : parallelogram(a, a, A, B) {
		name = "Rhombus: ";
		if (a != b || a != c || a != d || A != C || B != D) {
			throw MyException("Error creating a figure. Reason: not all sides are equal, or angles A, C and B, D are not pairwise equal.");
		}
	}
	void rhombus::print() {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << ", " << d << "; ahgels " << A << ", " << B << ", " << C << ", " << D << ") create\n" << std::endl;
	}



