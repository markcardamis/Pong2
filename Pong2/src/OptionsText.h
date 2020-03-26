//
//  OptionsText.h
//  Pong2
//
//  Created by Mark Cardamis on 24/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef OptionsText_h
#define OptionsText_h

using namespace sf;

class OptionsText
{
private:
    std::vector<Text> m_VectorMenu;       // Create and store menu items as a Text array in SFML
    Text m_Text;                          // Create a local Text object
    Font m_Font;                          // Set the font
    FloatRect m_ObjectRect;               // Used to move location origin of object
    int m_SelectedItemIndex;              // Variable to store the selected menu item
    void _addString(String string, float width, float height); // Add Text to Vector
    Text _centreOrigin(Text textObject);                       // Change Origin of Text Object
    void _verticallySpaceText(float width, float height);      // Vertically space the MenuText objects

public:
    OptionsText(float width, float height, String fontPath);
    ~OptionsText();
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedItem();
};

#endif /* OptionsText_h */
