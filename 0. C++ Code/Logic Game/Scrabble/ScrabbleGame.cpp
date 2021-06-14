//
//  ScrabbleGame.cpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "ScrabbleGame.h"

ScrabbleGame::ScrabbleGame()
{
	m_lettersBag = LettersBag();
	m_board = Board();
	m_currentPlayer = 0;
	m_currentPoints = 0;
	m_passedTurns = 0;
	m_wordResultError = false;

	// Inicialització jugadors i fitxes
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		m_players[i] = Player(m_lettersBag);
		
	}

	// Inicialització botons
	int btn_size_w = 139;
	int btn_size_h = 100; 
	int btn_pos_x = SCREEN_SIZE_X * 0.5 - btn_size_w * 0.5;
	int btn_pos_y = SCREEN_SIZE_Y - btn_size_h; 
	int btn_recall_pos_x = btn_pos_x - btn_size_w * 0.75;
	int btn_shuffle_pos_x = btn_pos_x + btn_size_w;

	m_buttonRecall = Button(IMAGE_BUTTON_RECALL_NORMAL, IMAGE_BUTTON_RECALL_PRESSED, btn_recall_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_buttonShuffle = Button(IMAGE_BUTTON_SHUFFLE_NORMAL, IMAGE_BUTTON_SHUFFLE_PRESSED, btn_shuffle_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_buttonSend = Button(IMAGE_BUTTON_SEND_NORMAL, IMAGE_BUTTON_SEND_PRESSED, btn_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_buttonPass = Button(IMAGE_BUTTON_PASS_NORMAL, IMAGE_BUTTON_PASS_PRESSED, btn_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_tilePlayed = false;
}

ScrabbleGame::~ScrabbleGame() {

}

void ScrabbleGame::updateAndRender(int mousePosX, int mousePosY, bool mouseStatus) {
	
	// Dibujar background y board
	GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);

	if (!m_endedGame)
	{
		//////////////////////////////////////////////////////////////////////////////////// RENDERS


		// Render fichas jugador
		m_players[m_currentPlayer].renderTiles();

		// Render botones
		m_buttonRecall.render();
		m_buttonShuffle.render();

		// Mensajes
		string playerMessage = "Player turn: " + to_string(m_currentPlayer + 1);
		string playerPoints;
		for (int i = 0; i < NUM_PLAYERS; i++)
		{
			playerPoints = "Score Player " + to_string(i + 1) + " = " + to_string(m_players[i].getScore());
			GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 10, BOARD_POS_Y + BOARD_SIZE + 100 + 35 * i, 0.6, playerPoints);

		}
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 10, 10, 0.6, playerMessage); // Turno jugador

		//////////////////////////////////////////////////////////////////////////////////// FUNCIONALIDAD
		int posX = BOARD_POS_X;
		int posY = BOARD_POS_Y;

		for (int x = 0; x < BOARD_COLS_AND_ROWS; x++)
		{
			for (int y = 0; y < BOARD_COLS_AND_ROWS; y++)
			{
				BoardPosition bp = BoardPosition(y, x);
				if (!m_board.isTileEmpty(bp))
				{
					IMAGE_NAME letterImage = letterToImageName(m_board.getLetterFromTile(bp), false);
					GraphicManager::getInstance()->drawSprite(letterImage, posX, posY);
				}
				posX += BOARD_TILE_SIZE;
			}
			posY += BOARD_TILE_SIZE;
			posX = BOARD_POS_X;
		}

		if (m_tilePlayed) // Mostrar pass o send
		{
			m_buttonSend.render();
			if (m_buttonSend.getState() != PRESSED)
			{
				m_buttonSend.setState(NORMAL);
			}
			m_buttonPass.setState(NONE);
		}
		else
		{

			m_buttonPass.render();
			if (m_buttonPass.getState() != PRESSED)
			{
				m_buttonPass.setState(NORMAL);
			}
			m_buttonSend.setState(NONE);

		}

		m_tilePlayed = m_players[m_currentPlayer].updateTiles(mousePosX, mousePosY, mouseStatus, m_board);

		m_currentPoints = 0;
		if (m_tilePlayed)
		{
			// Estado jugada actual del jugador
			m_currentPoints = m_players[m_currentPlayer].getScore();
			CurrentWordResult wordResult;
			m_wordResultError = true;
			wordResult = m_board.checkCurrentWord(m_currentPoints);
			string wordResultMessage;

			switch (wordResult)
			{
			case ALL_CORRECT:
				m_wordResultError = false;
				wordResultMessage = "Points: " + to_string(m_currentPoints);
				break;
			case INVALID_NOT_ALIGNED:
				wordResultMessage = "Tiles must be vertically or horizontally aligned and together";
				break;
			case INVALID_NOT_CONNECTION:
				wordResultMessage = "At least one letter must be next to the rest of the words";
				break;
			case INVALID_START_NOT_IN_CENTER:
				wordResultMessage = "You have to start using the center position";
				break;
			case INVALID_WORD_OF_ONE_LETTER:
				wordResultMessage = "Only words of two or more letters";
				break;
			case INVALID_WORDS_NOT_IN_DICTIONARY:
				wordResultMessage = "The new words are not in the dictionary";
				break;
			default:
				break;
			}

			if (m_wordResultError) // Puntos o error en la jugada
			{
				GraphicManager::getInstance()->drawFont(FONT_RED_30, 150, 10, 0.6, wordResultMessage);
			}
			else
			{
				GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 150, 10, 0.6, wordResultMessage);
			}
		}



		//////////////////////////////////////////////////////////////////////////////////// UPDATES

		if (m_buttonPass.update(mousePosX, mousePosY, mouseStatus)) // Pass presionado
		{
			nextTurn();
			m_board.removeCurrentWord();
			m_passedTurns++;
			if (m_passedTurns == NUM_PLAYERS)
			{
				m_endedGame = true;
			}
		}

		if (m_buttonSend.update(mousePosX, mousePosY, mouseStatus)) // Send presionado
		{
			if (!m_wordResultError)
			{
				m_players[m_currentPlayer].setScore(m_players[m_currentPlayer].getScore() + m_currentPoints);
				m_board.sendCurrentWordToBoard();
				nextTurn();
				m_passedTurns = 0;
			}
		}

		if (m_buttonShuffle.update(mousePosX, mousePosY, mouseStatus)) // Shuffle presionado
		{
			m_players[m_currentPlayer].reOrder();
		}

		if (m_buttonRecall.update(mousePosX, mousePosY, mouseStatus)) // Recall presionado
		{
			m_players[m_currentPlayer].reCallTiles(m_board);
			m_board.removeCurrentWord();
		}
		
		string msg = "PosX : " + to_string(mousePosX) + "    " + "PosY : " + to_string(mousePosY);
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 610, 10, 0.4, msg);

	}
	else
	{
		// Winner
		string msg;
		int playerWon = winner();

		if (playerWon == -1)
		{
			msg = "The game ended! There are no winners :(";
			GraphicManager::getInstance()->drawFont(FONT_WHITE_30, ((BOARD_POS_X + BOARD_SIZE) / 2) - 250, BOARD_POS_Y + BOARD_SIZE + 100, 1, msg);
		}
		else
		{
			msg = "The game ended! Winner: Player " + to_string(playerWon + 1);
			GraphicManager::getInstance()->drawFont(FONT_WHITE_30, ((BOARD_POS_X + BOARD_SIZE) / 2) - 190, BOARD_POS_Y + BOARD_SIZE + 100, 1, msg);
		}
		
	}
}

void ScrabbleGame::nextTurn()
{
	if (m_currentPlayer == 2)
	{
		m_currentPlayer = 0;
	}
	else
	{
		m_currentPlayer++;
	}
	m_endedGame = m_players[m_currentPlayer].drawTiles(m_lettersBag);
}

int ScrabbleGame::winner()
{
	int winner = 0;
	int maxPoints = m_players[winner].getScore();
	bool draw = false;

	for (int i = 1; i < NUM_PLAYERS; i++)
	{
		if (m_players[i].getScore() > maxPoints)
		{
			winner = i;
			draw = false;
		}
		else if (m_players[i].getScore() == maxPoints)
		{
			draw = true;
		}
	}

	if (draw)
	{
		winner = -1;
	}
	
	return winner;
}