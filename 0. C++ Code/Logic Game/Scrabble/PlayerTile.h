//
//  PlayerTile.h
//  MP_Practica
//

#ifndef PlayerTile_h
#define PlayerTile_h

#include "Tile.h"
#include "BoardPosition.h"
#include "../Scrabble_Defs.h"

using namespace std;

class PlayerTile
{
public:
	PlayerTile();
	PlayerTile(const Tile& tile, int nTile);
	int const getX() { return m_posX; }
	int const getY() { return m_posY; }
	bool const isEmpty() { return m_isEmpty; }
	bool const isOnBoard() { return m_isOnBoard; }
	BoardPosition const getBoardPosition() { return m_boardPosition; }
	void setTile(const Tile& tile) { m_tile = tile; }
	void setX(int posX) { m_posX = posX; }
	void setY(int posY) { m_posY = posY; }
	void setEmpty(bool empty) { m_isEmpty = empty; }
	void setOnBoard(bool onBoard) { m_isOnBoard = onBoard; }
	void setBoardPosition(const BoardPosition& bp) { m_boardPosition = bp; }
private:
	Tile m_tile;
	int m_nTile;
	bool m_isEmpty;
	bool m_isOnBoard;
	float m_posX, m_posY;
	BoardPosition m_boardPosition;
};

#endif // !PlayerTile
