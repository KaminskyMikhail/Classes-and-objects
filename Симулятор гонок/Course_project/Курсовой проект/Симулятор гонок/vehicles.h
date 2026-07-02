#pragma once
#include "string"
class vehicles {
protected:
	std::string name;
	double speed;
public:
	vehicles(double speed, std::string name) : speed(speed), name(name) {}
};
