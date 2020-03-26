//
//  Paddle.cpp
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "Paddle.h"

Paddle::Paddle(Vector2f paddleSize, float paddleSpeed, int gameWidth, int gameHeight, int paddlePlayer)
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

Paddle::~Paddle()
{
    
}

void Paddle::draw(sf::RenderWindow* window)
{
    window->draw(m_Paddle);
    _setPaddleDirection(PADDLE_STOP);
}

void Paddle::reset()
{
    switch (m_PaddleNumber)
    {
    case PADDLE_LEFT:
        _setPosition(m_PaddleXWallBuffer + _getHalfPaddleWidth(), m_yLimit / 2);
        break;
    case PADDLE_RIGHT:
        _setPosition(m_xLimit - m_PaddleXWallBuffer - _getHalfPaddleWidth(), m_yLimit / 2);
        break;
    case PADDLE_LEFT_2:
        _setPosition(m_PaddleXWallBuffer + _getHalfPaddleWidth()*6, m_yLimit / 2);
        break;
    default:
        break;
    }
    _setPaddleDirection(PADDLE_DOWN);
}

void Paddle::move(float offsetX, float offsetY)
{
    m_Paddle.move(offsetX, offsetY);
}

void Paddle::setSpeed(float paddleSpeed)
{
    m_Speed = paddleSpeed;
}

void Paddle::moveUp(float deltaTime)
{
    if (getMinPositionY() > m_PaddleYWallBuffer)
    {
        move(0.f, -m_Speed * deltaTime);
        _setPaddleDirection(PADDLE_UP);
    }
}

void Paddle::moveDown(float deltaTime)
{
    if (getMaxPositionY() < m_yLimit - m_PaddleYWallBuffer)
    {
        move(0.f, m_Speed * deltaTime);
        _setPaddleDirection(PADDLE_DOWN);
    }
}

void Paddle::autoMove(float deltaTime) // Move the computer's paddle
{
    if (((getSpeed() < 0.f) && (getMinPositionY() > m_PaddleYWallBuffer)) ||
            ((getSpeed() > 0.f) && (getMaxPositionY() < m_yLimit - m_PaddleYWallBuffer)))
        {
            move(0.f, getSpeed() * deltaTime);
        }
}

void Paddle::autoSetDirection(float ballPositionY, float ballRadius)
{
    if (ballPositionY + ballRadius > getMaxPositionY())
    {
        setSpeed(m_SpeedOriginal);
        _setPaddleDirection(PADDLE_UP);
    }
    else if (ballPositionY - ballRadius < getMinPositionY())
    {
        setSpeed(-m_SpeedOriginal);
        _setPaddleDirection(PADDLE_DOWN);
    }
    else
    {
        setSpeed(0.f);
        _setPaddleDirection(PADDLE_STOP);
    }
}

bool Paddle::isPaddleOnLeft()
{
    return (m_PaddleNumber != PADDLE_RIGHT? true : false);
}

int Paddle::getPaddleDirection()
{
    return m_PaddleDirection;
}

void Paddle::_setPosition(float x, float y)
{
    m_Paddle.setPosition(x, y);
}

void Paddle::_setPaddleDirection(int paddleDirection)
{
    m_PaddleDirection = paddleDirection;
}

