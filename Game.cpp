#include <iostream>
#include "Pair.h"
#include "Game.h"

using namespace std;

	Game::Game(char** board, int size, int win)
	{
		this->board = board;
		this->size = size;
		this->win = win;
	}
	Game::Game(const Game &other)
	{
		this->board = other.board;
		this->size = other.size;
		this->win = other.win;
	}
	Game::Game(int size, int win)
	{
		board = new char*[size];
		for (int i = 0; i < size; i++)
		{
			board[i] = new char[size];
		}
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				board[i][j] = '-';
		this->size = size;
		this->win = win;
	}

	int Game::Get_size()
	{
		return this->size;
	}

	char** Game::Get_board()
	{
		return this->board;
	}

	int Game::Get_win()
	{
		return this->win;
	}

	char Game::_check(char player)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				int to_win = 0;
				if (board[i][j] == player)
				{
					to_win = 0;
					for (int k = win - 1; k >= -(win - 1); k--)
					{
						if ((i - k >= 0) && (i - k < size))
						{
							if (board[i - k][j] != player)
							{
								to_win = 0;
								continue;
							}
							to_win++;
						}
						else
							to_win = 0;
						if (to_win == win)
							return player;
					}
					to_win = 0;
					for (int k = win - 1; k >= -(win - 1); k--)
					{
						if ((j - k >= 0) && (j - k < size))
						{
							if (board[i][j - k] != player)
							{
								to_win = 0;
								continue;
							}
							to_win++;
						}
						else
							to_win = 0;
						if (to_win == win)
							return player;
					}
					to_win = 0;

					int z = win - 1;
					while (z >= -2)
					{
						if ((j + z < size) && (i - z >= 0) && (i - z < size) && (j + z >= 0))
						{
							if (board[i - z][j + z] != player)
							{
								to_win = 0;
								z--;
								continue;
							}
							to_win++;

						}
						else
							to_win = 0;
						z--;
						if (to_win == win)
							return player;
					}
					z = win - 1;
					while (z >= -2)
					{
						if ((j - z < size) && (i - z >= 0) && (i - z < size) && (j - z >= 0))
						{
							if (board[i - z][j - z] != player)
							{
								to_win = 0;
								z--;
								continue;
							}
							to_win++;
						}
						else
							to_win = 0;
						z--;
						if (to_win == win)
							return player;
					}
				}
			}
		return '-';
	}

	char Game::check()
	{
		char result = _check('x');
		if (result == 'x')
			return result;
		result = _check('o');
		if (result == 'o')
			return result;
		return '-';
	}

	void Game::make_move(char player)
	{
		while (true)
		{
			int i, j;
			while (true)
			{
				cout << "Enter number of string:";
				cin >> i;
				if (!cin || i < 0 || i >= size)
				{
					cout << "Error\n";
					cin.clear();
					while (cin.get() != '\n');
				}
				else
					break;
			}
			while (true)
			{
				cout << "Enter number of column:";
				cin >> j;
				if (!cin || i < 0 || i >= size)
				{
					cout << "Error\n";
					cin.clear();
					while (cin.get() != '\n');
				}
				else
					break;
			}
			if (board[i][j] == '-')
			{
				board[i][j] = player;
				char w = check();
				break;
			}
			else
			{
				cout << "Try other move\n";
				continue;
			}

		}
	}

	bool Game::is_full()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (board[i][j] == '-')
					return false;
		return true;
	}