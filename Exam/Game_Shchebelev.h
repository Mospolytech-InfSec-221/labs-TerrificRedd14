#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

enum Building {
    Statue,
    Church,
    Cathedral,
    Inn,
    Market,
    Farm,
    TradeGuild,
    Barrack,
    Palisade,
    Stable,
    StoneWall,
    Fortress,
    Stockade,
    TownHall,
    Embassy
};

enum Resource {
    Gold,
    Wood,
    Rock,
    Token,
    Cube1,
    Cube2,
    Cube3,
    AdditionalCube,
};

struct Player {
    string name;
    bool counsellor = false;

    int fight_registry = 0;
    int points = 0;

    vector<Resource> resources;
    vector<Building> buildings;
};

struct Counsellor {
    string name;
    string player_name;
};

class Game_Shchebelev {
    stack<Player> players;
    vector<Counsellor> counsellors;

    int year = 1;
    int phase = 0;
    string enemy_name; 

public:
    Game_Shchebelev(); 
    Game_Shchebelev(int num);
    Game_Shchebelev(const Game_Shchebelev& game);

    ~Game_Shchebelev() = default;

    
    void phase1();
    void phase2();
    void phase3();
    void phase4();
    void phase5();
    void phase6();
    void phase7();
    void phase8();

    void defense_level(const char* enemy_name, int king_help, Player& player);
};
