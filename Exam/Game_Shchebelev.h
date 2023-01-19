#pragma once
#include <iostream>
#include <vector>
#include <string>

// Характеристики игрока
typedef struct Game_Shchebelevr {
	std::string name;
	int gold;
	int wood;
	int stone;
	int cube_1;
	int cube_2;
	int cube_3;
	bool has_additional_cube; // доп. кубик
	int additional_cude; // доп. кубик
	int building_tokens; // жетоны зданий
	bool has_adviser; // советник
	int military_register; // значение воинского реестра
	int victory_points; // победные очки
	std::vector<std::string> buildings; // вектор построек

} Game_Shchebelevr;

// советник и занявший его игрок
typedef struct Adviser {
	std::string adviser_name;
	std::string Game_Shchebelevr_name;
	Adviser(std::string a_name, std::string g_name)
	{
		this->adviser_name = a_name;
		this->Game_Shchebelevr_name = g_name;
	}
} Adviser;

class Game_Shchebelev
{
private:
	std::vector<Game_Shchebelevr> Game_Shchebelevrs;
	std::vector<Adviser> advisers;
	int year;
	int phase;
	std::string enemy;
public:
	Game_Shchebelev();
	~Game_Shchebelev();
	Game_Shchebelev(int Game_Shchebelevrs_count);
	Game_Shchebelev(const Game_Shchebelev&);

	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
};

