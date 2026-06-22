#pragma once
#include <iostream>

class Greeter {
private:
	std::string var = "Hello, ";
public:
	Greeter() = default;
	std::string greet(std::string a) const;
};