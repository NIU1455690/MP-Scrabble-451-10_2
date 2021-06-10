//
//  ScrabbleGame.hpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef ScrabbleGame_hpp
#define ScrabbleGame_hpp

#include <stdio.h>
#include "Board.h"
#include "Button.h"
#include "Player.h"
#include "LettersBag.h"

const int NUM_PLAYERS = 3;

class ScrabbleGame
{
public:
    ScrabbleGame();
    ~ScrabbleGame();
    void updateAndRender(int mousePosX, int mousePosY, bool mouseStatus);
    void nextTurn();
private:
    Board m_board;
    Player m_players[NUM_PLAYERS];
    LettersBag m_lettersBag;
    Button m_buttonRecall;
    Button m_buttonShuffle;
    Button m_buttonSend;
    Button m_buttonPass;
	bool draw_tiles;
    bool btn_isPressed;
    int m_currentPlayer;
	//TODO 4.3: Instanciar el botó send fent ús de la classe Button.
	// - Eliminem el codi que hem fet per poder gestionar un botó i ara ho fem mitjançant la classe Button
	// - Inicialitzar la instància de button en el constructor de ScrabbleGame.
	// - Fer la crida del render i update de la instància en el updateAndRender(...).


};

#endif /* ScrabbleGame_hpp */
