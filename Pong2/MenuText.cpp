//
//  MenuText.cpp
//  Pong2
//
//  Created by Mark Cardamis on 7/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "MenuText.h"

MenuText::MenuText(float width, float height, String fontPath)
{
    font.loadFromFile(fontPath);
    text[0].setString("Single Player vs AI");
    text[1].setString("Two Player");
    text[2].setString("Two Player vs AI");
    text[3].setString("Exit");

    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        text[i].setFont(font);
        text[i].setFillColor(sf::Color::White);
        text[i].setPosition(Vector2f(width/2, (height/(MAX_MENU_ITEMS + 2)) * (i+1)));
        text[i].setCharacterSize(40);
        centreText(i);
    }
    selectedItemIndex = 0;
    text[0].setFillColor(sf::Color::Red);

}

MenuText::~MenuText()
{
    
}

void MenuText::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_MENU_ITEMS; ++i)
    {
        window.draw(text[i]);
    }
}

void MenuText::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setFillColor(Color::White);
        selectedItemIndex--;
        text[selectedItemIndex].setFillColor(Color::Red);
    }
}

void MenuText::moveDown()
{
    if (selectedItemIndex + 1 < MAX_MENU_ITEMS)
    {
        text[selectedItemIndex].setFillColor(Color::White);
        selectedItemIndex++;
        text[selectedItemIndex].setFillColor(Color::Red);
    }
}

int MenuText::getSelectedItem()
{
    return selectedItemIndex;
}

void MenuText::centreText(int i)
{
    objectRect = text[i].getLocalBounds();
    text[i].setOrigin(objectRect.left +
                        objectRect.width / 2.0f,
                        objectRect.top +
                        objectRect.height / 2.0f);
}
