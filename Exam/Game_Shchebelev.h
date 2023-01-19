#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef struct Game_Shchebelevr {
	std::string name;
	int gold;
	int wood;
	int stone;
	int cube_1;
	int cube_2;
	int cube_3;
	bool has_additional_cube; 
	int additional_cude;
	int building_tokens; 
	bool has_adviser;
	int military_register; 
	int victory_points; 
	std::vector<std::string> buildings; 

} Game_Shchebelevr;

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

