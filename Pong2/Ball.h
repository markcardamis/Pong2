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

enum enumBallDirection { BALL_STOP = 0, BALL_UP = 1, BALL_DOWN = 2, BALL_LEFT = 3, BALL_RIGHT = 4 };

class Paddle;

class Ball
{
private:
    CircleShape m_Ball;                   // Create and store a Ball as a CircleShape in SFML
    enumBallDirection m_Direction;        // Set an initial direction for ball restarts
    float m_Pi;                           // Save variable PI which is passed in constructor
    float m_Speed;                        // Adjust the speed at which the Ball can move
    float m_OriginalSpeed;                // Save the initial maximum speed to recall after stopping
    float m_Angle = 0.f;                  // Save the angle of trajectory
    float m_Spin = 0.f;                   // Save the spin of the ball
    int m_xLimit;                         // Use the x-axis range to draw the Ball inside the screen
    int m_yLimit;                         // Use the y-axis range to draw the Ball inside the screen
    int m_Difficulty;                     // Variable to set the difficulty properties
    int m_BallAngleFactor;                // Variables to change properties based on difficulty
    int m_BallSpinFactor;
    int m_BallSpeedFactor;
    float _getAngle();
    void _setAngle(float angle);
    void _move(float offsetX, float offsetY);
    void _setPosition(float x, float y);
    float _getSpeed();
    void _setSpeed(float ballSpeed);
    float _getSpin();                      // Get ball spin component
    void _setSpin(float ballSpin);         // Set ball spin to effect bounces
    void _applyDifficulty();                 // Get the current difficulty and set the variables

    
public:
    Ball(float ballRadius, float ballSpeed, int gameWidth, int gameHeight, float pi, int difficulty = 0);
    ~Ball();
    void draw(sf::RenderWindow &window);
    void reset(enumBallDirection ballDirection = BALL_STOP);
    void setDifficulty(int gameDifficulty);
    void move(float deltaTime);
    void reboundWall(enumBallDirection ballDirection);
    void reboundPaddle(Paddle& paddle);
    float getPositionX();
    float getPositionY();
    float getRadius();
    float getMinPositionX();
    float getMaxPositionX();
    float getMinPositionY();
    float getMaxPositionY();
    bool isBallMovingLeft();
};

#endif /* Ball_h */
