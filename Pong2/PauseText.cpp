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

PauseText::~PauseText()
{
    
}

void PauseText::draw(sf::RenderWindow &window)
{
    window.draw(m_Text);
}

void PauseText::setString(String textString)
{
    m_Text.setString(textString);
    inline_centreOrigin();
}

void PauseText::reset()
{
    setString("Press space to begin the round");
    inline_centreOrigin();
}

void PauseText::inline_centreOrigin()
{
    m_ObjectRect = m_Text.getLocalBounds();
    m_Text.setOrigin(m_ObjectRect.left +
                        m_ObjectRect.width / 2.0f,
                        m_ObjectRect.top +
                        m_ObjectRect.height / 2.0f);
}


