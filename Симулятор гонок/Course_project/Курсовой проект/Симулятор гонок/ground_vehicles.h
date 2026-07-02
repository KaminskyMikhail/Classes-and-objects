#pragma once
#include "vehicles.h"
#include "get_ground_vehicles.h"
#include <string>
class  ground_vehicles : public vehicles {
protected:
	double travel_to_relax;// время движения до отдыха
	double relax_time;//время отдыха
public:
	ground_vehicles(double travel_to_relax, double relax_time, double speed, std::string name) : travel_to_relax(travel_to_relax), relax_time(relax_time), vehicles(speed, name) {};
	virtual get_ground_vehicles get_val();
};