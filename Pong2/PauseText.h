//
//  PauseText.h
//  Pong2
//
//  Created by Mark Cardamis on 8/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef PauseText_h
#define PauseText_h

using namespace sf;

class PauseText
{
private:
    Text m_Text;                  // Create a Text object in SFML
    Font m_Font;                  // Set the font
    FloatRect m_ObjectRect;               // Used to move location origin of object
    inline void inline_centreOrigin(); // Change Origin of Text Object
public:
    PauseText(int width, int height, String fontPath);
    ~PauseText();
    void draw(sf::RenderWindow &window);
    void setString(String);
    void reset();
};

#endif /* PauseText_h */
