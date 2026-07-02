#include "airborne_vehicles.h"
	
	get_airborne_vehicles airborne_vehicles::get_val() {
		return { name, speed, coefficient_reduction_speed };
	}
