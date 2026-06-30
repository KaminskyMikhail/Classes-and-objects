#include <iostream>
#include <vector>
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
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class airborne_vehicles : public vehicles {
protected:
	double coefficient_reduction_speed; // коэффициент снижения скорости
public:
	airborne_vehicles(double coefficient_reduction_speed, double speed, std::string name) : coefficient_reduction_speed(coefficient_reduction_speed), vehicles(speed, name){}

};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class camel : public ground_vehicles {
public:
	camel(double speed, double travel_to_relax, double relax_time, std::string name) : ground_vehicles(travel_to_relax, relax_time, speed, name){}

	virtual get_ground_vehicles get_val(){
		return { name, speed, travel_to_relax, relax_time };
	}

	void set_val(const get_ground_vehicles& data) {
		name = data.name;
		speed = data.speed;
		travel_to_relax = data.travel_to_relax;
		relax_time = data.relax_time;
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
	racing_camel player2{40, 10, 5, "Racing camel"};
	centaur player3{15, 8, 2, "Centaur"};
	all_terrain_boots player4{5, 60, 10, "All-terrain boots"};
	ground_vehicles* arr[4];
public:
	ground_race(double distance) : distance(distance){
		arr[1] = &player1;
		arr[2] = &player2;
		arr[3] = &player3;
		arr[4] = &player4;
	}

	void  rest_time(std::vector<int> arr, int count) { 
		auto data = player1.get_val();
		int time_player1 = distance / data.speed;
		int stops_player1 = time_player1 / 0.5 - 1;
		if (stops_player1 > 0) { data.relax_time = 5; }
		if (stops_player1 > 1){
			for (int i = 1; i < stops_player1; i++) {
				data.relax_time += 8;
			}
		}
		double final_time_camel = static_cast<double>(time_player1) + (static_cast<double>(data.relax_time / 60));
		std::cout << final_time_camel;;
	}
	
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class air_race {
private:
	flying_carpet player1{0, 10, "Flying carpet"};
	eagle player2{6, 8, "Eagle"};
	broomstick player3{0, 20, "Broomstick"};
public:


};
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class race_for_everyone {

};
//----------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	std::vector<std::string> for_reg {"", "Ботинки вездеходы", "Метла", "Верблюд", "Кентавр", "Орел", "Верблюд-быстроход", "Ковер-самолет"}; // просто чтобы было
	std::vector<int>party; // участники гонки
	double distance = 0;
	int choice_race = 0, choice_reg = 0, count = 0;
	int choice_player = 0;
	std::cout << "Добро пожаловть в гоночный симулятор!" << std::endl
		<< "1. Гонка для наземного транспорта" << std::endl
		<< "2. Гонка для воздушного транспорта" << std::endl
		<< "3. Гонка для наземного и воздушного транспорта" << std::endl
		<< "Выберите тип гонки: "; std::cin >> choice_race;
	if (choice_race == 1) 
		std::cout << "\n\nУкажите длину дистанции (должна быть положительна): "; std::cin >> distance;
		std::cout << "\n\nДолжно быть зарегистрировано хотя бы 2 транспортных средства " << std::endl
			<< "1. Зарегистрировать транспорт" << std::endl
			<< "Выберите действие : "; std::cin >> choice_reg; std::cout << "\n\n";
		//----------------------------РЕГИСТРаЦИЯ------------------------------------------------------------------
		do {
		if (choice_race == 1) {
			std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << '.' << std::endl;
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
			if (choice_player == 2 || choice_player == 5 || choice_player == 7) {
				std::cout << "\n\nПопытка зарегистрировать неверный тип транспортного средства!" << std::endl;
			}
			else if (choice_player == 3 || choice_player == 1 || choice_player == 4 || choice_player == 6) {
				party.push_back(choice_player);
				std::cout << "\n\n" << for_reg[choice_player] << " Успешно зарегистрирован!" << std::endl;
				choice_reg = 0;
				count++;
			}
			if (choice_player == 0) {
				std::cout << "\n\n1. Зарегистрировать транспорт \n2. Начать гонку \nВыберите действие: "; std::cin >> choice_player; std::cout << "\n\n";
				if (choice_player == 2) { choice_player = 0; };
			}
		} while (choice_player != 0);
		//----------------------------------------------------------------------------------------------------------

		ground_race type_1(distance);
		type_1.rest_time(party, count);


	return EXIT_SUCCESS;
}