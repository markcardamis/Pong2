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

ScoreText::ScoreText(int width, int height, int playerNumber, String fontPath)
{
    m_Font.loadFromFile(fontPath);
    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(height/18);     // Set dynamic font size based on height
    m_Text.setFillColor(sf::Color::White);
    m_Location = playerNumber;
    m_xLimit = width;
    m_yLimit = height;
    reset();
}

ScoreText::~ScoreText()
{
    
}

void ScoreText::draw(sf::RenderWindow* window)
{
    window->draw(m_Text);
}

int ScoreText::getScore()
{
    return m_ScoreNumber;
}

void ScoreText::reset()
{
    m_ScoreNumber = 0;
    _setString(m_ScoreNumber);
    switch (m_Location)
    {
    case LEFT_SCREEN:
        m_Text.setPosition(2*m_xLimit/5, m_yLimit/10);
        break;
    case RIGHT_SCREEN:
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


