#pragma once
#include "airborne_vehicles.h"
class eagle : public airborne_vehicles {
public:
	eagle(double coefficient_reduction_speed, double speed, std::string name) : airborne_vehicles(coefficient_reduction_speed, speed, name) {}

	virtual get_airborne_vehicles get_val();
};