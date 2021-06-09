//
//  ScrabbleGame.cpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright � 2021 CompiledCreations. All rights reserved.
//

#include "ScrabbleGame.h"
#include "../Scrabble_Defs.h"

#include "../GraphicManager.h"

ScrabbleGame::ScrabbleGame()
{
	m_lettersBag = LettersBag();
	m_board = Board();

	// Inicialitzaci� jugadors i fitxes
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		for (int j = 0; i < MAX_TILES; i++)
		{
			Tile tile = m_lettersBag.getLetter();
			m_players[i].setTile(tile);
		}
		
	}

	// Inicialitzaci� botons
	int btn_size_w = 139;
	int btn_size_h = 100;
	int btn_pos_x = SCREEN_SIZE_X * 0.5 - btn_size_w * 0.5;
	int btn_pos_y = SCREEN_SIZE_Y - btn_size_h;

	m_buttonRecall = Button(IMAGE_BUTTON_RECALL_NORMAL, IMAGE_BUTTON_RECALL_PRESSED, btn_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_buttonShuffle = Button(IMAGE_BUTTON_SHUFFLE_NORMAL, IMAGE_BUTTON_SHUFFLE_PRESSED, btn_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_buttonSend = Button(IMAGE_BUTTON_SEND_NORMAL, IMAGE_BUTTON_SEND_PRESSED, btn_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	m_buttonPass = Button(IMAGE_BUTTON_PASS_NORMAL, IMAGE_BUTTON_PASS_PRESSED, btn_pos_x, btn_pos_y, btn_size_w, btn_size_h);
	btn_isPressed = false;
	draw_tiles = false;
}

ScrabbleGame::~ScrabbleGame() {

}

void ScrabbleGame::updateAndRender(int mousePosX, int mousePosY, bool mouseStatus) {

	//--------------------------------------------------------------
	//TODO 1: Interactuar amb la crida de pintar images (sprites).
	//--------------------------------------------------------------

	//TODO 1.1 Afegir l'include de GraphicManager --> #include "../GraphicManager.h"

	//TODO 1.2 Fer la crida de pintar sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY);
	//	    Per comen�ar podem cridar el drawSprite amb els params --> (IMAGE_BOARD,0,0)

	//GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, int(SCREEN_SIZE_X * 0.5 - BOARD_SIZE * 0.5), 40);
	//TODO 1.3 Reescriure la crida de pintar el IMAGE_BOARD per� que estigui centrat en l'eix X i a 40 p�xels de l'eix Y
	//		Podeu fer servir la constant BOARD_SIZE definida a Scrabble_Defs.h
	//          SCREEN_SIZE_X (tenim aquesta constant que definexi el width de la pantalla)
	//  (0,0) ----------------> X+ 
	//    |
	//    |
	//    |
	//    v
	//    Y+ 
	// SCREEN_SIZE_Y (tenim aquesta altre constant que defineixi el height de la pantalla)


	//TODO 1.4: Us anir� molt b� definir en el Scrabble_Defs.h dos constants BOARD_POS_X, BOARD_POS_Y i refer la 
	//		crida anterior. Reutilitzareu diverses vegades aquestes constants. 



	//TODO 1.5: Cridar el sprite IMAGE_BACKGROUND. Aquest ocupa tota la pantalla i b�sicament �s de color blau.
	//			El podem cridar utilitzant la posici� inicial 0,0.



	//TODO 1.6: Fixeu-vos que el sprite del board ha desaparegut. Aix� ha passat ja que l'�ltima crida de drawSprite
	//			queda per sobre de l'anterior. Reescriure l'ordre de pintat per tal que el board estigui despr�s del
	//			background.




	//TODO 1.7: Anem a pintar la imatge de la tile 'A' (IMAGE_LETTER_A_SMALL)
	//			Recordeu que podeu utilitzar les constants definides en Scrabble_Defs.h --> 
	//			BOARD_POS_X: posici� inicial del board en l'eix X
	//			BOARD_POS_Y: posici� inicial del board en l'eix Y
	//			BOARD_TILE_SIZE: Mida de la tile (tant per width com per height)
	//			BOARD_COLS_AND_ROWS: Nombre de columnes i rows (�s el mateix).

	//--------------------------------------------------------------
	//TODO 2: Interacci� amb el mouse
	//------------------------------------------

	//TODO 2.1: Observeu que passa si poseu tot el codi del pintat de les tiles 'A' en un if(mouseStatus)



	//TODO 2.2: Afegiu com a �ltima crida del vostre codi la seg�ent crida del GraphicManager-->
	//			GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 10, 10, 0.6, "Hello world!");
	//			Recordeu que tota crida de drawSprite o drawFont segueix l'ordre de pintat. Si executem
	//			aquesta crida de drawFont com a primera instrucci� no es visualitzar�, ja que est� per darrera
	//			del background.



	//TODO 2.3: Imprimiu les coordenades del mouse (us la passen per par�metres), fent �s de drawFont.



	//--------------------------------------------------------------
	//TODO 3: Programar el codi per afegir un bot�
	//--------------------------------------------
	//Per no liar-nos amb el click del mouse, treiem el pintat dels tiles respecte l'estat del bot� del mouse.
	//TODO 3.1: - Programar un bot� fent �s de les imatges 
	//			    IMAGE_BUTTON_SEND_NORMAL: per dibuixar la seva representaci� del bot� quan el mouse no est� pressionant dintre de la seva zona
	//			    IMAGE_BUTTON_SEND_PRESSED: per dibuixar la representaci� del bot� quan el mouse est� pressionant dintre de la seva zona
	//			- Haureu de fer servir una variable per saber en quin estat est� el mouse respecte el bot�.
	//			- Podeu fer servir les seg�ents coordenades pel bot�-->
	//			    int btn_size_w = 139;
	//			    int btn_size_h = 100;
	//			    int btn_pos_x = SCREEN_SIZE_X*0.5 - btn_size_w*0.5;
	//			    int btn_pos_y = SCREEN_SIZE_Y - btn_size_h;
	//			- Heu de fer que es produeixi una acci� al pr�mer en el bot� --> pintar/deixar de pintar les lletres
	//				- Acci� es produeix quan entrem en la zona del bot� i passem d'estar apretant el bot� de mouse a no estar-hi
	//
	
	GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);

	if (draw_tiles)
	{
		int posX = BOARD_POS_X;
		int posY = BOARD_POS_Y;
		for (int i = 0; i < BOARD_COLS_AND_ROWS; i++)
		{
			for (int j = 0; j < BOARD_COLS_AND_ROWS; j++)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_LETTER_A_SMALL, posX, posY);
				posX += BOARD_TILE_SIZE;
			}
			posY += BOARD_TILE_SIZE;
			posX = BOARD_POS_X;
		}
	}
	std::string msg = "PosX: " + to_string(mousePosX) + ", PosY: " + to_string(mousePosY);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 10, 10, 0.6, msg);

	m_buttonSend.render();

	if (m_buttonSend.update(mousePosX, mousePosY, mouseStatus)) 
	{
		draw_tiles = !draw_tiles;
	}

}
