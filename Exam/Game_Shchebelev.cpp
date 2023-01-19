#include "Game_Shchebelev.h"

Game_Shchebelev::Game_Shchebelev()
{
	this->year = 1;
	this->phase = 1;
}

Game_Shchebelev::~Game_Shchebelev()
{
}

// ���������������� �����������
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
	this->advisers.push_back({ "Jester", "" }); // ���
	this->advisers.push_back({ "Squire", "" }); // ������
	this->advisers.push_back({ "Architect", "" }); // ������
	this->advisers.push_back({ "Merchant", "" }); // �����
	this->advisers.push_back({ "Sergeant", "" }); // �������
	this->advisers.push_back({ "Alchemist", "" }); // �������
	this->advisers.push_back({ "Astrologer", "" }); // ���������
	this->advisers.push_back({ "Treasurer", "" }); // ��������
	this->advisers.push_back({ "Huntress", "" }); // ��������
	this->advisers.push_back({ "General", "" }); // �������
	this->advisers.push_back({ "Gunsmith", "" }); // ���������
	this->advisers.push_back({ "Duchess", "" }); // ���������
	this->advisers.push_back({ "Hero", "" }); // �����
	this->advisers.push_back({ "Smuggler", "" }); // �������������
	this->advisers.push_back({ "Inventor", "" }); // ������������
	this->advisers.push_back({ "Wizard", "" }); // ���������
	this->advisers.push_back({ "Queen", "" }); // ��������
	this->advisers.push_back({ "King", "" }); // ������
}

// ���������� �����������
Game_Shchebelev::Game_Shchebelev(const Game_Shchebelev& c_Game_Shchebelev)
{
	// ����������� �������
	for (int i = 0; i < c_Game_Shchebelev.Game_Shchebelevrs.size(); i++)
	{
		if (this->Game_Shchebelevrs.size() < i + 1) // ���� ��� ����� ������
			this->Game_Shchebelevrs.push_back(c_Game_Shchebelev.Game_Shchebelevrs[i]);
		else // ���� ������������
			this->Game_Shchebelevrs[i] = c_Game_Shchebelev.Game_Shchebelevrs[i];
	}
	// ����������� ����������
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
		// �� ������ ���� �������� ������ �����
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
		// �������� �� �������� ���������� ������
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
		// ���� �������� ����
		if (candidates.size() == 1)
		{
			for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
				if (this->Game_Shchebelevrs[i].name == candidates[0].name) this->Game_Shchebelevrs[i].has_additional_cube = true;
		}
		// ���� �� ��������� �� ���������� �� ����� �������
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
			// ���� ������� ��������
			if (count == 1)
			{
				for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
					if (this->Game_Shchebelevrs[i].name == new_candidates[0].name) this->Game_Shchebelevrs[i].has_additional_cube = true;
			}
			else
			{
				// ���� �� ��������� �� ����� ������ ����
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
	// ����� �� ��� � ���� ������ ����� ������
	std::cout << "##### Year " << this->year << " Phase 3. Royal award ######" << std::endl;
	std::vector<Game_Shchebelevr> candidates;
	int max_buildings = this->Game_Shchebelevrs[0].buildings.size();
	// ����� ����������
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
	// ���������� �����
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
	// ����������� ���������
	std::cout << "##### Year " << this->year << " Phase 5. Royal envoy ######" << std::endl;
	// �������� �� �������� ���������� ������
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
	// ���� �������� ����
	if (candidates.size() == 1)
	{
		for (int i = 0; i < this->Game_Shchebelevrs.size(); i++)
			if (this->Game_Shchebelevrs[i].name == candidates[0].name) this->Game_Shchebelevrs[i].has_adviser = true;
	}
	// ���� �� ��������� �� ���������� �� ����� �������
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
		// ���� ������� ��������
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
	// ��� ������
	std::cout << "##### Year " << this->year << " Phase 3. Hiring warriors ######" << std::endl;

}

void Game_Shchebelev::phase8()
{

}