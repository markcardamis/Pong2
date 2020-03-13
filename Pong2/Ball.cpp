//
//  Ball.cpp
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Constants.h"

Ball::Ball(float ballRadius, float ballSpeed, int gameWidth, int gameHeight)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    m_Ball.setRadius(ballRadius);
    m_Ball.setFillColor(Color::White);
    m_Ball.setOrigin(m_Ball.getGlobalBounds().width/2, m_Ball.getGlobalBounds().height/2);
    m_OriginalSpeed = ballSpeed;
    m_Speed = ballSpeed;
    m_xLimit = gameWidth;
    m_yLimit = gameHeight;
    reset();
}

Ball::~Ball()
{
    
}

void Ball::draw(sf::RenderWindow &window)
{
    window.draw(m_Ball);
}

void Ball::reset(enumBallDirection ballDirection)
{
    setPosition(m_xLimit / 2, m_yLimit / 2);
    setSpeed(m_OriginalSpeed); // Reset Ball speed
    
    float ballAngle;
    do
    {
        // Make sure the ball initial angle is not too much vertical
        ballAngle = std::rand() % 360 * 2 * pi / 360;
    }
    while (std::cos(ballAngle) < 0.7f);
        
    switch (ballDirection)
    {
    case BALL_INITIAL:
        setAngle(ballAngle);
        break;
    case BALL_RIGHT:
        setAngle(ballAngle);
        break;
    case BALL_LEFT:
        setAngle(ballAngle+pi);
        break;
    default:
        setAngle(ballAngle);
        break;
    }

}

void Ball::setPosition(float x, float y)
{
    m_Ball.setPosition(x, y);
}

float Ball::getAngle()
{
    return m_Angle;
}

void Ball::setAngle(float ballAngle)
{
    m_Angle = ballAngle;
}

void Ball::move(float offsetX, float offsetY)
{
    m_Ball.move(offsetX, offsetY);
}

void Ball::move(float deltaTime)
{
    float factor = m_Speed * deltaTime;
    move(std::cos(getAngle()) * factor, std::sin(getAngle()) * factor);
}

void Ball::reboundWall(enumBallDirection ballDirection)
{
    float reboundAngle = -1*getAngle();
    setAngle(reboundAngle);
    if (ballDirection == BALL_DOWN) // Rebound down
    {
        m_Ball.setPosition(getPositionX(), getRadius() + 0.1f);
    }
    else if (ballDirection == BALL_UP) // Rebound up
    {
        m_Ball.setPosition(getPositionX(), m_yLimit - getRadius() - 0.1f);
    }
}

void Ball::reboundPaddle(Paddle& paddle)
{
    // If ball hits bottom half of paddle add more down angle
    if (getPositionY() > paddle.getPositionY())
    {
        setAngle(PI - getAngle() + (std::rand() % 20) * PI / 180);
    }
    else // If ball hits top half of paddle then add more up angle
    {
        setAngle(PI - getAngle() - (std::rand() % 20) * PI / 180);
    }
    
    setSpeed(getSpeed()+10); // Increase ball speed
    
    if (getPositionX() < m_xLimit/2) //Left Paddle
    {
        setPosition(paddle.getMaxPositionX() + getRadius() + 0.1f, getPositionY());
    }
    else //Right Paddle
    {
        setPosition(paddle.getMinPositionX() - getRadius() - 0.1f, getPositionY());
    }
    
}

void Ball::setSpeed(float ballSpeed)
{
    m_Speed = ballSpeed;
}

float Ball::getSpeed()
{
    return m_Speed;
}

float Ball::getPositionX()
{
    return m_Ball.getPosition().x;
}

float Ball::getPositionY()
{
    return m_Ball.getPosition().y;
}

float Ball::getRadius()
{
    return m_Ball.getRadius();
}

float Ball::getMinPositionX()
{
    return getPositionX() - getRadius();
}

float Ball::getMaxPositionX()
{
    return getPositionX() + getRadius();
}

float Ball::getMinPositionY()
{
    return getPositionY() - getRadius();
}

float Ball::getMaxPositionY()
{
    return getPositionY() + getRadius();
}

bool Ball::isBallMovingLeft()
{
    return (std::cos(getAngle()) < 0? true: false);
}


