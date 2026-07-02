#include "air_race.h"
	std::vector<double> air_race::rest_time(std::vector<int> arr, int count) {
		std::vector<double> time_to_overcome;
		time_to_overcome.clear();

		for (int i = 0; i < count; i++) {
			int player_num = arr[i];
			if (player_num >= 0 && player_num < 8 && players[player_num] != nullptr) {
				auto data = players[player_num]->get_val();

				double effective_distance = distance;

				if (player_num == 7) {
					if (effective_distance < 1000) {
					}
					else if (effective_distance < 5000) {
						effective_distance *= 0.97;
					}
					else if (effective_distance < 10000) {
						effective_distance *= 0.9;
					}
					else {
						effective_distance *= 0.95;
					}
				}

				if (player_num == 2) {
					int percent = static_cast<int>(effective_distance / 1000);
					double reduction = percent / 100.0;
					effective_distance *= (1 - reduction);
				}

				if (player_num == 5) {
					effective_distance *= 0.94;
				}

				double all_road_time_player = effective_distance / data.speed;
				time_to_overcome.push_back(all_road_time_player);
			}
		}
		return time_to_overcome;
	}
