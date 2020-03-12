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
    font.loadFromFile(fontPath);
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(Vector2f(width/2, height/2));
    reset();
}

Text PauseText::getText()
{
    return text;
}

void PauseText::setString(String textString)
{
    text.setString(textString);
    centreText();
}

void PauseText::reset()
{
    setString("Press space to begin the round");
    centreText();
}

void PauseText::centreText()
{
    objectRect = text.getLocalBounds();
    text.setOrigin(objectRect.left +
                        objectRect.width / 2.0f,
                        objectRect.top +
                        objectRect.height / 2.0f);
}


