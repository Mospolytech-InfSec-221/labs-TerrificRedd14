#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef struct Gamer {
	std::string name;
	int move;
	int gold;
	int wood;
	int stone;
	int cube_1;
	int cube_2;
	int cube_3;
	bool has_additional_cube;
	int additional_cube;
	int building_tokens;
	int tokens;
	bool has_adviser;
	int military_register;
	int victory_points;
	std::vector<std::string> buildings;

} Gamer;

typedef struct Adviser {
	std::string adviser_name;
	std::string Gamer_name;
	Adviser(std::string a_name, std::string g_name)
	{
		adviser_name = a_name;
		Gamer_name = g_name;
	}
} Adviser;

class Game_Shchebelev
{
private:
	std::vector<Gamer> Gamers;
	std::vector<Adviser> advisers;
	int year;
	int phase;
	std::string enemy;
public:
	Game_Shchebelev();
	~Game_Shchebelev();
	Game_Shchebelev(int Gamers_count);
	Game_Shchebelev(const Game_Shchebelev&);

	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();

	void phase246();
	void phase246_bones();
	void phase246_advisor();
};

