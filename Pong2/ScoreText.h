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
    Text text;                          // Create and store a score as a Text in SFML
    Font font;                          // Set the font
    FloatRect objectRect;               // Used to move location origin of object
    enumPlayer player;                  // Set the player for correct text position on screen
    int scoreNumber = 0;                // Variable to store the score
    int xLimit;                         // Use the x-axis range to draw the Text inside the screen
    int yLimit;                         // Use the y-axis range to draw the Text inside the screen
    inline void setString(int);
    inline void setString(String);
    inline void centreText();
public:
    ScoreText(int gameWidth, int gameHeight, enumPlayer playerNumber, String fontPath);
    Text getText();
    int getScore();
    void reset();
    void add();
};
#endif /* ScoreText_h */
