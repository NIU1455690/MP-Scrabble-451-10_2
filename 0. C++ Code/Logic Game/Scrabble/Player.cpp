//
//  Player.cpp
//  Scrabble
//

#include "Player.h"

Player::Player(LettersBag& lettersBag)
{
	m_score = 0; 
	m_nTiles = 0;
	m_movingLetter = false;
	for (int i = 0; i < MAX_TILES; i++)
	{
		Tile tile = lettersBag.getLetter();
		m_tiles[i] = PlayerTile(tile, m_nTiles);
		m_nTiles++;
	}
}

void Player::updateTiles(int mousePosX, int mousePosY, bool mouseIsPressed)
{
	int tileSize = 107;
	int tilePos = SCREEN_SIZE_X / MAX_TILES;
	int minLletresY = BOARD_POS_Y + BOARD_SIZE;
	int maxLletresY = BOARD_POS_Y + BOARD_SIZE + tileSize;
	int aux_currentLetter;

	//TODO 4.1: Implementar la programació del update...
	if (!m_movingLetter)
	{
		if (mousePosY > minLletresY && mousePosY < maxLletresY) {

				if (mouseIsPressed)
				{
					m_currentLetter = mousePosX / tileSize;
					m_tiles[m_currentLetter].setEmpty(true);
					m_movingLetter = true;
				}
			}
	}
	else
	{
		if (mouseIsPressed)
		{
			m_tiles[m_currentLetter].setX(mousePosX);
			m_tiles[m_currentLetter].setY(mousePosY);
		}
		else
		{
			m_tiles[m_currentLetter].setX(tilePos * m_currentLetter);
			m_tiles[m_currentLetter].setY(minLletresY);
			m_tiles[m_currentLetter].setEmpty(false);
			m_movingLetter = false;
		}
	}
}

void Player::renderTiles()
{
	for (int i = 0; i < MAX_TILES; i++)
	{
		bool big;

		if (!m_tiles[i].isEmpty())
		{
			big = true;
		}
		else
		{
			big = false;
		}

		IMAGE_NAME letterImage = letterToImageName(m_tiles[i].getTile().getLetter(), big);
		GraphicManager::getInstance()->drawSprite(letterImage, m_tiles[i].getX(), m_tiles[i].getY());
		
	}
	
}

IMAGE_NAME Player::letterToImageName(char letter, bool big)
{
	IMAGE_NAME letterImage;
	if (big)
	{
		switch (letter)
		{
		case 'a':
			letterImage = IMAGE_LETTER_A_BIG;
			break;
		case 'b':
			letterImage = IMAGE_LETTER_B_BIG;
			break;
		case 'c':
			letterImage = IMAGE_LETTER_C_BIG;
			break;
		case 'd':
			letterImage = IMAGE_LETTER_D_BIG;
			break;
		case 'e':
			letterImage = IMAGE_LETTER_E_BIG;
			break;
		case 'f':
			letterImage = IMAGE_LETTER_F_BIG;
			break;
		case 'g':
			letterImage = IMAGE_LETTER_G_BIG;
			break;
		case 'h':
			letterImage = IMAGE_LETTER_H_BIG;
			break;
		case 'i':
			letterImage = IMAGE_LETTER_I_BIG;
			break;
		case 'j':
			letterImage = IMAGE_LETTER_J_BIG;
			break;
		case 'k':
			letterImage = IMAGE_LETTER_K_BIG;
			break;
		case 'l':
			letterImage = IMAGE_LETTER_L_BIG;
			break;
		case 'm':
			letterImage = IMAGE_LETTER_M_BIG;
			break;
		case 'n':
			letterImage = IMAGE_LETTER_N_BIG;
			break;
		case 'o':
			letterImage = IMAGE_LETTER_O_BIG;
			break;
		case 'p':
			letterImage = IMAGE_LETTER_P_BIG;
			break;
		case 'q':
			letterImage = IMAGE_LETTER_Q_BIG;
			break;
		case 'r':
			letterImage = IMAGE_LETTER_R_BIG;
			break;
		case 's':
			letterImage = IMAGE_LETTER_S_BIG;
			break;
		case 't':
			letterImage = IMAGE_LETTER_T_BIG;
			break;
		case 'u':
			letterImage = IMAGE_LETTER_U_BIG;
			break;
		case 'v':
			letterImage = IMAGE_LETTER_V_BIG;
			break;
		case 'w':
			letterImage = IMAGE_LETTER_W_BIG;
			break;
		case 'x':
			letterImage = IMAGE_LETTER_X_BIG;
			break;
		case 'y':
			letterImage = IMAGE_LETTER_Y_BIG;
			break;
		case 'z':
			letterImage = IMAGE_LETTER_Z_BIG;
			break;
		}
	}
	else
	{
		switch (letter)
		{
		case 'a':
			letterImage = IMAGE_LETTER_A_SMALL;
			break;
		case 'b':
			letterImage = IMAGE_LETTER_B_SMALL;
			break;
		case 'c':
			letterImage = IMAGE_LETTER_C_SMALL;
			break;
		case 'd':
			letterImage = IMAGE_LETTER_D_SMALL;
			break;
		case 'e':
			letterImage = IMAGE_LETTER_E_SMALL;
			break;
		case 'f':
			letterImage = IMAGE_LETTER_F_SMALL;
			break;
		case 'g':
			letterImage = IMAGE_LETTER_G_SMALL;
			break;
		case 'h':
			letterImage = IMAGE_LETTER_H_SMALL;
			break;
		case 'i':
			letterImage = IMAGE_LETTER_I_SMALL;
			break;
		case 'j':
			letterImage = IMAGE_LETTER_J_SMALL;
			break;
		case 'k':
			letterImage = IMAGE_LETTER_K_SMALL;
			break;
		case 'l':
			letterImage = IMAGE_LETTER_L_SMALL;
			break;
		case 'm':
			letterImage = IMAGE_LETTER_M_SMALL;
			break;
		case 'n':
			letterImage = IMAGE_LETTER_N_SMALL;
			break;
		case 'o':
			letterImage = IMAGE_LETTER_O_SMALL;
			break;
		case 'p':
			letterImage = IMAGE_LETTER_P_SMALL;
			break;
		case 'q':
			letterImage = IMAGE_LETTER_Q_SMALL;
			break;
		case 'r':
			letterImage = IMAGE_LETTER_R_SMALL;
			break;
		case 's':
			letterImage = IMAGE_LETTER_S_SMALL;
			break;
		case 't':
			letterImage = IMAGE_LETTER_T_SMALL;
			break;
		case 'u':
			letterImage = IMAGE_LETTER_U_SMALL;
			break;
		case 'v':
			letterImage = IMAGE_LETTER_V_SMALL;
			break;
		case 'w':
			letterImage = IMAGE_LETTER_W_SMALL;
			break;
		case 'x':
			letterImage = IMAGE_LETTER_X_SMALL;
			break;
		case 'y':
			letterImage = IMAGE_LETTER_Y_SMALL;
			break;
		case 'z':
			letterImage = IMAGE_LETTER_Z_SMALL;
			break;
		}
	}

	return letterImage;
}