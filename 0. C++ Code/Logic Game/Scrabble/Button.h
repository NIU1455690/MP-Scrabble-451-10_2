//
//  Button.hpp
#pragma once

#ifndef Button_h
#define Button_h

#include <stdio.h>
#include <string>
#include "../GraphicManager.h"

using namespace std;

typedef enum {
    NORMAL = 0,
    PRESSED,
    NONE
} ButtonState;

class Button
{
public:
    Button();
    Button(IMAGE_NAME state_normal,
           IMAGE_NAME state_pressed,
           int posX, int posY,
           int width, int height);

    ~Button();

    bool update(int mousePosX, int mousePosY, bool mouseIsPressed);
    void render();
    void setY(int y);
    void setState(ButtonState state) { m_eCurrentState = state; }
    ButtonState getState() { return m_eCurrentState; }

private:
    ButtonState m_eCurrentState;
    int         m_iPosX;
    int         m_iPosY;
    int         m_iWidth;
    int         m_iHeight;
    IMAGE_NAME  m_eStateNormal;
    IMAGE_NAME  m_eStatePressed;
};

#endif 