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
    Text text;                  // Create a Text object in SFML
    Font font;                  // Set the font
    FloatRect objectRect;               // Used to move location origin of object
    inline void centreText();
public:
    PauseText(int width, int height, String fontPath);
    Text getText();
    void setString(String);
    void reset();
};

#endif /* PauseText_h */
