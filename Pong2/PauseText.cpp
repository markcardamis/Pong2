//
//  PauseText.cpp
//  Pong2
//
//  Created by Mark Cardamis on 8/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "PauseText.h"

PauseText::PauseText(int width, int height, String fontPath)
{
    m_Font.loadFromFile(fontPath);
    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(40);
    m_Text.setFillColor(sf::Color::White);
    m_Text.setPosition(Vector2f(width/2, height/2));
    reset();
}

Text PauseText::getText()
{
    return m_Text;
}

void PauseText::setString(String textString)
{
    m_Text.setString(textString);
    m_CentreText();
}

void PauseText::reset()
{
    setString("Press space to begin the round");
    m_CentreText();
}

void PauseText::m_CentreText()
{
    m_ObjectRect = m_Text.getLocalBounds();
    m_Text.setOrigin(m_ObjectRect.left +
                        m_ObjectRect.width / 2.0f,
                        m_ObjectRect.top +
                        m_ObjectRect.height / 2.0f);
}


