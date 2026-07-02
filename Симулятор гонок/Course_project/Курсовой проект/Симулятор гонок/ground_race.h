#pragma once
#include"camel.h"
#include"centaur.h"
#include"racing_camel.h"
#include"all_terrain_boots.h"
#include<vector>

class ground_race {
private:
	double distance;
	camel player1{ 10, 30, 0, "Camel" };
	racing_camel player2{ 40, 10, 0, "Racing camel" };
	centaur player3{ 15, 8, 0, "Centaur" };
	all_terrain_boots player4{ 5, 60, 0, "All-terrain boots" };
	ground_vehicles* players[7];
public:
	ground_race(double distance) : distance(distance) {
		for (int i = 0; i < 7; i++) {
			players[i] = nullptr;
		}
		players[1] = &player4;
		players[3] = &player1;
		players[4] = &player3;
		players[6] = &player2;
	}

	std::vector<double> rest_time(std::vector<int> arr, int count);
};