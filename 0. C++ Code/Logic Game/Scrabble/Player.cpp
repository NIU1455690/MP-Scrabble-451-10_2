//
//  Player.cpp
//  Scrabble
//

#include "Player.h"

void Player::setTile(const Tile& tile)
{
	m_tiles[m_nTiles].setTile(tile);
	m_nTiles++;
}