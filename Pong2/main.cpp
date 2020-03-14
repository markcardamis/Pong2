
//
//  main.cpp
//  Pong2
//
//  Created by Mark Cardamis on 05/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "MenuText.h"
#include "PauseText.h"
#include "ScoreText.h"
#include "Ball.h"
#include "Paddle.h"
#include "SoundManager.h"

enum enumState { GAME_STOPPED = 0, GAME_PAUSED = 1, GAME_RUNNING = 2, GAME_WON = 3 };

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    
    enumState gameState = GAME_STOPPED;
    bool aiMode = false;
    bool isPlayer2OnLeft = false;
    
    sf::Clock clock;
    sf::Clock AITimer;
    const sf::Time AITime   = sf::seconds(0.1f);
    

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
        
    // Load the sounds used in the game
    SoundManager soundManager = SoundManager();
    soundManager.play(SOUNDMANAGER_BACKGROUND);

    // Create the Paddle and the Ball classes
    Paddle leftPaddle(PADDLE_SIZE, PADDLE_SPEED, GAME_WIDTH, GAME_HEIGHT, PADDLE_LEFT);
    Paddle leftPaddle2(PADDLE_SIZE, PADDLE_SPEED, GAME_WIDTH, GAME_HEIGHT, PADDLE_LEFT_2);
    Paddle rightPaddle(PADDLE_SIZE, PADDLE_SPEED, GAME_WIDTH, GAME_HEIGHT, PADDLE_RIGHT);
    Ball ball(BALL_RADIUS, BALL_SPEED, GAME_WIDTH, GAME_HEIGHT, PI);
    
    // Create the Text display classes
    MenuText menuText(GAME_WIDTH, GAME_HEIGHT, FONT_PATH);
    ScoreText leftScoreText(GAME_WIDTH, GAME_HEIGHT, LEFT_SCREEN , FONT_PATH);
    ScoreText rightScoreText(GAME_WIDTH, GAME_HEIGHT, RIGHT_SCREEN , FONT_PATH);
    PauseText pauseText(GAME_WIDTH, GAME_HEIGHT, FONT_PATH);


    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Space:
                        if (gameState == GAME_PAUSED)
                        {
                            gameState = GAME_RUNNING;
                            clock.restart();

                           // Reset the position of the paddles and ball
                           leftPaddle.reset();
                           leftPaddle2.reset();
                           rightPaddle.reset();
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (gameState == GAME_STOPPED)
                        {
                            menuText.moveUp();
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (gameState == GAME_STOPPED)
                        {
                            menuText.moveDown();
                        }
                        break;
                    case sf::Keyboard::Enter:
                        if (gameState == GAME_STOPPED)
                        {
                            switch (menuText.getSelectedItem())
                            {
                            case 0:
                                gameState = GAME_PAUSED;
                                aiMode = true;
                                isPlayer2OnLeft = false;
                                break;
                            case 1:
                                gameState = GAME_PAUSED;
                                aiMode = false;
                                isPlayer2OnLeft = false;
                                break;
                            case 2:
                                gameState = GAME_PAUSED;
                                aiMode = true;
                                isPlayer2OnLeft = true;
                                break;
                            case 3:
                                gameState = GAME_STOPPED;
                                window.close();
                                break;
                            default:
                                gameState = GAME_STOPPED;
                                window.close();
                                break;
                            }
                            clock.restart();

                            // Reset the position of the paddles and ball
                            leftPaddle.reset();
                            leftPaddle2.reset();
                            rightPaddle.reset();
                            leftScoreText.reset();
                            rightScoreText.reset();
                            pauseText.reset();
                        } else if (gameState == GAME_WON)
                        {
                            gameState = GAME_STOPPED;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        
        ////////////////////////////////////////////////////////////
        // Inputs
        ////////////////////////////////////////////////////////////

        if (gameState == GAME_RUNNING)
        {
            float deltaTime = clock.restart().asSeconds();

            if (sf::Keyboard::isKeyPressed(PLAYER1_UP_KEY))
            {
                leftPaddle.moveUp(deltaTime);
            }
            
            if (sf::Keyboard::isKeyPressed(PLAYER1_DOWN_KEY))
            {
                leftPaddle.moveDown(deltaTime);
            }
            
            if (isPlayer2OnLeft) // player 2 is on the left
            {
                if (sf::Keyboard::isKeyPressed(PLAYER2_UP_KEY))
                {
                    leftPaddle2.moveUp(deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(PLAYER2_DOWN_KEY))
                {
                    leftPaddle2.moveDown(deltaTime);
                }
            }
            
            if (aiMode)
            {

                rightPaddle.autoMove(deltaTime); // move the Paddle in the current direction

                // Update the computer's paddle direction according to the ball position
                if (AITimer.getElapsedTime() > AITime)
                {
                    AITimer.restart();
                    rightPaddle.autoSetDirection(ball.getPositionY(), ball.getRadius());
                }
            }
            else // player 2 is on the right
            {
                if (sf::Keyboard::isKeyPressed(PLAYER2_UP_KEY))
                {
                    rightPaddle.moveUp(deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(PLAYER2_DOWN_KEY))
                {
                    rightPaddle.moveDown(deltaTime);
                }
            }
            
            ////////////////////////////////////////////////////////////
            // Logic
            ////////////////////////////////////////////////////////////
            
            // Move the ball
            ball.move(deltaTime);

            // Check collisions between the ball and the screen
            if (ball.getMinPositionX() < 0.f)
            {
                gameState = GAME_PAUSED;
                soundManager.play(SOUNDMANAGER_SCORE);
                rightScoreText.add();
                ball.reset(BALL_LEFT);
                if (rightScoreText.getScore() >= 5) {
                    gameState = GAME_WON;
                    pauseText.setString("RIGHT PLAYER won\n\nPress Enter to restart\nPress Escape to exit");
                }
            }
            if (ball.getMaxPositionX() > GAME_WIDTH)
            {
                gameState = GAME_PAUSED;
                soundManager.play(SOUNDMANAGER_SCORE);
                leftScoreText.add();
                ball.reset(BALL_RIGHT);
                if (leftScoreText.getScore() >= 5) {
                    gameState = GAME_WON;
                    pauseText.setString("LEFT PLAYER won\n\nPress Enter to restart\nPress Escape to exit");
                }
            }
            if (ball.getMinPositionY() <= 0.f)
            {
                soundManager.play(SOUNDMANAGER_WALL);
                ball.reboundWall(BALL_DOWN);
            }
            if (ball.getMaxPositionY() >= GAME_HEIGHT)
            {
                soundManager.play(SOUNDMANAGER_WALL);
                ball.reboundWall(BALL_UP);
            }

            // Check the collisions between the ball and the paddles
            // Left Paddle
            if (ball.getMinPositionX() < leftPaddle.getMaxPositionX() &&
                ball.getMaxPositionY() >= leftPaddle.getMinPositionY() &&
                ball.getMinPositionY() <= leftPaddle.getMaxPositionY())
            {
                ball.reboundPaddle(leftPaddle);
                soundManager.play(SOUNDMANAGER_PADDLE);
            }
            
            // Left Paddle Player 2
            if (isPlayer2OnLeft &&
                ball.isBallMovingLeft() &&
                ball.getMinPositionX() < leftPaddle2.getMaxPositionX() &&
                ball.getMaxPositionY() >= leftPaddle2.getMinPositionY() &&
                ball.getMinPositionY() <= leftPaddle2.getMaxPositionY())
            {
                ball.reboundPaddle(leftPaddle2);
                soundManager.play(SOUNDMANAGER_PADDLE);
            }
            

            // Right Paddle
            if (ball.getMaxPositionX() >= rightPaddle.getMinPositionX() &&
                ball.getMaxPositionY() >= rightPaddle.getMinPositionY() &&
                ball.getMinPositionY() <= rightPaddle.getMaxPositionY())
            {
                ball.reboundPaddle(rightPaddle);
                soundManager.play(SOUNDMANAGER_PADDLE);
            }
        }
        
        ////////////////////////////////////////////////////////////
        // Output
        ////////////////////////////////////////////////////////////
        
        // Clear the window
        window.clear(sf::Color::Black);

        switch (gameState)
        {
            case GAME_STOPPED:
                menuText.draw(window);
                break;
            case GAME_PAUSED:
                pauseText.draw(window);
                break;
            case GAME_RUNNING:
                // Draw the paddles and the ball
                leftPaddle.draw(window);
                if (isPlayer2OnLeft)
                {
                    leftPaddle2.draw(window);
                }
                rightPaddle.draw(window);
                leftScoreText.draw(window);
                rightScoreText.draw(window);
                ball.draw(window);
                break;
            case GAME_WON:
                pauseText.draw(window);
                break;
        }

        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
