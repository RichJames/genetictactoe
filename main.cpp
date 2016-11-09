#include "gamestate.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	char game[3][3] = {
			   { ' ', ' ', ' '},
			   { ' ', ' ', ' '},
			   { ' ', ' ', ' '}
			  };

	char game2[3][3] = {
			   { 'x', ' ', ' '},
			   { ' ', ' ', ' '},
			   { ' ', 'y', ' '}
			  };

	Board myGame(game);

	cout << "Current gamestate:" << endl;
	cout << myGame << endl;

	std::vector<Board> games(1, myGame);

	cout << "games[0] == " << games[0] << endl;

	games.push_back(Board(game2));

	cout << "# of elements in games array is " << games.size() << endl;

	cout << "iterating through the games array..." << endl;
	for (int i = 0; i < games.size(); i++)
	{
		cout << "games[" << i << "] =" << endl;
		cout << games[i] << endl;
	}

	return 0;
}

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
