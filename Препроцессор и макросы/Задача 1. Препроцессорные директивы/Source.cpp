#include <iostream>
#define MODE 0
#ifndef MODE
#error "MODE is not defined. Please define MODE with an integer value (0, 1, etc.)"
#endif

double addition(double a, double b);

int main() {

#if MODE == 0
	std::cout << "I'm working in training mode.\n";
#elif MODE == 1 
	double a, b;
	std::cout << "I'm working in combat mode." << std::endl;
	std::cout << "Enter number 1: "; std::cin >> a;
	std::cout << "Enter number 2: "; std::cin >> b;
	std::cout<< "Addition result: " << addition(a, b);
#else
	std::cout << "Unknown mode.Shutting down.\n";
#endif // MODE == 1

	return 0;
}
double addition(double a, double b) {
	return a + b;
}