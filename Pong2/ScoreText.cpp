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
    font.loadFromFile(fontPath);
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    player = playerNumber;
    xLimit = gameWidth;
    yLimit = gameHeight;
    reset();
}

Text ScoreText::getText()
{
    return text;
}

int ScoreText::getScore()
{
    return scoreNumber;
}

void ScoreText::reset()
{
    scoreNumber = 0;
    setString(scoreNumber);
    switch (player)
    {
    case PLAYER_LEFT:
        text.setPosition(2*xLimit/5, yLimit/10);
        break;
    case PLAYER_RIGHT:
        text.setPosition(3*xLimit/5, yLimit/10);
        break;
    default:
        text.setPosition(xLimit/2, yLimit/10);
        break;
    }
}

void ScoreText::add()
{
    scoreNumber++;
    setString(scoreNumber);
}

void ScoreText::setString(int number)
{
    text.setString(std::to_string(scoreNumber));
    centreText();
}

void ScoreText::setString(String textString)
{
    text.setString(textString);
    centreText();
}

void ScoreText::centreText()
{
    objectRect = text.getLocalBounds();
    text.setOrigin(objectRect.left +
                        objectRect.width / 2.0f,
                        objectRect.top +
                        objectRect.height / 2.0f);
}


