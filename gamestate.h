/*
 * gamestate.h - a structure or class to represent a gamestate and to 
 *               provide transformations to find similar states.
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

class Board {
	private:
		char _gamestate[3][3];

	public:
		Board();
		Board(char[3][3]);
		Board(const Board &);	// copy constructor
		~Board() {}

		Board& operator=(const Board&);

		Board& Rotate();
		Board& Rotate(char** state);
		Board& Flip();
		Board& Flip(char** state);
		int EmptySpaces() const;
		void PlayMove(int row, int col, char move);
		char GetMove(int row, int col) const;

		friend std::ostream& operator<<(std::ostream &out, const Board &obj);
		friend bool operator== (const Board &b1, const Board &b2);
};

#endif // GAMESTATE_H
