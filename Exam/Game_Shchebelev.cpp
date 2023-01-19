#include "Game_Shchebelev.h"

Game_Shchebelev::Game_Shchebelev()
{
	this->year = 1;
	this->phase = 1;
}

Game_Shchebelev::~Game_Shchebelev()
{
}

Game_Shchebelev::Game_Shchebelev(int Gamers_count)
{
	this->year = 1;
	this->phase = 1;
	for (int i = 0; i < Gamers_count; i++)
	{
		this->Gamers.push_back(Game_Shchebelevr());
		std::cout << "Name >> ";
		std::cin >> this->Gamers[i].name;
		this->Gamers[i].has_additional_cube = false;
		this->Gamers[i].building_tokens = 17;
		this->Gamers[i].has_adviser = false;
		this->Gamers[i].military_register = 0;
		this->Gamers[i].victory_points = 0;
	}
	this->advisers.push_back({ "Jester", "" }); 
	this->advisers.push_back({ "Squire", "" }); 
	this->advisers.push_back({ "Architect", "" }); 
	this->advisers.push_back({ "Merchant", "" }); 
	this->advisers.push_back({ "Sergeant", "" }); 
	this->advisers.push_back({ "Alchemist", "" }); 
	this->advisers.push_back({ "Astrologer", "" }); 
	this->advisers.push_back({ "Treasurer", "" }); 
	this->advisers.push_back({ "Huntress", "" }); 
	this->advisers.push_back({ "General", "" }); 
	this->advisers.push_back({ "Gunsmith", "" }); 
	this->advisers.push_back({ "Duchess", "" }); 
	this->advisers.push_back({ "Hero", "" }); 
	this->advisers.push_back({ "Smuggler", "" }); 
	this->advisers.push_back({ "Inventor", "" }); 
	this->advisers.push_back({ "Wizard", "" }); 
	this->advisers.push_back({ "Queen", "" }); 
	this->advisers.push_back({ "King", "" }); 
}

Game_Shchebelev::Game_Shchebelev(const Game_Shchebelev& c_Game_Shchebelev)
{
	for (int i = 0; i < c_Game_Shchebelev.Gamers.size(); i++)
	{
		if (this->Gamers.size() < i + 1) 
			this->Gamers.push_back(c_Game_Shchebelev.Gamers[i]);
		else
			this->Gamers[i] = c_Game_Shchebelev.Gamers[i];
	}
	for (int i = 0; i < 18; i++)
	{
		if (this->advisers.size() < i + 1)
			this->advisers.push_back(c_Game_Shchebelev.advisers[i]);
		else
			this->advisers[i] = c_Game_Shchebelev.advisers[i];
	}
	this->year = c_Game_Shchebelev.year;
	this->phase = c_Game_Shchebelev.phase;
	this->enemy = c_Game_Shchebelev.enemy;
}

