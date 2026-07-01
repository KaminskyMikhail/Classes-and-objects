#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
struct get_ground_vehicles {
	std::string name;
	double speed;
	double travel_to_relax;
	double relax_time;
	
};

struct get_airborne_vehicles {
	std::string name;
	double speed;
	double coefficient_reduction_speed;
};

class interface {
	
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class vehicles : public interface {
protected :
	std::string name;
	double speed;
public:
	vehicles(double speed, std::string name) : speed(speed), name(name){}
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class ground_vehicles : public vehicles{
protected:
	double travel_to_relax;// время движения до отдыха
	double relax_time;//время отдыха
public:
	ground_vehicles(double travel_to_relax, double relax_time, double speed, std::string name) : travel_to_relax(travel_to_relax), relax_time(relax_time), vehicles(speed, name) {}
	virtual get_ground_vehicles get_val() {
		return { name, speed, travel_to_relax, relax_time };
	}
	virtual void set_val(const get_ground_vehicles& data) {
		name = data.name;
		speed = data.speed;
		travel_to_relax = data.travel_to_relax;
		relax_time = data.relax_time;
		
	}
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class airborne_vehicles : public vehicles {
protected:
	double coefficient_reduction_speed; // коэффициент снижения скорости
public:
	airborne_vehicles(double coefficient_reduction_speed, double speed, std::string name) : coefficient_reduction_speed(coefficient_reduction_speed), vehicles(speed, name){}
	virtual get_airborne_vehicles get_val() {
		return { name, speed, coefficient_reduction_speed };
	}
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class camel : public ground_vehicles {
public:
	camel(double speed, double travel_to_relax, double relax_time, std::string name) : ground_vehicles(travel_to_relax, relax_time, speed, name){}

	virtual get_ground_vehicles get_val(){
		return { name, speed, travel_to_relax, relax_time };
	}

	
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class racing_camel : public camel {
public:
	racing_camel(double speed, double travel_to_relax, double relax_time, std::string name) : camel(speed, travel_to_relax, relax_time, name) {}

	virtual get_ground_vehicles get_val() {
		return{ name, speed, travel_to_relax, relax_time };
	}
	

};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class centaur : public ground_vehicles {
public:
	centaur(double speed, double travel_to_relax, double relax_time, std::string name) : ground_vehicles(travel_to_relax, relax_time, speed, name){}

	virtual get_ground_vehicles get_val() {
		return{ name, speed, travel_to_relax, relax_time };
	}
	
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class all_terrain_boots : public ground_vehicles {
public:
	all_terrain_boots(double speed, double travel_to_relax, double relax_time, std::string name) : ground_vehicles(travel_to_relax, relax_time, speed, name) {}

	virtual get_ground_vehicles get_val() {
		return{ name, speed, travel_to_relax, relax_time };
	}
	
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class flying_carpet : public airborne_vehicles {
public:
	flying_carpet(double coefficient_reduction_speed, double speed, std::string name) : airborne_vehicles(coefficient_reduction_speed, speed, name){}

	virtual get_airborne_vehicles get_val() {
		return{name, speed, coefficient_reduction_speed};
	}

};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class eagle : public airborne_vehicles {
public:
	eagle(double coefficient_reduction_speed, double speed, std::string name) : airborne_vehicles(coefficient_reduction_speed, speed, name) {}

	virtual get_airborne_vehicles get_val() {
		return{ name, speed, coefficient_reduction_speed };
	}
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class broomstick : public airborne_vehicles {
public:
	broomstick(double coefficient_reduction_speed, double speed, std::string name) : airborne_vehicles(coefficient_reduction_speed, speed, name) {}

	virtual get_airborne_vehicles get_val() {
		return{ name, speed, coefficient_reduction_speed };
	}
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------

class ground_race{
private:
	double distance;
	camel player1{ 10, 30, 0, "Camel" };
	racing_camel player2{40, 10, 0, "Racing camel"};
	centaur player3{15, 8, 0, "Centaur"};
	all_terrain_boots player4{5, 60, 0, "All-terrain boots"};
	ground_vehicles* players[7];
public:
	ground_race(double distance) : distance(distance){
		for (int i = 0; i < 7; i++) {
			players[i] = nullptr;
		}
		players[1] = &player4;
		players[3] = &player1;
		players[4] = &player3;
		players[6] = &player2;
	}
	
	std::vector<double> rest_time(std::vector<int> arr, int count) {
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
					players[player_num]->set_val(data);
				}

				time_to_overcome.push_back(total_time);
			}
		}
		return time_to_overcome;
	}


};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class air_race {
private:
	double distance;
	flying_carpet player1{0, 10, "Flying carpet"};
	eagle player2{0, 8, "Eagle"};
	broomstick player3{0, 20, "Broomstick"};
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
	std::vector<double> rest_time(std::vector<int> arr, int count) {
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

};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class race_for_everyone{
	double distance;
	air_race type_2;
	ground_race type_1;
public:
	race_for_everyone(double distance) : type_1(distance), type_2(distance), distance(distance){}
	std::vector<double> rest_time(std::vector<int> arr, int count) {
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
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------

void sort_pairs(std::vector<double>&, std::vector<int>& party);
bool check(std::vector<int> party, int choice_player);
bool quantity(std::vector<int> party);

int main() {
	std::vector<std::string> for_reg {"", "Ботинки вездеходы", "Метла", "Верблюд", "Кентавр", "Орел", "Верблюд-быстроход", "Ковер-самолет"}; // просто чтобы было
	std::vector<int>party; // участники гонки
	std::vector<double> overcome_time;
	double distance = 0;
	int choice_race = 0, choice_reg = 0, count = 0, out = 0;
	int choice_player = 0;
	std::cout << "Добро пожаловть в гоночный симулятор!" << std::endl;
	do{
		party.clear(); overcome_time.clear();
		std::cout << "1. Гонка для наземного транспорта" << std::endl
		<< "2. Гонка для воздушного транспорта" << std::endl
		<< "3. Гонка для наземного и воздушного транспорта" << std::endl;
		std::cout << "Выберите тип гонки: "; std::cin >> choice_race;
		std::cout << "\n\nУкажите длину дистанции (должна быть положительна): "; std::cin >> distance;
		std::cout << "\n\nДолжно быть зарегистрировано хотя бы 2 транспортных средства " << std::endl
			<< "1. Зарегистрировать транспорт" << std::endl
			<< "Выберите действие : "; std::cin >> choice_reg; std::cout << "\n\n";
		//----------------------------РЕГИСТРаЦИЯ------------------------------------------------------------------
			do {
				if (choice_race == 1) {
					std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << '.' << std::endl;
				}
				else if (choice_race == 2) {
					std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << '.' << std::endl;
				}
				else if (choice_race == 3) {
					std::cout << "Гонка для воздушного и наземного транспорта. Расстояние: " << distance << '.' << std::endl;
				}
				std::cout << "1. Ботинки вездеходы" << std::endl
					<< "2. Метла" << std::endl
					<< "3. Верблюд" << std::endl
					<< "4. Кентавр" << std::endl
					<< "5. Орел" << std::endl
					<< "6. Верблюд-быстроход" << std::endl
					<< "7. Ковер-самолет" << std::endl
					<< "0. Закончить регистрацию" << std::endl
					<< "Выберите транспорт или 0 для окончания процесса регистрации: "; std::cin >> choice_player;
				bool check_qtty = true;
				if (choice_player == 0) {
					check_qtty = quantity(party);
				}
				int to_exit = 0;
				if (check_qtty) {
					bool check_reg = check(party, choice_player);
					if (check_reg) {
						if (choice_race == 1) {
							if (choice_player == 2 || choice_player == 5 || choice_player == 7) {
								std::cout << "\n\nПопытка зарегистрировать неверный тип транспортного средства!" << std::endl;
							}
							else if (choice_player == 3 || choice_player == 1 || choice_player == 4 || choice_player == 6) {
								party.push_back(choice_player);
								std::cout << "\n\n" << for_reg[choice_player] << " Успешно зарегистрирован!" << std::endl;
								choice_reg = 0;
								count++;
							}
						}

						if (choice_race == 2) {
							if (choice_player == 3 || choice_player == 1 || choice_player == 6 || choice_reg == 4) {
								std::cout << "\n\nПопытка зарегистрировать неверный тип транспортного средства!" << std::endl;
							}
							else if (choice_player == 2 || choice_player == 5 || choice_player == 7) {
								party.push_back(choice_player);
								std::cout << "\n\n" << for_reg[choice_player] << " Успешно зарегистрирован!" << std::endl;
								choice_reg = 0;
								count++;
							}
						}

						if (choice_race == 3) {
							if (choice_player >= 1 && choice_player <= 7) {
								party.push_back(choice_player);
								std::cout << "\n\n" << for_reg[choice_player] << " Успешно зарегистрирован!" << std::endl;
								choice_reg = 0;
								count++;
							}
						}
					}
					else { std::cout << "\n\n" << for_reg[choice_player] << " уже зарегистрирован!" << std::endl; };


					if (choice_player == 0) {
						std::cout << "\n\n1. Зарегистрировать транспорт \n2. Начать гонку \nВыберите действие: "; std::cin >> choice_player; std::cout << "\n\n";
						if (choice_player == 2) { choice_player = 0; };
					}
				}
				else if (!check_qtty) {
					do {
						std::cout << "\n\nДолжно быть зарегистрировано хотя бы 2 транспортных средства \n "
							<< "1. Зарегистрировать транспорт\n"
							<< "Выберите действие: "; std::cin >> to_exit; choice_player = 1;
						std::cout << "\n\n";
					} while (to_exit != 1);
				}
			} while (choice_player != 0);
			//----------------------------------------------------------------------------------------------------------
			if (choice_race == 1) {
				ground_race type_1(distance);
				overcome_time = type_1.rest_time(party, count);
				sort_pairs(overcome_time, party);
				std::cout << "Результаты гонки:" << std::endl;
				for (int i = count - 1; i >= 0; i--) {
					int var = party[i];
					std::cout << for_reg[var] << ". Время: " << overcome_time[i] << std::endl;
				}
			}
			else if (choice_race == 2){
				air_race type_2(distance);
				overcome_time = type_2.rest_time(party, count);
				sort_pairs(overcome_time, party);
				std::cout << "Результаты гонки:" << std::endl;
				for (int i = count - 1; i >= 0; i--) {
					int var = party[i];
					std::cout << for_reg[var] << ". Время: " << overcome_time[i] << std::endl;
				}
			}
			else if (choice_race == 3) {
				race_for_everyone type_3(distance);
				overcome_time = type_3.rest_time(party, count);
				sort_pairs(overcome_time, party);
				std::cout << "Результаты гонки:" << std::endl;
				for (int i = count - 1; i >= 0; i--) {
					int var = party[i];
					std::cout << for_reg[var] << ". Время: " << overcome_time[i] << std::endl;
				}
			}
			std::cout << "\n\n1. Провести еще одну гонку\n" << "2. Выйти\n" << "Выберите действие: "; std::cin >> out;
			std::cout << "\n\n";
			count = 0;

	} while (out != 2);


	return EXIT_SUCCESS;
}

bool quantity(std::vector<int> party) {
	return party.size() >= 2;
}

bool check(std::vector<int> party, int choice_player) {
	auto it = std::find(party.begin(), party.end(), choice_player);
	return it == party.end();
}

void sort_pairs(std::vector<double>& values, std::vector<int>& party) {

	std::vector<std::pair<double, int>> pairs;
	for (size_t i = 0; i < values.size(); i++) {
		pairs.push_back({ values[i], party[i] });
	}


	std::sort(pairs.begin(), pairs.end(),
		[](const auto& a, const auto& b) {
			return a.first > b.first;
		});

	for (size_t i = 0; i < pairs.size(); i++) {
		values[i] = pairs[i].first;
		party[i] = pairs[i].second;
	}
}