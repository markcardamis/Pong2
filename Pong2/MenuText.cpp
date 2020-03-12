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
    m_Font.loadFromFile(fontPath);
    m_Text[0].setString("Single Player vs AI");
    m_Text[1].setString("Two Player");
    m_Text[2].setString("Two Player vs AI");
    m_Text[3].setString("Exit");

    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        m_Text[i].setFont(m_Font);
        m_Text[i].setFillColor(sf::Color::White);
        m_Text[i].setPosition(Vector2f(width/2, (height/(MAX_MENU_ITEMS + 2)) * (i+1)));
        m_Text[i].setCharacterSize(40);
        m_CentreText(i);
    }
    m_SelectedItemIndex = 0;
    m_Text[0].setFillColor(sf::Color::Red);

}

MenuText::~MenuText()
{
    
}

void MenuText::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_MENU_ITEMS; ++i)
    {
        window.draw(m_Text[i]);
    }
}

void MenuText::moveUp()
{
    if (m_SelectedItemIndex - 1 >= 0)
    {
        m_Text[m_SelectedItemIndex].setFillColor(Color::White);
        m_SelectedItemIndex--;
        m_Text[m_SelectedItemIndex].setFillColor(Color::Red);
    }
}

void MenuText::moveDown()
{
    if (m_SelectedItemIndex + 1 < MAX_MENU_ITEMS)
    {
        m_Text[m_SelectedItemIndex].setFillColor(Color::White);
        m_SelectedItemIndex++;
        m_Text[m_SelectedItemIndex].setFillColor(Color::Red);
    }
}

int MenuText::getSelectedItem()
{
    return m_SelectedItemIndex;
}

void MenuText::m_CentreText(int i)
{
    m_ObjectRect = m_Text[i].getLocalBounds();
    m_Text[i].setOrigin(m_ObjectRect.left +
                        m_ObjectRect.width / 2.0f,
                        m_ObjectRect.top +
                        m_ObjectRect.height / 2.0f);
}
