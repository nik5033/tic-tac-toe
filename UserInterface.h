#include <iostream>
#include <cstdlib>
#include "AI.h"

using namespace std;

class UserInterface
{
public:
	void Show_board(Game game);
	char make_game(Game game, AI ai);
	char _cin_char();
	int _cin();
	void consol();
};