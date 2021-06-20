#include "UserInterface.h"
#include <iostream>
#include <cstdlib>

using namespace std;


	void UserInterface:: Show_board(Game game)
	{
		char** board = game.Get_board();
		for (int i = 0; i < game.Get_size(); i++)
		{
			for (int j = 0; j < game.Get_size(); j++)
				cout << board[i][j] << " ";
			cout << endl;
		}
	}
	char UserInterface::make_game(Game game, AI ai)
	{
		char** board = game.Get_board();
		while (true)
		{
			system("cls");
			if (ai.Get_player() == 'x')
				ai.make_move(game);
			else
			{
				Show_board(game);
				game.make_move(ai.Get_alien());
			}
			Show_board(game);
			if (game.check() == 'x' || game.check() == 'o')
				return game.check();
			if (game.is_full())
				return '-';
			if (ai.Get_player() == 'x')
				game.make_move(ai.Get_alien());
			else
				ai.make_move(game);
			board = game.Get_board();
			cout << endl;
			if (game.check() == 'x' || game.check() == 'o')
				return game.check();
			if (game.is_full())
				return '-';
		}
	}
	char UserInterface::_cin_char()
	{
		char data;
		while (true)
		{
			cin >> data;
			cin.ignore();
			if (!cin || (data != 'x'&&data != 'o'))
			{
				cout << "Please, try input!!\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else
				break;
		}
		return data;
	}
	int UserInterface:: _cin()
	{
		int data;
		while (true)
		{
			cin >> data;
			cin.ignore();
			if (!cin)
			{
				cout << "Please, try input!!\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else
				break;
		}
		return data;
	}
	void UserInterface::consol()
	{
		cout << "Enter size of the board:";
		int size = _cin();
		system("cls");
		cout << "Winning length:";
		int win = _cin();
		system("cls");
		Game game(size, win);
		cout << "Choose:x or o:";
		char team = _cin_char();
		AI ai(team);
		system("cls");
		char result = make_game(game, ai);
		system("cls");
		Show_board(game);
		if (result == '-')
			cout << "Draw!!!\n";
		else
			cout << game.check() << " is win!!!\n";
	}
