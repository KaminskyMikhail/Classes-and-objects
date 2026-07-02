#include "ground_race.h"

	std::vector<double> ground_race::rest_time(std::vector<int> arr, int count) {
		std::vector<double> time_to_overcome;
		time_to_overcome.clear();

		for (int i = 0; i < count; i++) {
			int player_num = arr[i];
			if (player_num >= 0 && player_num < 7 && players[player_num] != nullptr) {
				auto data = players[player_num]->get_val();

				double all_road_time_player = distance / data.speed;
				double travel_time_hours = data.travel_to_relax / 60.0;
				int stops_player = static_cast<int>(all_road_time_player / travel_time_hours);

				if (all_road_time_player / travel_time_hours == stops_player && stops_player > 0) {
					stops_player--;
				}

				double total_time = all_road_time_player;

				if (stops_player > 0) {
					if (player_num == 4) {
						data.relax_time = 2;
					}
					else if (player_num == 3 || player_num == 6) {
						data.relax_time = 5;
					}
					else if (player_num == 1) {
						data.relax_time = 10;
					}

					if (stops_player > 1) {
						for (int j = 1; j < stops_player; j++) {
							if (player_num == 4) {
								data.relax_time += 2;
							}
							else if (player_num == 3) {
								data.relax_time += 8;
							}
							else if (player_num == 6) {
								if (j == 1) {
									data.relax_time += 6.5;
								}
								else {
									data.relax_time += 8;
								}
							}
							else if (player_num == 1) {
								data.relax_time += 5;
							}
						}
					}

					total_time = all_road_time_player + (data.relax_time / 60.0);
				}

				time_to_overcome.push_back(total_time);
			}
		}
		return time_to_overcome;
	}
