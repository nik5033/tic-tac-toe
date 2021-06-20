#ifndef Game_H
#define Game_H

#include <iostream>
#include "Pair.h"

using namespace std;

class Game
{
private:
	char** board;
	int size;
	int win;
public:
	Game(char** board, int size, int win);
	Game(const Game &other);
	Game(int size, int win);
	int Get_size();
	char** Get_board();
	int Get_win();
	char _check(char player);
	char check();
	void make_move(char player);
	bool is_full();
};

#endif
