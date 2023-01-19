#include "Game_Shchebelev.h"

Game_Shchebelev::Game_Shchebelev()
{
	this->year = 1;
	this->phase = 1;
}

Game_Shchebelev::~Game_Shchebelev()
{
}

// инициализирующий конструктор
Game_Shchebelev::Game_Shchebelev(int Game_Shchebelevrs_count)
{
	this->year = 1;
	this->phase = 1;
	for (int i = 0; i < Game_Shchebelevrs_count; i++)
	{
		this->Game_Shchebelevrs.push_back(Game_Shchebelevr());
		std::cout << "Name >> ";
		std::cin >> this->Game_Shchebelevrs[i].name;
		this->Game_Shchebelevrs[i].has_additional_cube = false;
		this->Game_Shchebelevrs[i].building_tokens = 17;
		this->Game_Shchebelevrs[i].has_adviser = false;
		this->Game_Shchebelevrs[i].military_register = 0;
		this->Game_Shchebelevrs[i].victory_points = 0;
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

// копирующий конструктор
Game_Shchebelev::Game_Shchebelev(const Game_Shchebelev& c_Game_Shchebelev)
{
	// копирование игроков
	for (int i = 0; i < c_Game_Shchebelev.Game_Shchebelevrs.size(); i++)
	{
		if (this->Game_Shchebelevrs.size() < i + 1) // если это новый объект
			this->Game_Shchebelevrs.push_back(c_Game_Shchebelev.Game_Shchebelevrs[i]);
		else // если существуюший
			this->Game_Shchebelevrs[i] = c_Game_Shchebelev.Game_Shchebelevrs[i];
	}
	// копирование советников
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
		// на первой фазе выбираем только товар
		for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
		{
			std::string product;
			std::cout << "Game_Shchebelevr " << this->Game_Shchebelevrs[i].name << ", choose your product: gold/wood/stone" << std::endl;
			std::cin >> product;
			if (product == "gold") this->Game_Shchebelevrs[i].gold++;
			else if (product == "wood") this->Game_Shchebelevrs[i].wood++;
			else if (product == "stone") this->Game_Shchebelevrs[i].stone++;
		}
	}
	else
	{
		// выбираем по меньшему количеству зданий
		std::vector<Game_Shchebelevr> candidates;
		int min_buildings = this->Game_Shchebelevrs[0].buildings.size();
		for (auto g : this->Game_Shchebelevrs)
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
			for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
				if (this->Game_Shchebelevrs[i].name == candidates[0].name) this->Game_Shchebelevrs[i].has_additional_cube = true;
		}
		// если их несколько то сравниваем по сумме товаров
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
			// если нашёлся кандидат
			if (count == 1)
			{
				for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
					if (this->Game_Shchebelevrs[i].name == new_candidates[0].name) this->Game_Shchebelevrs[i].has_additional_cube = true;
			}
			else
			{
				// если их несколько то выдаём товары всем
				for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
				{
					for (auto nc : new_candidates)
						if (nc.name == this->Game_Shchebelevrs[i].name)
						{
							std::string product;
							std::cout << "Game_Shchebelevr " << this->Game_Shchebelevrs[i].name << ", choose your product: gold/wood/stone";
							std::cin >> product;
							if (product == "gold") this->Game_Shchebelevrs[i].gold++;
							else if (product == "wood") this->Game_Shchebelevrs[i].wood++;
							else if (product == "stone") this->Game_Shchebelevrs[i].stone++;
						}
				}
			}
		}
	}
}

void Game_Shchebelev::phase3()
{
	// выдаём ПО тем у кого больше всего зданий
	std::cout << "##### Year " << this->year << " Phase 3. Royal award ######" << std::endl;
	std::vector<Game_Shchebelevr> candidates;
	int max_buildings = this->Game_Shchebelevrs[0].buildings.size();
	// поиск кандидатов
	for (auto g : this->Game_Shchebelevrs)
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
	for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
	{
		for (auto c : candidates)
		{
			if (this->Game_Shchebelevrs[i].name == c.name)
			{
				std::cout << "Game_Shchebelevr " << c.name << " receives victory point" << std::endl;
				this->Game_Shchebelevrs[i].victory_points++;
			}
		}
	}
}

void Game_Shchebelev::phase5()
{
	// королевский посланник
	std::cout << "##### Year " << this->year << " Phase 5. Royal envoy ######" << std::endl;
	// выбираем по меньшему количеству зданий
	std::vector<Game_Shchebelevr> candidates;
	int min_buildings = this->Game_Shchebelevrs[0].buildings.size();
	for (auto g : this->Game_Shchebelevrs)
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
		for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
			if (this->Game_Shchebelevrs[i].name == candidates[0].name) this->Game_Shchebelevrs[i].has_adviser = true;
	}
	// если их несколько то сравниваем по сумме товаров
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
		// если нашёлся кандидат
		if (count == 1)
		{
			for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
				if (this->Game_Shchebelevrs[i].name == new_candidates[0].name) this->Game_Shchebelevrs[i].has_adviser = true;
		}
	}
	for (auto g : this->Game_Shchebelevrs) std::cout << "Game_Shchebelevr " << g.name << " now has royal envoy" << std::endl;
}

void Game_Shchebelev::phase7()
{
	// наём воинов
	std::cout << "##### Year " << this->year << " Phase 3. Hiring warriors ######" << std::endl;

}

void Game_Shchebelev::phase8()
{

}