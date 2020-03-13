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
    // Set default text options
    m_Font.loadFromFile(fontPath);
    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(height/18);     // Set dynamic font size based on height
    m_SelectedItemIndex = 0;                // Set selected index to 0
    
    _addString("Single Player vs AI", width, height);
    _addString("Two Player", width, height);
    _addString("Two Player vs AI", width, height);
    _addString("Exit", width, height);

}

MenuText::~MenuText()
{
    
}

void MenuText::draw(sf::RenderWindow &window)
{
    
    for (std::vector<Text>::iterator it = m_VectorMenu.begin(); it != m_VectorMenu.end(); ++it)
    {
        window.draw(*it);
    }
    
}

void MenuText::moveUp()
{
    if (m_SelectedItemIndex - 1 >= 0)
    {
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::White);
        m_SelectedItemIndex--;
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::Red);
    }
}

void MenuText::moveDown()
{
    if (m_SelectedItemIndex + 1 < m_VectorMenu.size())
    {
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::White);
        m_SelectedItemIndex++;
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::Red);
    }
}

int MenuText::getSelectedItem()
{
    return m_SelectedItemIndex;
}

void MenuText::_addString(String input, float width, float height)
{
    m_Text.setString(input);
    m_VectorMenu.push_back(_centreOrigin(m_Text));
    if (m_VectorMenu.size() == m_SelectedItemIndex + 1) // Set selected text to red when added to Vector
    {
        m_VectorMenu[m_SelectedItemIndex].setFillColor(sf::Color::Red);
    } else
    {
        m_Text.setFillColor(sf::Color::White);
    }
    _verticallySpaceText(width, height);
}

Text MenuText::_centreOrigin(Text textObject)
{
    m_ObjectRect = textObject.getLocalBounds();
    textObject.setOrigin(m_ObjectRect.left +
                        m_ObjectRect.width / 2.0f,
                        m_ObjectRect.top +
                        m_ObjectRect.height / 2.0f);
    return textObject;
}

void MenuText::_verticallySpaceText(float width, float height)
{
    // Use iterator to run through the Vector of type Text and
    for (std::vector<Text>::iterator it = m_VectorMenu.begin(); it != m_VectorMenu.end(); ++it)
    {
        it->setPosition(Vector2f(width/2, (height/(m_VectorMenu.size() + 2)) * (it - m_VectorMenu.begin()+1)));
        m_ObjectRect = it->getLocalBounds();
          it->setOrigin(m_ObjectRect.left +
                               m_ObjectRect.width / 2.0f,
                               m_ObjectRect.top +
                               m_ObjectRect.height / 2.0f);
    }
}
