#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "get_ground_vehicles.h"
#include "get_airborne_vehicles.h" 
#include "vehicles.h" 
#include "ground_vehicles.h" 
#include "airborne_vehicles.h" 
#include "camel.h" 
#include "racing_camel.h" 
#include "centaur.h" 
#include "all_terrain_boots.h" 
#include "flying_carpet.h" 
#include "eagle.h" 
#include "broomstick.h" 
#include "ground_race.h" 
#include "air_race.h" 
#include "race_for_everyone.h"


void sort_pairs(std::vector<double>&, std::vector<int>& party);
bool check(std::vector<int> party, int choice_player);
bool quantity(std::vector<int> party);

int main() {
	std::vector<std::string> for_reg{ "", "Ботинки вездеходы", "Метла", "Верблюд", "Кентавр", "Орел", "Верблюд-быстроход", "Ковер-самолет" }; // просто чтобы было
	std::vector<int>party; // участники гонки
	std::vector<double> overcome_time;
	double distance = 0;
	int choice_race = 0, choice_reg = 0, count = 0, out = 0;
	int choice_player = 0;
	std::cout << "Добро пожаловть в гоночный симулятор!" << std::endl;
	do {
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
		else if (choice_race == 2) {
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