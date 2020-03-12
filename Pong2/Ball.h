//
//  Ball.h
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef Ball_h
#define Ball_h

using namespace sf;

enum enumBallDirection { BALL_INITIAL = 0, BALL_RIGHT = 1, BALL_LEFT = 2 };

class Ball
{
private:
    const float pi = 3.14159f;          // Set PI constant
    CircleShape m_Ball;                   // Create and store a Ball as a CircleShape in SFML
    enumBallDirection m_Direction;        // Set an initial direction for ball restarts
    float m_Speed;                        // Adjust the speed at which the Ball can move
    float m_OriginalSpeed;                       // Save the initial maximum speed to recall after stopping
    float m_Angle = 0.f;                  // Save the angle of trajectory
    int m_xLimit;                         // Use the x-axis range to draw the Ball inside the screen
    int m_yLimit;                         // Use the y-axis range to draw the Ball inside the screen
    
public:
    Ball(float ballRadius, float ballSpeed, int gameWidth, int gameHeight);
    CircleShape getBall();
    void reset(enumBallDirection ballDirection = BALL_INITIAL);
    void setPosition(float x, float y);
    float getAngle();
    void setAngle(float angle);
    void move(float offsetX, float offsetY);
    void move(float deltaTime);
    float getSpeed();
    void setSpeed(float ballSpeed);
    float getPositionX();
    float getPositionY();
    float getRadius();
    bool isBallMovingLeft();
};

#endif /* Ball_h */
