#pragma once
#include "camel.h"
class racing_camel : public camel {
public:
	racing_camel(double speed, double travel_to_relax, double relax_time, std::string name) : camel(speed, travel_to_relax, relax_time, name) {}

	virtual get_ground_vehicles get_val();
};