#include "game_Shchebelev.h"
#include <iostream>
#include <fstream>
#include <string>

Game_Shchebelev::Game_Shchebelev()
{
	this->year = 1;
	this->phase = 1;
}

Game_Shchebelev::Game_Shchebelev(int gamers_count)
{
	this->year = 1;
	this->phase = 1;
	for (int i = 0; i < gamers_count; i++)
	{
		this->gamers.push_back(Gamer());
		std::cout « "Name » ";
		std::cin » this->gamers[i].name;
		this->gamers[i].has_additional_cube = false;
		this->gamers[i].building_tokens = 17;
		this->gamers[i].has_adviser = false;
		this->gamers[i].military_register = 0;
		this->gamers[i].victory_points = 0;
	}
	this->advisers.push_back({ "Jester", "" }); // шут
	this->advisers.push_back({ "Squire", "" }); // сквайр
	this->advisers.push_back({ "Architect", "" }); // зодчий
	this->advisers.push_back({ "Merchant", "" }); // купец
	this->advisers.push_back({ "Sergeant", "" }); // сержант
	this->advisers.push_back({ "Alchemist", "" }); // алхимик
	this->advisers.push_back({ "Astrologer", "" }); // звездочёт
	this->advisers.push_back({ "Treasurer", "" }); // казначей
	this->advisers.push_back({ "Huntress", "" }); // охотница
	this->advisers.push_back({ "General", "" }); // генерал
	this->advisers.push_back({ "Gunsmith", "" }); // оружейник
	this->advisers.push_back({ "Duchess", "" }); // герцогиня
	this->advisers.push_back({ "Hero", "" }); // герой
	this->advisers.push_back({ "Smuggler", "" }); // контрабандист
	this->advisers.push_back({ "Inventor", "" }); // изобретатель
	this->advisers.push_back({ "Wizard", "" }); // волшебник
	this->advisers.push_back({ "Queen", "" }); // королева
	this->advisers.push_back({ "King", "" }); // король
}

Game_Shchebelev::Game_Shchebelev(const Game_Shchebelev& c_game)
{
	// копирование игроков
	for (int i = 0; i < c_game.gamers.size(); i++)
	{
		if (this->gamers.size() < i + 1) // если это новый объект
			this->gamers.push_back(c_game.gamers[i]);
		else // если существуюший
			this->gamers[i] = c_game.gamers[i];
	}
	// копирование советников
	for (int i = 0; i < 18; i++)
	{
		if (this->advisers.size() < i + 1)
			this->advisers.push_back(c_game.advisers[i]);
		else
			this->advisers[i] = c_game.advisers[i];
	}
	this->year = c_game.year;
	this->phase = c_game.phase;
	this->enemy = c_game.enemy;
}

Game_Shchebelev::~Game_Shchebelev()
{
}

