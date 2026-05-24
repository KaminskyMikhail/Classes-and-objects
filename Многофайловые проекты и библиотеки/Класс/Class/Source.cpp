#include <iostream>
#include "Class.h"

int main() {
	char symbol{};
	std::string answer;
	std::cout << "Do you want to specify the initial value of the counter ? Enter yes or no: "; std::cin >> answer;
	while (answer != "yes" && answer != "no") {
		std::cout << "Do you want to specify the initial value of the counter ? Enter yes or no: "; std::cin >> answer;
	}
	if (answer == "yes") {
		char symbol{};
		int var{};
		std::cout << "Enter the initial value of the counter: ";
		std::cin >> var;
		Counter count(var);
		do {
			std::cout << "Enter command ('+', '-', '=' or 'x'): ";
			std::cin >> symbol;
			switch (symbol) {
			case '-': count.dec(); break;
			case '+': count.inc(); break;
			case '=': std::cout << count.get_val() << std::endl; break;
			case 'x': std::cout << "Goodbye!" << std::endl;
			}
		} while (symbol != 'x');
	}
	else if (answer == "no") {
		char symbol{};
		Counter count;
		do {
			std::cout << "Enter command ('+', '-', '=' or 'x'): ";
			std::cin >> symbol;
			switch (symbol) {
			case '-': count.dec(); break;
			case '+': count.inc(); break;
			case '=': std::cout << count.get_val() << std::endl; break;
			case 'x': std::cout << "Goodbye!";
			}
		} while (symbol != 'x');
	}

	return EXIT_SUCCESS;
}