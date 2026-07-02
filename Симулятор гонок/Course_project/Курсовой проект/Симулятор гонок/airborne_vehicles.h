#pragma once
#include "vehicles.h"
#include "get_airborne_vehicles.h"
#include <string>
class airborne_vehicles : public vehicles {
protected:
	double coefficient_reduction_speed; // коэффициент снижения скорости
public:
	airborne_vehicles(double coefficient_reduction_speed, double speed, std::string name) : coefficient_reduction_speed(coefficient_reduction_speed), vehicles(speed, name) {}
	virtual get_airborne_vehicles get_val();
};