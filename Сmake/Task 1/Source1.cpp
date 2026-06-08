#include <iostream>
#include <conio.h>

int main() {
	std::string name;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
	_getch();
	return 0;
}