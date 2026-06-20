#include <iostream>
#include "Header.h"

int main() {
	Leaver person;
	std::cout << "Enter name: ";
	std::string name, conc_result; std::cin >> name;
	conc_result = person.leave(name);
	std::cout << conc_result << std::endl;
	system("Pause");
	return 0;
}