//
//  MenuText.h
//  Pong2
//
//  Created by Mark Cardamis on 7/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef MenuText_h
#define MenuText_h

#define MAX_MENU_ITEMS 4

using namespace sf;

class MenuText
{
private:
    Text text[MAX_MENU_ITEMS];          // Create and store menu items as a Text array in SFML
    Font font;                          // Set the font
    FloatRect objectRect;               // Used to move location origin of object
    int selectedItemIndex = 0;          // Variable to store the score
    inline void centreText(int i);

public:
    MenuText(float width, float height, String fontPath);
    ~MenuText();
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedItem();
};
#endif /* MenuText_h */
