#ifndef AI_H
#define AI_H

#include "Pair.h"
#include "List.h"
#include "Game.h"
#include <iostream>

using namespace std;

class AI
{
private:
	char player;
	char alien;
	char XWIN = 'x';
	char OWIN = 'o';
	char DRAW = '-';
public:
	char Get_player();
	char Get_alien();
	AI(char player);
	void make_move(Game& game);
	bool defence(Game& game, Pair<int, int> move);
	bool attack(Game& game, Pair<int, int> move);
	List<Pair<int, int>>* generate_moves(Game& game, List<Pair<int, int>>* moves);
};

#endif