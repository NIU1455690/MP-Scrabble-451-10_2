//
//  Button.cpp

#include "Button.h"

Button::Button()
{

}

Button::Button(IMAGE_NAME state_normal,
               IMAGE_NAME state_pressed,
               int posX, int posY,
               int width, int height)
{
    m_eCurrentState = NORMAL;
    m_iPosX = posX;
    m_iPosY = posY;
    m_iWidth = width;
    m_iHeight = height;
    m_eStateNormal = state_normal;
    m_eStatePressed = state_pressed;
}

Button::~Button(){
}


bool Button::update(int mousePosX, int mousePosY, bool mouseIsPressed) {

	bool presionat = false;
	//TODO 4.1: Implementar la programació del update...
	if (mousePosX > m_iPosX && mousePosX < m_iPosX + m_iWidth && mousePosY > m_iPosY && mousePosY < m_iPosY + m_iHeight) {
		if (mouseIsPressed)
		{
			m_eCurrentState = PRESSED;
		}
		else
		{
			if (m_eCurrentState == PRESSED)
			{
				m_eCurrentState = NORMAL;
				presionat = true;
			}
		}
	}
	else
	{
		m_eCurrentState = NORMAL;
	}
    return presionat; //Això s'ha de modificar, ho deixem posat per tal que compili sense errors.
}

void Button::render() {
    //TODO 4.2: Implementar la programació del render...
	if (m_eCurrentState == NORMAL)
	{
		GraphicManager::getInstance()->drawSprite(m_eStateNormal, m_iPosX, m_iPosY);
	}
	else
	{
		GraphicManager::getInstance()->drawSprite(m_eStatePressed, m_iPosX, m_iPosY);
	}
}