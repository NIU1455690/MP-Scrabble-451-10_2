//
//  PlayerTile.cpp
//  Scrabble
//

#include "PlayerTile.h"

PlayerTile::PlayerTile(const Tile& tile, int nTile)
{
	m_tile = tile;
	m_nTile = nTile;
	m_isEmpty = false;
	m_isOnBoard = false;
	m_boardPosition = BoardPosition();
	m_posY = BOARD_POS_Y + BOARD_SIZE;
	m_posX = SCREEN_SIZE_X / 7 * m_nTile;
}