void Game_Shchebelev::phase1()
{
	std::cout << "##### Year " << this->year << " Phase 1. Help of the king ######" << std::endl;
	if (this->year == 1 && this->phase == 1) {
		for (int i = 0; i < this->Gamers.size(); i++)
		{
			std::string product;
			std::cout << "Game_Shchebelevr " << this->Gamers[i].name << ", choose your product: gold/wood/stone" << std::endl;
			std::cin >> product;
			if (product == "gold") this->Gamers[i].gold++;
			else if (product == "wood") this->Gamers[i].wood++;
			else if (product == "stone") this->Gamers[i].stone++;
		}
	}
	else
	{
		std::vector<Game_Shchebelevr> candidates;
		int min_buildings = this->Gamers[0].buildings.size();
		for (auto g : this->Gamers)
		{
			if (g.buildings.size() < min_buildings)
			{
				min_buildings = g.buildings.size();
				candidates.clear();
				candidates.push_back(g);
			}
			else if (g.buildings.size() == min_buildings)
			{
				candidates.push_back(g);
			}
		}
		if (candidates.size() == 1)
		{
			for (int i = 0; i < this->Gamers.size(); i++)
				if (this->Gamers[i].name == candidates[0].name) this->Gamers[i].has_additional_cube = true;
		}
		else {
			std::vector<Game_Shchebelevr> new_candidates;
			int count = 0;
			int sum_min = candidates[0].gold + candidates[0].wood + candidates[0].stone;
			for (auto c : candidates)
			{
				int sum_p = c.gold + c.wood + c.stone;
				if (sum_p < sum_min)
				{
					sum_min = c.gold + c.wood + c.stone;
					new_candidates.clear();
					new_candidates.push_back(c);
				}
				else if (sum_min == sum_p) new_candidates.push_back(c);
			}
			if (count == 1)
			{
				for (int i = 0; i < this->Gamers.size(); i++)
					if (this->Gamers[i].name == new_candidates[0].name) this->Gamers[i].has_additional_cube = true;
			}
			else
			{
				for (int i = 0; i < this->Gamers.size(); i++)
				{
					for (auto nc : new_candidates)
						if (nc.name == this->Gamers[i].name)
						{
							std::string product;
							std::cout << "Game_Shchebelevr " << this->Gamers[i].name << ", choose your product: gold/wood/stone";
							std::cin >> product;
							if (product == "gold") this->Gamers[i].gold++;
							else if (product == "wood") this->Gamers[i].wood++;
							else if (product == "stone") this->Gamers[i].stone++;
						}
				}
			}
		}
	}
}

void Game_Shchebelev::phase3()
{
	std::cout << "##### Year " << this->year << " Phase 3. Royal award ######" << std::endl;
	std::vector<Game_Shchebelevr> candidates;
	int max_buildings = this->Gamers[0].buildings.size();
	for (auto g : this->Gamers)
	{
		if (g.buildings.size() > max_buildings)
		{
			max_buildings = g.buildings.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.buildings.size() == max_buildings) candidates.push_back(g);
	}
	for (int i = 0; i < this->Gamers.size(); i++)
	{
		for (auto c : candidates)
		{
			if (this->Gamers[i].name == c.name)
			{
				std::cout << "Game_Shchebelevr " << c.name << " receives victory point" << std::endl;
				this->Gamers[i].victory_points++;
			}
		}
	}
}

void Game_Shchebelev::phase5()
{
	std::cout << "##### Year " << this->year << " Phase 5. Royal envoy ######" << std::endl;
	std::vector<Gamer> candidates;
	int min_buildings = this->Gamers[0].buildings.size();
	for (auto g : this->Gamers)
	{
		if (g.buildings.size() < min_buildings)
		{
			min_buildings = g.buildings.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.buildings.size() == min_buildings)
		{
			candidates.push_back(g);
		}
	}
	if (candidates.size() == 1)
	{
		for (int i = 0; i < this->Gamers.size(); i++)
			if (this->Gamers[i].name == candidates[0].name) this->Gamers[i].has_adviser = true;
	}
	else {
		std::vector<Gamer> new_candidates;
		int count = 0;
		int sum_min = candidates[0].gold + candidates[0].wood + candidates[0].stone;
		for (auto c : candidates)
		{
			int sum_p = c.gold + c.wood + c.stone;
			if (sum_p < sum_min)
			{
				sum_min = c.gold + c.wood + c.stone;
				new_candidates.clear();
				new_candidates.push_back(c);
			}
			else if (sum_min == sum_p) new_candidates.push_back(c);
		}
		if (count == 1)
		{
			for (int i = 0; i < this->Gamers.size(); i++)
				if (this->Gamers[i].name == new_candidates[0].name) this->Games[i].has_adviser = true;
		}
	}
	for (auto g : this->Gamers) std::cout << "Gamer " << g.name << " now has royal envoy" << std::endl;
}

void Game_Shchebelev::phase7()
{
	std::cout << "##### Year " << this->year << " Phase 3. Hiring warriors ######" << std::endl;

}

void Game_Shchebelev::phase8()
{

}


