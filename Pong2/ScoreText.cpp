//
//  ScoreText.cpp
//  Pong2
//
//  Created by Mark Cardamis on 7/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "ScoreText.h"

ScoreText::ScoreText(int gameWidth, int gameHeight, enumPlayer playerNumber, String fontPath)
{
    m_Font.loadFromFile(fontPath);
    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(40);
    m_Text.setFillColor(sf::Color::White);
    m_Player = playerNumber;
    m_xLimit = gameWidth;
    m_yLimit = gameHeight;
    reset();
}

ScoreText::~ScoreText()
{
    
}

void ScoreText::draw(sf::RenderWindow &window)
{
    window.draw(m_Text);
}

int ScoreText::getScore()
{
    return m_ScoreNumber;
}

void ScoreText::reset()
{
    m_ScoreNumber = 0;
    _setString(m_ScoreNumber);
    switch (m_Player)
    {
    case PLAYER_LEFT:
        m_Text.setPosition(2*m_xLimit/5, m_yLimit/10);
        break;
    case PLAYER_RIGHT:
        m_Text.setPosition(3*m_xLimit/5, m_yLimit/10);
        break;
    default:
        m_Text.setPosition(m_xLimit/2, m_yLimit/10);
        break;
    }
}

void ScoreText::add()
{
    m_ScoreNumber++;
    _setString(m_ScoreNumber);
}

void ScoreText::_setString(int number)
{
    m_Text.setString(std::to_string(m_ScoreNumber));
    _centreOrigin();
}

void ScoreText::_centreOrigin()
{
    m_ObjectRect = m_Text.getLocalBounds();
    m_Text.setOrigin(m_ObjectRect.left +
                        m_ObjectRect.width / 2.0f,
                        m_ObjectRect.top +
                        m_ObjectRect.height / 2.0f);
}


