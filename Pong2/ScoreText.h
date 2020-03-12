//
//  ScoreText.h
//  Pong2
//
//  Created by Mark Cardamis on 7/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef ScoreText_h
#define ScoreText_h

using namespace sf;

enum enumPlayer { PLAYER_LEFT = 0, PLAYER_RIGHT = 1};

class ScoreText
{
private:
    Text m_Text;                          // Create and store a score as a Text in SFML
    Font m_Font;                          // Set the font
    FloatRect m_ObjectRect;               // Used to move location origin of object
    enumPlayer m_Player;                  // Set the player for correct text position on screen
    int m_ScoreNumber = 0;                // Variable to store the score
    int m_xLimit;                         // Use the x-axis range to draw the Text inside the screen
    int m_yLimit;                         // Use the y-axis range to draw the Text inside the screen
    inline void m_SetString(int);
    inline void m_SetString(String);
    inline void m_CentreText();
public:
    ScoreText(int gameWidth, int gameHeight, enumPlayer playerNumber, String fontPath);
    Text getText();
    int getScore();
    void reset();
    void add();
};
#endif /* ScoreText_h */
