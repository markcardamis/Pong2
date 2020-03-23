//
//  OptionsText.cpp
//  Pong2
//
//  Created by Mark Cardamis on 24/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "OptionsText.h"

OptionsText::OptionsText(float width, float height, String fontPath)
{
    // Set default text options
    m_Font.loadFromFile(fontPath);
    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(height/18);     // Set dynamic font size based on height
    m_SelectedItemIndex = 1;                // Set selected index to 1 not to highlight first option
    
    _addString("Set Difficulty then press Enter", width, height);
    _addString("Easy", width, height);
    _addString("Medium", width, height);
    _addString("Hard", width, height);

}

OptionsText::~OptionsText()
{
    
}

void OptionsText::draw(sf::RenderWindow &window)
{
    
    for (std::vector<Text>::iterator it = m_VectorMenu.begin(); it != m_VectorMenu.end(); ++it)
    {
        window.draw(*it);
    }
    
}

void OptionsText::moveUp()
{
    if (m_SelectedItemIndex >= 0)
    {
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::White);
        m_SelectedItemIndex--;
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::Red);
    }
}

void OptionsText::moveDown()
{
    if (m_SelectedItemIndex + 1 < m_VectorMenu.size())
    {
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::White);
        m_SelectedItemIndex++;
        m_VectorMenu[m_SelectedItemIndex].setFillColor(Color::Red);
    }
}

int OptionsText::getSelectedItem()
{
    return (m_SelectedItemIndex - 1); // subtract 1 as first item is non selectable
}

void OptionsText::_addString(String input, float width, float height)
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

Text OptionsText::_centreOrigin(Text textObject)
{
    m_ObjectRect = textObject.getLocalBounds();
    textObject.setOrigin(m_ObjectRect.left +
                        m_ObjectRect.width / 2.0f,
                        m_ObjectRect.top +
                        m_ObjectRect.height / 2.0f);
    return textObject;
}

void OptionsText::_verticallySpaceText(float width, float height)
{
    // Use iterator to run through the Vector of type Text and
    for (auto it = m_VectorMenu.begin(); it != m_VectorMenu.end(); ++it)
    {
        it->setPosition(Vector2f(width/2, (height/(m_VectorMenu.size() + 2)) * (it - m_VectorMenu.begin()+1)));
        m_ObjectRect = it->getLocalBounds();
          it->setOrigin(m_ObjectRect.left +
                               m_ObjectRect.width / 2.0f,
                               m_ObjectRect.top +
                               m_ObjectRect.height / 2.0f);
    }
}

