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

static int32_t nzrand() {
    constexpr double max=RAND_MAX+1.;
    return static_cast<int>(std::ceil((rand()+1.)/max));
}

Ball::Ball(float ballRadius, float ballSpeed, int gameWidth, int gameHeight, float pi, int difficulty)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    m_Ball.setRadius(ballRadius);
    m_Ball.setFillColor(Color::White);
    m_Ball.setOrigin(m_Ball.getGlobalBounds().width/2, m_Ball.getGlobalBounds().height/2);
    m_OriginalSpeed = ballSpeed;
    m_Speed = ballSpeed;
    m_xLimit = gameWidth;
    m_yLimit = gameHeight;
    m_Pi = pi;
    setDifficulty(difficulty);
    reset();
}

Ball::~Ball()
{
    
}

void Ball::draw(sf::RenderWindow* window)
{
    window->draw(m_Ball);
}

void Ball::reset(int ballDirection)
{
    _setPosition(m_xLimit / 2, m_yLimit / 2);
    _setSpeed(m_OriginalSpeed); // Reset Ball speed
    
    float ballAngle;
    do
    {
        // Make sure the ball initial angle is not too much vertical
        ballAngle = std::rand() % 360 * 2 * m_Pi / 360;
    }
    while (std::cos(ballAngle) < 0.7f);
        
    switch (ballDirection)
    {
    case BALL_STOP:
        _setAngle(ballAngle);
        break;
    case BALL_RIGHT:
        _setAngle(ballAngle);
        break;
    case BALL_LEFT:
        _setAngle(ballAngle + m_Pi);
        break;
    default:
        _setAngle(ballAngle);
        break;
    }

}

void Ball::setDifficulty(int gameDifficulty)
{
    m_Difficulty = gameDifficulty;
    _applyDifficulty();
}

void Ball::_applyDifficulty()
{
    switch (m_Difficulty)
    {
    case 0: // Easy
        m_BallAngleFactor = 1;
        m_BallSpinFactor = 1;
        m_BallSpeedFactor = 1;
        break;
    case 1: // Medium
        m_BallAngleFactor = 20;
        m_BallSpinFactor = 20;
        m_BallSpeedFactor = 10;
        break;
    case 2: // Hard
        m_BallAngleFactor = 25;
        m_BallSpinFactor = 25;
        m_BallSpeedFactor = 20;
        break;
    default:
        break;
    }
}

void Ball::move(float deltaTime)
{
    float factor = m_Speed * deltaTime;
    _move(std::cos(_getAngle()) * factor, std::sin(_getAngle()) * factor);
}

void Ball::reboundWall(int ballDirection)
{
    
    float reboundAngle = -1*(_getAngle() + _getSpin());
    _setAngle(reboundAngle);
    if (ballDirection == BALL_DOWN) // Rebound down
    {
        _setPosition(getPositionX(), getRadius() + 0.1f);
    }
    else if (ballDirection == BALL_UP) // Rebound up
    {
        _setPosition(getPositionX(), m_yLimit - getRadius() - 0.1f);
    }
}

void Ball::reboundPaddle(Paddle& paddle)
{
    
    ////////////////////////////////////////////////////////////
    // Ball Angle
    ////////////////////////////////////////////////////////////
    
    // If ball hits bottom half of paddle add more down angle
    if (getPositionY() > paddle.getPositionY())
    {
        _setAngle(m_Pi - _getAngle() + ((std::rand() % m_BallAngleFactor) + .1) * m_Pi / 180 + _getSpin());
    }
    else // If ball hits top half of paddle then add more up angle
    {
        _setAngle(m_Pi - _getAngle() - ((std::rand() % m_BallAngleFactor) + .1) * m_Pi / 180 + _getSpin());
    }
    // Add clockwise ball spin
    if ((paddle.isPaddleOnLeft() && paddle.getPaddleDirection() == Paddle::PADDLE_UP) ||
        (!paddle.isPaddleOnLeft() && paddle.getPaddleDirection() == Paddle::PADDLE_DOWN))
    {
        _setSpin(_getSpin() - (paddle.getSpeed()/_getSpeed()) * m_BallSpinFactor * m_Pi / 180);// add 20 degrees of paddle/ball speed ratio
    } // Add anti-clockwise ball spin
    else if ((paddle.isPaddleOnLeft() && paddle.getPaddleDirection() == Paddle::PADDLE_DOWN) ||
        (!paddle.isPaddleOnLeft() && paddle.getPaddleDirection() == Paddle::PADDLE_UP))
    {
        _setSpin(_getSpin() + (paddle.getSpeed()/_getSpeed()) * m_BallSpinFactor * m_Pi / 180);// add 20 degrees of paddle/ball speed ratio
    }

    ////////////////////////////////////////////////////////////
    // Ball Position
    ////////////////////////////////////////////////////////////
    
    if (paddle.isPaddleOnLeft()) //Left Paddle
    {
        _setPosition(paddle.getMaxPositionX() + getRadius() + 0.1f, getPositionY());
    }
    else //Right Paddle
    {
        _setPosition(paddle.getMinPositionX() - getRadius() - 0.1f, getPositionY());
    }
    
    ////////////////////////////////////////////////////////////
    // Ball Speed
    ////////////////////////////////////////////////////////////
    
    _setSpeed(_getSpeed() + m_BallSpeedFactor); // Increase ball speed with every paddle collision;

}

bool Ball::isBallMovingLeft()
{
    return std::cos(_getAngle()) < 0;
}

float Ball::_getAngle()
{
    return m_Angle;
}

void Ball::_setAngle(float ballAngle)
{
    m_Angle = ballAngle;
    _setSpin(0.f);
}

void Ball::_move(float offsetX, float offsetY)
{
    m_Ball.move(offsetX, offsetY);
}

void Ball::_setPosition(float x, float y)
{
    m_Ball.setPosition(x, y);
}

float Ball::_getSpeed()
{
    return m_Speed;
}

void Ball::_setSpeed(float ballSpeed)
{
    m_Speed = ballSpeed;
}


float Ball::_getSpin()
{
    return m_Spin;
}

void Ball::_setSpin(float ballSpin)
{
    m_Spin = ballSpin;
}

