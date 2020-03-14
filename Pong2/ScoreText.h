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

enum enumScoreLocation { LEFT_SCREEN = 0, RIGHT_SCREEN = 1};

class ScoreText
{
private:
    Text m_Text;                          // Create and store a score as a Text in SFML
    Font m_Font;                          // Set the font
    FloatRect m_ObjectRect;               // Used to move location origin of object
    enumScoreLocation m_Location;         // Set the location for correct text position on screen
    int m_ScoreNumber;                    // Variable to store the score
    int m_xLimit;                         // Use the x-axis range to draw the Text inside the screen
    int m_yLimit;                         // Use the y-axis range to draw the Text inside the screen
    void _setString(int);
    void _centreOrigin();                 // Change Origin of Text Object
public:
    ScoreText(int gameWidth, int gameHeight, enumScoreLocation playerNumber, String fontPath);
     ~ScoreText();
    void draw(sf::RenderWindow &window);
    int getScore();
    void reset();
    void add();
};
#endif /* ScoreText_h */
