#include"race_for_everyone.h"
	std::vector<double> race_for_everyone::rest_time(std::vector<int> arr, int count) {
		std::vector<double> time_to_overcome;
		time_to_overcome.clear();

		std::vector<int> ground_players;
		std::vector<int> air_players;

		for (int i = 0; i < count; i++) {
			int player_num = arr[i];
			if (player_num == 1 || player_num == 3 || player_num == 4 || player_num == 6) {
				ground_players.push_back(player_num);
			}
			else if (player_num == 2 || player_num == 5 || player_num == 7) {
				air_players.push_back(player_num);
			}
		}

		std::vector<double> ground_times;
		if (!ground_players.empty()) {
			ground_times = type_1.rest_time(ground_players, ground_players.size());
		}

		std::vector<double> air_times;
		if (!air_players.empty()) {
			air_times = type_2.rest_time(air_players, air_players.size());
		}

		time_to_overcome.reserve(ground_times.size() + air_times.size());
		time_to_overcome.insert(time_to_overcome.end(), ground_times.begin(), ground_times.end());
		time_to_overcome.insert(time_to_overcome.end(), air_times.begin(), air_times.end());

		return time_to_overcome;
	}