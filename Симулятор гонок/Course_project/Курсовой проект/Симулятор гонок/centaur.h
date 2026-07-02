#pragma once
#include "ground_vehicles.h"
class centaur : public ground_vehicles {
public:
	centaur(double speed, double travel_to_relax, double relax_time, std::string name) : ground_vehicles(travel_to_relax, relax_time, speed, name) {}

	virtual get_ground_vehicles get_val();

};