//
//  Player.h
//  MP_Practica
//

#ifndef Player_h
#define Player_h

#include "Board.h"
#include "PlayerTile.h"
#include "LettersBag.h"
#include "AuxFuncs.h"
#include "../GraphicManager.h"

using namespace std;

const int MAX_TILES = 7;

class Player
{
public:
	Player() { m_score = 0; m_nTiles = 0; m_movingLetter = false; }
	Player(LettersBag& lettersBag);
	int const getScore() { return m_score; }
	int randomInRange(int minimo, int maximo);
	void setScore(int score) { m_score = score; }
	void renderTiles();
	void reOrder();
	void reCallTiles(Board& board);
	bool tileInBoard();
	bool drawTiles(LettersBag& lettersBag);
	bool updateTiles(int mousePosX, int mousePosY, bool mouseIsPressed, Board& board);
private:
	int m_score;
	int m_nTiles;
	int m_currentLetter;
	bool m_movingLetter;
	PlayerTile m_tiles[MAX_TILES];
};

#endif // !Player
