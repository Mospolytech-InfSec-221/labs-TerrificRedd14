#include "Game_Shchebelev.h"

Game_Shchebelev::Game_Shchebelev(int num) {
    for (int i = 0; i < num; i++)
        this->players.push(Player{});
}

Game_Shchebelev::Game_Shchebelev() : Game_Shchebelev(2) {}

Game_Shchebelev::Game_Shchebelev(const Game_Shchebelev& game) {
    this->phase = game.phase;
    this->year = game.year;
    this->enemy_name = game.enemy_name;
    this->counsellors = game.counsellors;
    this->players = game.players;
}

void Game_Shchebelev::phase1() {
    // some code here
}

void Game_Shchebelev::phase3() {
    // some code here
}

void Game_Shchebelev::phase5() {
    // some code here
}

void Game_Shchebelev::phase7() {
    // some code here
}

void Game_Shchebelev::phase8() {
    // some code here
}

void Game_Shchebelev::defense_level(const char* enemy_name, int king_help, Player& player) {

}