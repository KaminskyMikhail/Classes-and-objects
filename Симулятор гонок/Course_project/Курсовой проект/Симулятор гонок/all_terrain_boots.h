#pragma once
#include "ground_vehicles.h"
class all_terrain_boots : public ground_vehicles {
public:
	all_terrain_boots(double speed, double travel_to_relax, double relax_time, std::string name) : ground_vehicles(travel_to_relax, relax_time, speed, name) {}

	virtual get_ground_vehicles get_val();
};