//
//  PlayerTile.cpp
//  Scrabble
//

#include "Player.h"
#include "PlayerTile.h"


PlayerTile::PlayerTile()
{

}

PlayerTile::PlayerTile(const Tile& tile, int nTile)
{
	m_tile = tile;
	m_nTile = nTile;
	m_isEmpty = false;
	m_isOnBoard = false;
	m_boardPosition = BoardPosition();
	m_posY = BOARD_POS_Y + BOARD_SIZE;
	m_posX = SCREEN_SIZE_X / MAX_TILES * m_nTile;
}