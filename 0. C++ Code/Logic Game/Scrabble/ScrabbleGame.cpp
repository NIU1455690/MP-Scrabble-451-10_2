#include "ScrabbleGame.h"
#include "../Scrabble_Defs.h"

#include "../GraphicManager.h"

ScrabbleGame::ScrabbleGame()
{
    btn_isPressed = false;
    draw_tiles = false;
}

ScrabbleGame::~ScrabbleGame() {

}

void ScrabbleGame::updateAndRender(int mousePosX, int mousePosY, bool mouseStatus) {

    int btn_size_w = 139;
    int btn_size_h = 100;
    int btn_pos_x = SCREEN_SIZE_X * 0.5 - btn_size_w * 0.5;
    int btn_pos_y = SCREEN_SIZE_Y - btn_size_h;

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

    if (!btn_isPressed)
    {
        GraphicManager::getInstance()->drawSprite(IMAGE_BUTTON_SEND_NORMAL, btn_pos_x, btn_pos_y);
    }
    else
    {
        GraphicManager::getInstance()->drawSprite(IMAGE_BUTTON_SEND_PRESSED, btn_pos_x, btn_pos_y);
    }

    if (mousePosX > btn_pos_x && mousePosX < btn_pos_x + btn_size_w && mousePosY > btn_pos_y && mousePosY < btn_pos_y + btn_size_h) {
        if (mouseStatus)
        {
            btn_isPressed = true;
        }
        else
        {
            if (btn_isPressed)
            {
                btn_isPressed = false;
                draw_tiles = !draw_tiles;
            }
        }
    }
    else
    {
        btn_isPressed = false;
    }
}