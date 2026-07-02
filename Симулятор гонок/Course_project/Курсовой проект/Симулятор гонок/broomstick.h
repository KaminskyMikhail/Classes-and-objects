#pragma once
#include "airborne_vehicles.h"
class broomstick : public airborne_vehicles {
public:
	broomstick(double coefficient_reduction_speed, double speed, std::string name) : airborne_vehicles(coefficient_reduction_speed, speed, name) {}

	virtual get_airborne_vehicles get_val();
};