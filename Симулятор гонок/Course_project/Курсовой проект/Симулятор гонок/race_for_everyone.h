#pragma once
#include"air_race.h"
#include"ground_race.h"
class race_for_everyone {
	double distance;
	air_race type_2;
	ground_race type_1;
public:
	race_for_everyone(double distance) : type_1(distance), type_2(distance), distance(distance) {}
	std::vector<double> rest_time(std::vector<int> arr, int count);
};