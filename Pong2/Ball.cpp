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
    ball.setRadius(ballRadius);
    ball.setFillColor(Color::White);
    ball.setOrigin(ball.getGlobalBounds().width/2, ball.getGlobalBounds().height/2);
    oSpeed = ballSpeed;
    speed = ballSpeed;
    xLimit = gameWidth;
    yLimit = gameHeight;
    reset();
}

CircleShape Ball::getBall()
{
    return ball;
}

void Ball::reset(enumBallDirection ballDirection)
{
    setPosition(xLimit / 2, yLimit / 2);
    setSpeed(oSpeed); // Reset Ball speed
    
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
    ball.setPosition(x, y);
}

float Ball::getAngle()
{
    return angle;
}

void Ball::setAngle(float ballAngle)
{
    angle = ballAngle;
}

void Ball::move(float offsetX, float offsetY)
{
    ball.move(offsetX, offsetY);
}

void Ball::move(float deltaTime)
{
    float factor = speed * deltaTime;
    move(std::cos(getAngle()) * factor, std::sin(getAngle()) * factor);
}

void Ball::setSpeed(float ballSpeed)
{
    speed = ballSpeed;
}

float Ball::getSpeed()
{
    return speed;
}

float Ball::getPositionX()
{
    return ball.getPosition().x;
}

float Ball::getPositionY()
{
    return ball.getPosition().y;
}

float Ball::getRadius()
{
    return ball.getRadius();
}

bool Ball::isBallMovingLeft()
{
    return (std::cos(getAngle()) < 0? true: false);
}

