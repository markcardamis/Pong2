//
//  Paddle.cpp
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "Paddle.h"

Paddle::Paddle(Vector2f paddleSize, float paddleSpeed, int gameWidth, int gameHeight, enumPaddlePlayer paddlePlayer)
{
    paddle.setSize(paddleSize);
    paddle.setOutlineThickness(1);
    paddle.setOutlineColor(Color::Black);
    paddle.setFillColor(sf::Color::White);
    paddle.setOrigin(paddleSize / 2.f);
    oSpeed = paddleSpeed;
    speed = paddleSpeed;
    xLimit = gameWidth;
    yLimit = gameHeight;
    paddleNumber = paddlePlayer;
}

RectangleShape Paddle::getPaddle()
{
    return paddle;
}

void Paddle::reset()
{
    switch (paddleNumber)
    {
    case PADDLE_LEFT:
        setPosition(paddleXBuffer + getHalfPaddleWidth(), yLimit / 2);
        break;
    case PADDLE_RIGHT:
        setPosition(xLimit - paddleXBuffer - getHalfPaddleWidth(), yLimit / 2);
        break;
    case PADDLE_LEFT_2:
        setPosition(10*paddleXBuffer + getHalfPaddleWidth(), yLimit / 2);
        break;
    default:
        break;
    }
}

void Paddle::setPosition(float x, float y)
{
    paddle.setPosition(x, y);
}

void Paddle::move(float offsetX, float offsetY)
{
    paddle.move(offsetX, offsetY);
}

void Paddle::setSpeed(float paddleSpeed)
{
    speed = paddleSpeed;
}

float Paddle::getSpeed()
{
    return speed;
}

float Paddle::getPositionX()
{
    return paddle.getPosition().x;
}

float Paddle::getPositionY()
{
    return paddle.getPosition().y;
}

void Paddle::moveUp(float deltaTime)
{
    if (getPositionY() - getHalfPaddleHeight() > paddleYBuffer)
    {
        move(0.f, -speed * deltaTime);
    }
}

void Paddle::moveDown(float deltaTime)
{
    if (getPositionY() + getHalfPaddleHeight() < yLimit - paddleYBuffer)
    {
        move(0.f, speed * deltaTime);
    }
}

void Paddle::autoMove(float deltaTime) // Move the computer's paddle
{
    if (((getSpeed() < 0.f) && (getPositionY() - getHalfPaddleHeight() > paddleYBuffer)) ||
            ((getSpeed() > 0.f) && (getPositionY() + getHalfPaddleHeight() < yLimit - paddleYBuffer)))
        {
            move(0.f, getSpeed() * deltaTime);
        }
}

void Paddle::autoSetDirection(float ballPositionY, float ballRadius)
{
    if (ballPositionY + ballRadius > getPositionY() + getHalfPaddleHeight())
    {
        setSpeed(oSpeed);
    }
    else if (ballPositionY - ballRadius < getPositionY() - getHalfPaddleHeight())
    {
        setSpeed(-oSpeed);
    }
    else
    {
        setSpeed(0.f);
    }
}

float Paddle::getHalfPaddleWidth()
{
    return paddle.getSize().x/2;
}

float Paddle::getHalfPaddleHeight()
{
    return paddle.getSize().y/2;
}

