//
//  Player.h
//  MP_Practica
//

#ifndef Player_h
#define Player_h

#include "PlayerTile.h"

using namespace std;

const int MAX_TILES = 7;

class Player
{
public:
	Player() { m_score = 0; m_nTiles = 0; }
	void setScore(int score) { m_score = score; }
	void setTile(const Tile& tile);
private:
	int m_score;
	int m_nTiles;
	PlayerTile m_tiles[MAX_TILES];
};

#endif // !Player
