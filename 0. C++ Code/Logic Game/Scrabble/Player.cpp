//
//  Player.cpp
//  Scrabble
//

#include "Player.h"
#include "iostream"

using namespace std;

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

bool Player::drawTiles(LettersBag& lettersBag)
{
	int tilePos = SCREEN_SIZE_X / MAX_TILES;
	int i = 0;
	while (!lettersBag.isEmpty() && i < MAX_TILES)
	{
		if (m_tiles[i].isOnBoard())
		{
			Tile tile = lettersBag.getLetter();
			m_tiles[i].setTile(tile);
			m_tiles[i].setEmpty(false);
			m_tiles[i].setOnBoard(false);
			m_tiles[i].setX(tilePos * i);
			m_tiles[i].setY(BOARD_POS_Y + BOARD_SIZE);
		}
		else
		{
			i++;
		}
	}

	return lettersBag.isEmpty();
}

bool Player::updateTiles(int mousePosX, int mousePosY, bool mouseIsPressed, Board& board)
{
	int tileSize = 107;
	int tileSizeSmall = BOARD_TILE_SIZE;
	int tilePos = SCREEN_SIZE_X / MAX_TILES;
	int minLletresY = BOARD_POS_Y + BOARD_SIZE;
	int maxLletresY = BOARD_POS_Y + BOARD_SIZE + tileSize;
	int aux_currentLetter;
	int currentLetterCol = 0;
	int currentLetterRow = 0;

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
		else if (mousePosY < minLletresY && mousePosY > BOARD_POS_Y && mousePosX > BOARD_POS_X && mousePosX < (BOARD_POS_X + (tileSizeSmall * BOARD_COLS_AND_ROWS)))
		{
			if (mouseIsPressed)
			{
				currentLetterCol = (mousePosX / tileSizeSmall) - 2;
				currentLetterRow = (mousePosY / tileSizeSmall) - 1;
				int currentLetterCol0 = BOARD_POS_X + (currentLetterCol * tileSizeSmall);
				int currentLetterRow0 = BOARD_POS_Y + (currentLetterRow * tileSizeSmall);

				bool encontrada = false;
				int i = 0;
				while (!encontrada && i < MAX_TILES)
				{
					if (currentLetterCol0 == m_tiles[i].getX() && currentLetterRow0 == m_tiles[i].getY())
					{
						BoardPosition bp = BoardPosition(currentLetterCol, currentLetterRow);
						m_currentLetter = i;
						m_tiles[m_currentLetter].setOnBoard(false);
						m_movingLetter = true;
						encontrada = true;
						board.removeTile(bp);
					}
					else
					{
						i++;
					}
				}
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
			if (mousePosY < minLletresY && mousePosY > BOARD_POS_Y && mousePosX > BOARD_POS_X && mousePosX < BOARD_POS_X + (tileSizeSmall * BOARD_COLS_AND_ROWS)) // Se suelta ficha dentro del tablero, colocamos ficha en board
			{
				currentLetterCol = (mousePosX / tileSizeSmall) - 2;
				currentLetterRow = (mousePosY / tileSizeSmall) - 1;
				
				BoardPosition bp = BoardPosition(currentLetterCol, currentLetterRow);
				if (board.isTileEmpty(bp))
				{
					m_tiles[m_currentLetter].setX(BOARD_POS_X + (currentLetterCol * tileSizeSmall));
					m_tiles[m_currentLetter].setY(BOARD_POS_Y + (currentLetterRow * tileSizeSmall));
					m_tiles[m_currentLetter].setOnBoard(true);
					m_tiles[m_currentLetter].setEmpty(true);
					m_tiles[m_currentLetter].setBoardPosition(bp);
					board.setTile(m_tiles[m_currentLetter].getTile(), m_tiles[m_currentLetter].getBoardPosition());
				}
				else
				{
					m_tiles[m_currentLetter].setX(tilePos * m_currentLetter);
					m_tiles[m_currentLetter].setY(minLletresY);
					m_tiles[m_currentLetter].setEmpty(false);
					m_tiles[m_currentLetter].setOnBoard(false);
				}
				m_movingLetter = false;
				
			}
			else
			{
				m_tiles[m_currentLetter].setX(tilePos * m_currentLetter);
				m_tiles[m_currentLetter].setY(minLletresY);
				m_tiles[m_currentLetter].setEmpty(false);
				m_tiles[m_currentLetter].setOnBoard(false);
				m_movingLetter = false;
			}
		}
	}

	return tileInBoard();

}

void Player::reOrder()
{

	vector<PlayerTile> auxTiles;
	int nAuxTiles = MAX_TILES;
	int indice = 0;
	int nTiles = 0;

	for (int i = 0; i < MAX_TILES; i++)
	{
		auxTiles.push_back(m_tiles[i]);
	}

	while (nAuxTiles > 0)
	{
		indice = randomInRange(0, nAuxTiles - 1);
		nAuxTiles--;
		m_tiles[nTiles] = auxTiles[indice];
		nTiles++;

		auxTiles.erase(auxTiles.begin() + indice);
	}

	int minLletresY = BOARD_POS_Y + BOARD_SIZE;
	int tilePos = SCREEN_SIZE_X / MAX_TILES;

	for (int i = 0; i < MAX_TILES; i++)
	{
		if (!m_tiles[i].isOnBoard()) {
			m_tiles[i].setX(tilePos * i);
			m_tiles[i].setY(minLletresY);
			m_tiles[i].setEmpty(false);
			m_movingLetter = false;
			m_tiles[i].setOnBoard(false);
		}
	}
}

bool Player::tileInBoard()
{
	bool tilePlayed = false;
	int i = 0;

	while (!tilePlayed && i < MAX_TILES)
	{
		if (m_tiles[i].isOnBoard()) tilePlayed = true;
		i++;
	}

	return tilePlayed;
}

void Player::reCallTiles(Board& board)
{
	int minLletresY = BOARD_POS_Y + BOARD_SIZE;
	int tilePos = SCREEN_SIZE_X / MAX_TILES;
	int currentLetterCol;
	int currentLetterRow;
	for (int i = 0; i < MAX_TILES; i++)
	{
		if (m_tiles[i].isOnBoard())
		{
			m_tiles[i].setX(tilePos * i);
			m_tiles[i].setY(minLletresY);
			m_tiles[i].setEmpty(false);
			m_movingLetter = false;
			m_tiles[i].setOnBoard(false);
			BoardPosition bp = m_tiles[i].getBoardPosition();
			board.removeTile(bp);
		}
	}
	
}

int Player::randomInRange(int minimo, int maximo)
{
	return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
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