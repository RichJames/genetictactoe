#include "gamestate.h"
#include <iostream>
#include <vector>

using namespace std;


/*
 * InArray tries to determine if 'game' is already in the array, 'gamearray'.
 * A game is considered in the array if some combination of rotation and flipping
 * will cause it to match an entry already in the array.  The tic tac toe board
 * is symmetrical, so many game states are simple reflections or rotations of 
 * other game states.  This function returns true if 'game' is in the array or 
 * false if it is not found.
 */
bool InArray(const std::vector<Board>& gamearray, const Board& game)
{
	Board gm(game);

	for (int i = 0; i < gamearray.size(); i++)
	{
		if (gm == gamearray[i]) return true;
		if (gm.Flip() == gamearray[i]) return true;	
		for (int j = 0; j < 7; j++)
		{
			if (gm.Rotate() == gamearray[i]) return true;
		}
		if (gm.Flip() == gamearray[i]) return true;	
		for (int j = 0; j < 7; j++)
		{
			if (gm.Rotate() == gamearray[i]) return true;
		}
	}

	return false;
}

/*
 * AddNewGames finds all the possible next moves for the given game state,
 * 'game', then tests if they are already in the array, 'gamearray'. If
 * a new game is not already in the array, it is added to the array.
 */
void AddNewGames(std::vector<Board>& gamearray, const Board& game)
{
	int emptyspaces = game.EmptySpaces();

	// add X or add Y?  Odd empty, add X.  Even empty, add Y.  No empties, add nothing.
	if (emptyspaces > 0)
	{
		char move = (emptyspaces % 2) ? 'X' : 'Y';

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (game.GetMove(i, j) == ' ') 
				{
					Board newgame(game);
					newgame.PlayMove(i, j, move);	
					if (! InArray(gamearray, newgame))
						gamearray.push_back(newgame);
				}
			}
	}
}

int main()
{
/*
	char game1[3][3] = {
		 	    {'X', 'Y', 'X'},
			    {'Y', 'X', 'X'},
			    {' ', 'Y', 'Y'},
		           };

*/

	Board initialGame;
	// vector of all possible game states
	std::vector<Board> games(1, initialGame);

	for (int i = 0; i < games.size(); i++)
	{
		Board newgame = games[i];
		AddNewGames(games, newgame);
	}
	cout << "Number of unique gamestates: " << games.size() << endl;

	for (int i = 0; i < games.size(); i++)
	{
		cout << "game[" << i << "] =" << endl;
		cout << games[i] << endl; 
	}

	return 0;
}
