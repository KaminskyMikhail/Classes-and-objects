#include "class_parallelogram.h"
#include "class_myexception.h"

parallelogram::parallelogram(int a, int b, int A, int B) : quadrilateral(a, b, a, b, A, B, A, B) {
		name = "Paralleloqram: ";
		if (a != c || b != d || A != C || B != D) {
			throw MyException("Error creating a figure. Reason: sides a, c and b, d are not pairwise equal, or angles A, C and B, D are not pairwise equal.");
		}
	}
	void parallelogram::print() {
		std::cout << name << " (Sides " << a << ", " << b << ", "
			<< c << ", " << d << "; ahgels " << A << ", " << B << ", " << C << ", " << D << ") create\n" << std::endl;
	}
