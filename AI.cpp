#include "Pair.h"
#include "List.h"
#include "Game.h"
#include <iostream>
#include "AI.h"

using namespace std;
char AI::Get_player()
{
	return this->player;
}
char AI::Get_alien()
{
	return this->alien;
}
	AI::AI(char alien)
	{
		this->alien =alien;
		if (alien == XWIN)
			this->player= OWIN;
		else
			this->player = XWIN;
	}

	void AI::make_move(Game& game)
	{
		List<Pair<int, int>>* move_list = new List<Pair<int, int>>;
		move_list = generate_moves(game, move_list);
		char** board = game.Get_board();
		int iter = move_list->Get_length();
		Pair<int, int> pair;
		while (iter != 0)
		{
			pair = move_list->GetLast();
			if (attack(game, pair))
			{
				int i = pair.Get_first();
				int j = pair.Get_second();
				board[i][j] = player;
				return;
			}
			move_list->Prepend(move_list->pop_last());
			iter--;
		}
		iter = move_list->Get_length();
		while (iter != 0)
		{
			pair = move_list->GetLast();
			if (defence(game, pair))
			{
				int i = pair.Get_first();
				int j = pair.Get_second();
				board[i][j] = player;
				return;
			}
			move_list->Prepend(move_list->pop_last());
			iter--;
		}
		pair = move_list->Get(0);
		int i = pair.Get_first();
		int j = pair.Get_second();
		board[i][j] = player;
	}
	bool AI::defence(Game& game, Pair<int, int> move)
	{
		char** board = new char*[game.Get_size()];
		for (int i = 0; i < game.Get_size(); i++)
		{
			board[i] = new char[game.Get_size()];
		}
		for (int i = 0; i < game.Get_size(); i++)
			for (int j = 0; j < game.Get_size(); j++)
				board[i][j] = game.Get_board()[i][j];
		board[move.Get_first()][move.Get_second()] = alien;
		Game other(board, game.Get_size(), game.Get_win());
		if (other.check() == alien)
			return true;
		else
			return false;
	}
	bool AI::attack(Game& game, Pair<int, int> move)
	{
		char** board = new char*[game.Get_size()];
		for (int i = 0; i < game.Get_size(); i++)
		{
			board[i] = new char[game.Get_size()];
		}
		for (int i = 0; i < game.Get_size(); i++)
			for (int j = 0; j < game.Get_size(); j++)
				board[i][j] = game.Get_board()[i][j];
		board[move.Get_first()][move.Get_second()] = player;
		Game other(board, game.Get_size(), game.Get_win());
		if (other.check() == player)
			return true;
		else
			return false;
	}

	List<Pair<int, int>>* AI::generate_moves(Game& game, List<Pair<int, int>>* moves)
	{
		int size = game.Get_size();
		char** _board = game.Get_board();
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (_board[i][j] == '-')
				{
					Pair<int, int> move(i, j);
					moves->Append(move);
				}
		return moves;
	}