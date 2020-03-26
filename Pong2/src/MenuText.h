//
//  MenuText.h
//  Pong2
//
//  Created by Mark Cardamis on 7/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef MenuText_h
#define MenuText_h

using namespace sf;

class MenuText
{
private:
    std::vector<Text> m_VectorMenu;       // Create and store menu items as a Text array in SFML
    Text m_Text;                          // Create a local Text object
    Font m_Font;                          // Set the font
    FloatRect m_ObjectRect;               // Used to move location origin of object
    int m_SelectedItemIndex;              // Variable to store the selected menu item
    void _addString(String string, int width, int height); // Add Text to Vector
    Text _centreOrigin(Text textObject);                       // Change Origin of Text Object
    void _verticallySpaceText(int width, int height);      // Vertically space the MenuText objects

public:
    MenuText(int width, int height, String fontPath);
    ~MenuText();
    void draw(sf::RenderWindow* window);
    void moveUp();
    void moveDown();
    int getSelectedItem();
};
#endif /* MenuText_h */
