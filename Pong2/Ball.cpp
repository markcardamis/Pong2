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

bool Ball::isBallMovingLeft()
{
    return (std::cos(getAngle()) < 0? true: false);
}

