#include "gamestate.h"
#include <iostream>

Board::Board(char gs[3][3])
{
	_gamestate[0][0]	= gs[0][0];
	_gamestate[0][1]	= gs[0][1];
	_gamestate[0][2]	= gs[0][2];
	_gamestate[1][0]	= gs[1][0];
	_gamestate[1][1]	= gs[1][1];
	_gamestate[1][2]	= gs[1][2];
	_gamestate[2][0]	= gs[2][0];
	_gamestate[2][1]	= gs[2][1];
	_gamestate[2][2]	= gs[2][2];
}

Board::Board(const Board &board)
{
	_gamestate[0][0]	= board._gamestate[0][0];
	_gamestate[0][1]	= board._gamestate[0][1];
	_gamestate[0][2]	= board._gamestate[0][2];
	_gamestate[1][0]	= board._gamestate[1][0];
	_gamestate[1][1]	= board._gamestate[1][1];
	_gamestate[1][2]	= board._gamestate[1][2];
	_gamestate[2][0]	= board._gamestate[2][0];
	_gamestate[2][1]	= board._gamestate[2][1];
	_gamestate[2][2]	= board._gamestate[2][2];
}

Board& Board::Rotate()
{
	char x			= _gamestate[0][0];
	_gamestate[0][0]	= _gamestate[0][1];
	_gamestate[0][1]	= _gamestate[0][2];
	_gamestate[0][2]	= _gamestate[1][2];
	_gamestate[1][2]	= _gamestate[2][2];
	_gamestate[2][2]	= _gamestate[2][1];
	_gamestate[2][1]	= _gamestate[2][0];
	_gamestate[2][0]	= _gamestate[1][0];
	_gamestate[1][0]	= x;

	return *this;
}

Board& Board::Rotate(char** state)
{
	char x		= state[0][0];
	state[0][0]	= state[0][1];
	state[0][1]	= state[0][2];
	state[0][2]	= state[1][2];
	state[1][2]	= state[2][2];
	state[2][2]	= state[2][1];
	state[2][1]	= state[2][0];
	state[2][0]	= state[1][0];
	state[1][0]	= x;

	return *this;
}

Board& Board::Flip()
{
	char x			= _gamestate[1][0];
	_gamestate[1][0]	= _gamestate[0][1];
	_gamestate[0][1]	= x;

	x			= _gamestate[2][0];
	_gamestate[2][0]	= _gamestate[0][2];
	_gamestate[0][2]	= x;

	x			= _gamestate[2][1];
	_gamestate[2][1]	= _gamestate[1][2];
	_gamestate[1][2]	= x;

	return *this;
}

Board& Board::Flip(char** state)
{
	char x		= state[1][0];
	state[1][0]	= state[0][1];
	state[0][1]	= x;

	x		= state[2][0];
	state[2][0]	= state[0][2];
	state[0][2]	= x;

	x		= state[2][1];
	state[2][1]	= state[1][2];
	state[1][2]	= x;

	return *this;
}

std::ostream& operator<< (std::ostream &out, const Board &obj)
{
	out << "{ " << obj._gamestate[0][0] << ", " << obj._gamestate[0][1] << ", " << obj._gamestate[0][2] << std::endl;
	out << "  " << obj._gamestate[1][0] << ", " << obj._gamestate[1][1] << ", " << obj._gamestate[1][2] << std::endl;
	out << "  " << obj._gamestate[2][0] << ", " << obj._gamestate[2][1] << ", " << obj._gamestate[2][2];
	out << " }" << std::endl;

	return out;
}

bool operator== (const Board &b1, const Board &b2)
{
	if (b1._gamestate[0][0] != b2._gamestate[0][0]) return false;
	if (b1._gamestate[0][1] != b2._gamestate[0][1]) return false;
	if (b1._gamestate[0][2] != b2._gamestate[0][2]) return false;
	if (b1._gamestate[1][0] != b2._gamestate[1][0]) return false;
	if (b1._gamestate[1][1] != b2._gamestate[1][1]) return false;
	if (b1._gamestate[1][2] != b2._gamestate[1][2]) return false;
	if (b1._gamestate[2][0] != b2._gamestate[2][0]) return false;
	if (b1._gamestate[2][1] != b2._gamestate[2][1]) return false;
	if (b1._gamestate[2][2] != b2._gamestate[2][2]) return false;

	return true;
}
