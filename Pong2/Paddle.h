//
//  Paddle.h
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef Paddle_h
#define Paddle_h

using namespace sf;

enum enumPaddlePlayer { PADDLE_LEFT = 0, PADDLE_RIGHT = 1, PADDLE_LEFT_2 = 2};

class Paddle
{
private:
    const float m_PaddleXBuffer = 10.f;    // Set horizontal buffer from Paddle to Game wall
    const float m_PaddleYBuffer = 20.f;    // Set vertical buffer from Paddle to Game wall
    RectangleShape m_Paddle;              // Create and store a Paddle as a RectangleShape in SFML
    enumPaddlePlayer m_PaddleNumber;      // Set the paddle number for initial position on screen
    float m_Speed;                        // Adjust the speed at which the Paddle can move
    float m_SpeedOriginal;                       // Save the initial maximum speed to recall after stopping
    int m_xLimit;                         // Use the x-axis range to draw the Paddle inside the screen
    int m_yLimit;                         // Limit y-axis range to stop Paddle moving off screen
    
public:
    Paddle(Vector2f paddleSize, float paddleSpeed, int gameWidth, int gameHeight, enumPaddlePlayer paddlePlayer);
    RectangleShape getPaddle();
    void reset();
    void setPosition(float x, float y);
    void move(float offsetX, float offsetY);
    float getSpeed();
    void setSpeed(float paddleSpeed);
    float getPositionX();
    float getPositionY();
    void moveUp(float deltaTime);
    void moveDown(float deltaTime);
    void autoMove(float deltaTime);
    void autoSetDirection(float ballPositionY, float ballRadius); // Set the Paddle direction to follow the ball
    float getHalfPaddleWidth();  // Helper function to retrieve the width of the Paddle
    float getHalfPaddleHeight(); // Helper function to retrieve the height of the Paddle
};

#endif /* Paddle_h */
