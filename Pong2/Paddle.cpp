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
    m_Paddle.setSize(paddleSize);
    m_Paddle.setOutlineThickness(1);
    m_Paddle.setOutlineColor(Color::Black);
    m_Paddle.setFillColor(sf::Color::White);
    m_Paddle.setOrigin(paddleSize / 2.f);
    m_SpeedOriginal = paddleSpeed;
    m_Speed = paddleSpeed;
    m_xLimit = gameWidth;
    m_yLimit = gameHeight;
    m_PaddleNumber = paddlePlayer;
}

RectangleShape Paddle::getPaddle()
{
    return m_Paddle;
}

void Paddle::reset()
{
    switch (m_PaddleNumber)
    {
    case PADDLE_LEFT:
        setPosition(m_PaddleXBuffer + getHalfPaddleWidth(), m_yLimit / 2);
        break;
    case PADDLE_RIGHT:
        setPosition(m_xLimit - m_PaddleXBuffer - getHalfPaddleWidth(), m_yLimit / 2);
        break;
    case PADDLE_LEFT_2:
        setPosition(10*m_PaddleXBuffer + getHalfPaddleWidth(), m_yLimit / 2);
        break;
    default:
        break;
    }
}

void Paddle::setPosition(float x, float y)
{
    m_Paddle.setPosition(x, y);
}

void Paddle::move(float offsetX, float offsetY)
{
    m_Paddle.move(offsetX, offsetY);
}

void Paddle::setSpeed(float paddleSpeed)
{
    m_Speed = paddleSpeed;
}

float Paddle::getSpeed()
{
    return m_Speed;
}

float Paddle::getPositionX()
{
    return m_Paddle.getPosition().x;
}

float Paddle::getPositionY()
{
    return m_Paddle.getPosition().y;
}

void Paddle::moveUp(float deltaTime)
{
    if (getPositionY() - getHalfPaddleHeight() > m_PaddleYBuffer)
    {
        move(0.f, -m_Speed * deltaTime);
    }
}

void Paddle::moveDown(float deltaTime)
{
    if (getPositionY() + getHalfPaddleHeight() < m_yLimit - m_PaddleYBuffer)
    {
        move(0.f, m_Speed * deltaTime);
    }
}

void Paddle::autoMove(float deltaTime) // Move the computer's paddle
{
    if (((getSpeed() < 0.f) && (getPositionY() - getHalfPaddleHeight() > m_PaddleYBuffer)) ||
            ((getSpeed() > 0.f) && (getPositionY() + getHalfPaddleHeight() < m_yLimit - m_PaddleYBuffer)))
        {
            move(0.f, getSpeed() * deltaTime);
        }
}

void Paddle::autoSetDirection(float ballPositionY, float ballRadius)
{
    if (ballPositionY + ballRadius > getPositionY() + getHalfPaddleHeight())
    {
        setSpeed(m_SpeedOriginal);
    }
    else if (ballPositionY - ballRadius < getPositionY() - getHalfPaddleHeight())
    {
        setSpeed(-m_SpeedOriginal);
    }
    else
    {
        setSpeed(0.f);
    }
}

float Paddle::getHalfPaddleWidth()
{
    return m_Paddle.getSize().x/2;
}

float Paddle::getHalfPaddleHeight()
{
    return m_Paddle.getSize().y/2;
}

