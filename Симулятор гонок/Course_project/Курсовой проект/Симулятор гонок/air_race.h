#pragma once
#include"flying_carpet.h"
#include"eagle.h"
#include"broomstick.h"
#include<vector>
class air_race {
private:
	double distance;
	flying_carpet player1{ 0, 10, "Flying carpet" };
	eagle player2{ 0, 8, "Eagle" };
	broomstick player3{ 0, 20, "Broomstick" };
	airborne_vehicles* players[8];
public:
	air_race(double distance) : distance(distance) {
		for (int i = 0; i < 7; i++) {
			players[i] = nullptr;
		}
		players[7] = &player1;
		players[2] = &player3;
		players[5] = &player2;
	}
	std::vector<double> rest_time(std::vector<int> arr, int count);

};