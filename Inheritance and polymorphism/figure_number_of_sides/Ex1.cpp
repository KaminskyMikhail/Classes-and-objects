#include <iostream>

class figure{
private:
	int num_of_sides;
protected:
	std::string name;
public:
	figure(std::string name) : num_of_sides(0), name(name) {}
	void print_foo() const {
		std::cout << name << ": " << num_of_sides << std::endl;
	}
};

class triangle : public figure {
private:
	int num_of_sides;
public:
	triangle() : num_of_sides(3), figure("Triangle"){}
	void print_foo() const {
		std::cout << name << ": " << num_of_sides << std::endl;
	}

};

class quadrilateral : public figure {
private:
	int num_of_sides;
public: 
	quadrilateral() : num_of_sides(4), figure("Quadrilateral") {}
	void print_foo() const {
		std::cout << name << ": " << num_of_sides << std::endl;
	}
};

int main() {

	std::cout << "Number of sides: " << std::endl;
	figure A("Figure"); triangle B; quadrilateral C;
		A.print_foo();
		B.print_foo();
		C.print_foo();
	return 0;
}