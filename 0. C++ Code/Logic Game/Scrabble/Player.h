//
//  Player.h
//  MP_Practica
//

#ifndef Player_h
#define Player_h

#include "PlayerTile.h"
#include "LettersBag.h"
#include "../GraphicManager.h"

using namespace std;

const int MAX_TILES = 7;

class Player
{
public:
	Player() { m_score = 0; m_nTiles = 0; m_movingLetter = false; }
	Player(LettersBag& lettersBag);
	void setScore(int score) { m_score = score; }
	void renderTiles();
	void updateTiles(int mousePosX, int mousePosY, bool mouseIsPressed);
	IMAGE_NAME letterToImageName(char letter, bool big);
private:
	int m_score;
	int m_nTiles;
	int m_currentLetter;
	bool m_movingLetter;
	PlayerTile m_tiles[MAX_TILES];
};

#endif // !Player