void Game_Shchebelev::phase1()
{
	std::cout « "##### Year " « this->year « " Phase 1. Help of the king ######" « std::endl;
	if (this->year == 1 && this->phase == 1) {
		// на первой фазе выбираем только товар
		for (int i = 0; i < this->gamers.size(); i++)
		{
			std::string product;
			std::cout « "gamers " « this->gamers[i].name « ", choose your product: gold/wood/stone" « std::endl;
			std::cin » product;
			if (product == "gold") this->gamers[i].gold++;
			else if (product == "wood") this->gamers[i].wood++;
			else if (product == "stone") this->gamers[i].stone++;
		}
	}
	else
	{
		// выбираем по меньшему количеству зданий
		std::vector<Gamer> candidates;
		int min_buildings = this->gamers[0].buildings.size();
		for (auto g : this->gamers)
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
		// если кандидат один
		if (candidates.size() == 1)
		{
			for (int i = 0; i < this->gamers.size(); i++)
				if (this->gamers[i].name == candidates[0].name) this->gamers[i].has_additional_cube = true;
		}
		// если их несколько то сравниваем по сумме товаров
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
			// если нашёлся кандидат
			if
				(count == 1)
			{
				for (int i = 0; i < this->gamers.size(); i++)
					if (this->gamers[i].name == new_candidates[0].name) this->gamers[i].has_additional_cube = true;
			}
			else
			{
				// если их несколько то выдаём товары всем
				for (int i = 0; i < this->gamers.size(); i++)
				{
					for (auto nc : new_candidates)
						if (nc.name == this->gamers[i].name)
						{
							std::string product;
							std::cout « "gamers " « this->gamers[i].name « ", choose your product: gold/wood/stone";
							std::cin » product;
							if (product == "gold") this->gamers[i].gold++;
							else if (product == "wood") this->gamers[i].wood++;
							else if (product == "stone") this->gamers[i].stone++;
						}
				}
			}
		}
	};

	void Game_Shchebelev::phase3() {
		// выдаём ПО тем у кого больше всего зданий
		std::cout « "##### Year " « this->year « " Phase 3. Royal award ######" « std::endl;
		std::vector<Gamer> candidates;
		int max_buildings = this->gamers[0].buildings.size();
		// поиск кандидатов
		for (auto g : this->gamers)
		{
			if (g.buildings.size() > max_buildings)
			{
				max_buildings = g.buildings.size();
				candidates.clear();
				candidates.push_back(g);
			}
			else if (g.buildings.size() == max_buildings) candidates.push_back(g);
		}
		// начисление очков
		for (int i = 0; i < this->gamers.size(); i++)
		{
			for (auto c : candidates)
			{
				if (this->gamers[i].name == c.name)
				{
					std::cout « "gamers " « c.name « " receives victory point" « std::endl;
					this->gamers[i].victory_points++;
				}
			}
		}
	}

	void Game_Shchebelev::phase5()
	{
		// королевский посланник
		std::cout « "##### Year " « this->year « " Phase 5. Royal envoy ######" « std::endl;
		// выбираем по меньшему количеству зданий
		std::vector<gamers> candidates;
		int min_buildings = this->gamers[0].buildings.size();
		for (auto g : this->gamers)
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
		// если кандидат один
		if (candidates.size() == 1)
		{
			for (int i = 0; i < this->gamers.size(); i++)
				if (this->gamers[i].name == candidates[0].name) this->gamers[i].has_adviser = true;
		}
		// если их несколько то сравниваем по сумме товаров
		else {
			std::vector<gamers> new_candidates;
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
			// если нашёлся кандидат
			if (count == 1)
			{
				for (int i = 0; i < this->gamers.size(); i++)
					if (this->gamers[i].name == new_candidates[0].name) this->gamers[i].has_adviser = true;
			}
		}
		for (auto g : this->gamers) std::cout « "gamers " « g.name « " now has royal envoy" « std::endl;
	}


	void Game_Shchebelev::phase7() {

	}

	void Game_Shchebelev::phase8() {

	}

	void Game_Shchebelev::phase246_adviser()
	{
		std::cout « "##### Year " « year « " Phase 2/4/6 ######" « std::endl;

		for (j = 0; j < 3; j++)
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (adviser[gamer[i].cube_1].gamer_name == "0" && gamer[i].cube_1 != 0)
				{
					adviser[gamer[i].cube_1].gamer_name == gamer[i].name;
					gamer[i].cube_1 = 0;
				}
				else if (adviser[gamer[i].cube_2].gamer_name == "0" && gamer[i].cube_2 != 0)
				{
					adviser[gamer[i].cube_2].gamer_name == gamer[i].name;
					gamer[i].cube_2 = 0;
				}
				else if (adviser[gamer[i].cube_3].gamer_name == "0" && gamer[i].cube_3 != 0)
				{
					adviser[gamer[i].cube_3].gamer_name == gamer[i].name;
					gamer[i].cube_3 = 0;
				}
				else if (adviser[gamer[i].cube_2 + gamer[i].cube_1].gamer_name == "0" && (gamer[i].cube_1 + gamer[i].cube_2) != 0)
				{
					adviser[gamer[i].cube_1 + gamer[i].cube_2].gamer_name == gamer[i].name;
					gamer[i].cube_1 = 0;
					gamer[i].cube_2 = 0;
				}
				else if (adviser[gamer[i].cube_3 + gamer[i].cube_1].gamer_name == "0" && (gamer[i].cube_2 + gamer[i].cube_1) != 0)
				{
					adviser[gamer[i].cube_3 + gamer[i].cube_1].gamer_name == gamer[i].name;
					gamer[i].cube_1 = 0;
					gamer[i].cube_3 = 0;
				}
				else if (adviser[gamer[i].cube_2 + gamer[i].cube_3].gamer_name == "0" && (gamer[i].cube_2 + gamer[i].cube_1) != 0)
				{
					adviser[gamer[i].cube_2 + gamer[i].cube_3].gamer_name == gamer[i].name;
					gamer[i].cube_2 = 0;
					gamer[i].cube_3 = 0;
				}
				else if (adviser[gamer[i].cube_2 + gamer[i].cube_1 + gamer[i].cube_3].gamer_name == "0" && (gamer[i].cube_2 + gamer[i].cube_1 + gamer[i].cube_3) != 0)
				{
					adviser[gamer[i].cube_1 + gamer[i].cube_2 + gamer[i].cube_3].gamer_name == gamer[i].name;
					gamer[i].cube_1 = 0;
					gamer[i].cube_2 = 0;
					gamer[i].cube_3 = 0;
				}
			}
		}
	}

	void Game_Shchebelev::adviser_help(Gamer & gamers, Adviser & advisers)
	{
		int j;
		if (adviser[0].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == advisers[0].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[0].advisers_name « " gived " « advisers[0].gamers_name « " 1 vp" « std::endl;

			gamers[j].victory_points++;
		}
		else if (adviser[1].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == advisers[1].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « advisers[1].advisers_name « " gived " « advisers[1].gamers_name « " 1 gold" « std::endl;

			gamers[j].gold++;
		}
		else if (adviser[2].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[2].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[2].advisers_name « " gived " « advisers[2].gamers_name « " 1 wood" « std::endl;

			gamers[j].wood++;
		}
		else if (adviser[3].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[3].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[3].advisers_name « " gived " « adviser[3].gamers_name « " 1 gold or 1 wood" « std::endl;

			std::cout « "gold?";
			std::string s;
			std::cin » s;
			if (s == "yes") gamers[j].gold++;
			else gamers[j].wood++;
		}
		else if (adviser[4].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[4].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[4].advisers_name « " gived " « adviser[4].gamers_name « " 1 milit" « std::endl;

			gamers[j].military_register++;
		}
		else if (adviser[5].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[5].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[5].advisers_name « " gived " « adviser[5].gamers_name « " 2 another resourse by your 1" « std::endl;

			std::cout « "What you wanna give?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold -= 2;
			else if (s == "wood") gamers[j].wood -= 2;
			else if (s == "stone") gamers[j].stone -= 2;
			gamers[j].gold++;
			gamers[j].wood++;
			gamers[j].stone++;
		}
		else if (adviser[6].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[6].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[6].advisers_name « " gived " « adviser[6].gamers_name « " 1 resourse and 1 token" « std::endl;

			std::cout « "What you wanna have?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;
		}
		else if (adviser[7].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if
					(gamers[i].name == adviser[7].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[7].advisers_name « " gived " « adviser[7].gamers_name « " 2 gold" « std::endl;

			gamers[j].gold += 2;
		}
		else if (adviser[8].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[8].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[8].advisers_name « " gived " « adviser[8].gamers_name « " 1 wood and 1 gold or 1 wood and 1 stone" « std::endl;

			std::cout « "What you wanna have?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "stone") gamers[j].stone++;
			gamers[j].wood++;
		}
		else if (adviser[9].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[9].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[9].advisers_name « " gived " « adviser[9].gamers_name « " 2 militar and see the hightest enemy" « std::endl;

			gamers[j].military_register += 2;
			//watch enemy
		}
		else if (adviser[10].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[10].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[10].advisers_name « " gived " « adviser[10].gamers_name « " 1 stone and 1 wood or 1 stone and 1 gold" « std::endl;

			std::cout « "What you wanna have?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			gamers[j].stone++;
		}
		else if (adviser[11].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[11].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[11].advisers_name « " gived " « adviser[11].gamers_name « " 2 resourses and 1 token" « std::endl;

			std::cout « "What you wanna have?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;

			std::cout « "What you wanna have?";
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;

			gamers[j].token++;
		}
		else if (adviser[12].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[12].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[12].advisers_name « " gived " « adviser[12].gamers_name « " 3 stone" « std::endl;

			gamers[j].stone += 3;
		}
		else if (adviser[13].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[13].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[13].advisers_name « " gived " « adviser[13].gamers_name « " - 1 vp for 3 resourses" « std::endl;

			gamers[j].victory_points —;

			std::cout « "What you wanna have?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;

			std::cout « "What you wanna have?";
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;

			std::cout « "What you wanna have?";
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;
		}
		else if (adviser[14].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[14].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[14].advisers_name « " gived " « adviser[14].gamers_name « " 1 gold 1 wood 1 stone" « std::endl;

			gamers[j].gold++;
			gamers[j].wood++;
			gamers[j].stone++;
		}
		else if
			(adviser[15].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[15].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[15].advisers_name « " gived " « adviser[15].gamers_name « " 4 gold" « std::endl;

			gamers.gold += 4;
		}
		else if (adviser[16].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[16].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[16].advisers_name « " gived " « adviser[16].gamers_name « " 2 resourses and see the hightest enemy and 3 vp" « std::endl;

			std::cout « "What you wanna have?";
			std::string s;
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;

			std::cout « "What you wanna have?";
			std::cin » s;
			if (s == "gold") gamers[j].gold++;
			else if (s == "wood") gamers[j].wood++;
			else if (s == "stone") gamers[j].stone++;

			gamers[j].victory_points += 3;

			//watch enemy
		}
		else if (adviser[17].gamers_name != "0")
		{
			for (int i = 0; i < gamers.size; i++)
			{
				if (gamers[i].name == adviser[17].gamers_name)
				{
					j = i;
					continue;
				}
			}
			std::cout « "The " « adviser[17].advisers_name « " gived " « adviser[17].gamers_name « " 1 gold 1 stone 1 wood and 1 military" « std::endl;

			gamers[j].gold++;
			gamers[j].wood++;
			gamers[j].stone++;
			gamers[j].military_register++;
		}