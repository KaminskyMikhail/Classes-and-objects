#include <iostream>

class Interface {
public:
	virtual void print() = 0;
};
class figure : Interface {
protected:
	std::string name;
public:
	void print() override {
		std::cout << "Figure: " << std::endl;
		std::cout << "Correct" << std::endl;
		std::cout << "Number of sides: 0\n" << std::endl;
	}
};

class triangle : public figure {
protected:
	int a, b, c; // стороны
	int A, B, C; // углы
public:
	triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C)
	{
		name = "Triangle";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0) {
			std::cout << "Number of sides: 3" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if ((A + B + C) == 180) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}
};

class right_triangle : public triangle {
public:
	right_triangle(int a, int b, int c, int A, int C) : triangle(a, b, c, A, 90, C) {
		name = "Right triangle: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0) {
			std::cout << "Number of sides: 3" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if ((A + B + C) == 180 && B == 90) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}
};

class isosceles_triangle : public triangle {
public:
	isosceles_triangle(int a, int b, int A, int B) : triangle(a, b, a, A, B, A) {
		name = "Isosceles triangle: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0) {
			std::cout << "Number of sides: 3" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if ((A + B + C) == 180 && a == c && A == C) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b= " << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}

};

class equilateral_triangle : public triangle {
public:
	equilateral_triangle(int a, int A) : triangle(a, a, a, A, A, A) {
		name = "Equilateral triangle: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0) {
			std::cout << "Number of sides: 3" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if ((A + B + C) == 180 && A == 60 && A == B && A == C && a == b && a == c) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << "\n" << std::endl;
	}

};

class quadrilateral : public figure {
protected:
	int a, b, c, d; // стороны
	int A, B, C, D; // углы
public:
	quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		name = "Quadrilateral: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0 && d!= 0) {
			std::cout << "Number of sides: 4" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if ((A + B + C + D) == 360) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
};

class rectangle : public quadrilateral {
public:
	rectangle(int a, int b) : quadrilateral(a, b, a, b, 90, 90, 90, 90) {
		name = "Rectangle: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0 && d != 0) {
			std::cout << "Number of sides: 4" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if (a == c && b == d && A == 90 && A == B && A == D && A == C) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
};

class square : public rectangle {
public:
	square(int a) : rectangle(a, a) {
		name = "Square: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0 && d != 0) {
			std::cout << "Number of sides: 4" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if (a == b && a == c && a == d && A == 90 && A == B && A == C && A == D) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
};

class parallelogram : public quadrilateral {
public:
	parallelogram(int a, int b, int A, int B) : quadrilateral(a, b, a, b, A, B, A, B) {
		name = "Paralleloqram: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0 && d != 0) {
			std::cout << "Number of sides: 4" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if (a == c && b == d && A == C && B == D) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}
};

class rhombus : public parallelogram {
public:
	rhombus(int a, int A, int B) : parallelogram(a, a, A, B) {
		name = "Rhombus: ";
	}
	void print() override {
		std::cout << name << std::endl;
		if (a != 0 && b != 0 && c != 0 && d != 0) {
			std::cout << "Number of sides: 4" << std::endl;
		}
		else {
			std::cout << "Uncorrect side length" << std::endl;
		}
		if (a == b && a == c && a == d && A == C && B == D) {
			std::cout << "Correct" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n" << std::endl;
	}

};

void print_info(figure* temp) {
	temp->print();
}
int main() {
	figure F;											figure* F_ptr = &F;					print_info(F_ptr);
	triangle TR(10, 20, 30, 50, 60, 70);				figure* triangle_ptr = &TR;			print_info(triangle_ptr);
	right_triangle RTR(10, 20, 30, 50, 40);				figure* right_triangle_ptr = &RTR;	print_info(right_triangle_ptr);
	isosceles_triangle ITR(10, 20, 50, 80);				figure* isos_triangle_ptr = &ITR;	print_info(isos_triangle_ptr);
	equilateral_triangle ETR(30, 60);					figure* equil_triangle_ptr = &ETR;	print_info(equil_triangle_ptr);

	quadrilateral QL(10, 20, 30, 40, 50, 60, 70, 180);	figure* QL_ptr = &QL;				print_info(QL_ptr);
	rectangle RQL(10, 20);								figure* RQL_ptr = &RQL;				print_info(RQL_ptr);
	square SQL(20);										figure* SQL_ptr = &SQL;				print_info(SQL_ptr);
	parallelogram PQL(20, 30, 30, 40);					figure* PQL_ptr = &PQL;				print_info(PQL_ptr);
	rhombus HQL(30, 30, 40);							figure* HQL_ptr = &HQL;				print_info(HQL_ptr);

	return EXIT_SUCCESS;
}