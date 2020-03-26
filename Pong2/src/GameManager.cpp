//
//  GameManager.cpp
//  Pong2
//
//  Created by Mark Cardamis on 26/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include "GameManager.h"
#include "ConfigurationManager.h"

GameManager::GameManager(sf::RenderWindow* parent, SoundManager* soundManager) : 
    m_Parent(parent), 
    m_SoundManager(soundManager),
    m_GameState(GAME_STOPPED),
    m_GameDifficulty(GAME_EASY),
    m_AiMode(false),
    m_IsPlayer2OnLeft(false)
{}

void GameManager::run()
{
    sf::Clock clock;
    sf::Clock AITimer;
    const sf::Time AITime = sf::seconds(0.1f);

    ConfigurationManager* configManager = ConfigurationManager::getInstance();

    // Create the Paddle and the m_Ball classes
    Paddle leftPaddle(
        configManager->getPaddleSize(), 
        configManager->getPaddleSpeed(), 
        configManager->getGameWidth(), 
        configManager->getGameHeight(), 
        Paddle::PADDLE_LEFT
    );

    Paddle leftPaddle2(
        configManager->getPaddleSize(), 
        configManager->getPaddleSpeed(), 
        configManager->getGameWidth(), 
        configManager->getGameHeight(), 
        Paddle::PADDLE_LEFT_2
    );

    Paddle rightPaddle(
        configManager->getPaddleSize(), 
        configManager->getPaddleSpeed(), 
        configManager->getGameWidth(), 
        configManager->getGameHeight(), 
        Paddle::PADDLE_RIGHT
    );

    Ball ball(
        configManager->getBallRadius(), 
        configManager->getBallSpeed(), 
        configManager->getGameWidth(), 
        configManager->getGameHeight(), 
        configManager->getPi()
    );
    
    // Create the Text display classes
    MenuText menuText(
        configManager->getGameWidth(), 
        configManager->getGameHeight(), 
        configManager->getFontPath()
    );

    ScoreText leftScoreText(
        configManager->getGameWidth(),
        configManager->getGameHeight(), 
        ScoreText::LEFT_SCREEN, 
        configManager->getFontPath()
    );

    ScoreText rightScoreText(
        configManager->getGameWidth(),
        configManager->getGameHeight(), 
        ScoreText::RIGHT_SCREEN, 
        configManager->getFontPath()
    );

    PauseText pauseText(
        configManager->getGameWidth(),
        configManager->getGameHeight(),
        configManager->getFontPath()
    );

    OptionsText optionsText(
        configManager->getGameWidth(),
        configManager->getGameHeight(),
        configManager->getFontPath()
    );

    while (m_Parent->isOpen())
    {
        // Handle events
        sf::Event event;
        while (m_Parent->pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_Parent->close();
                break;
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Space:
                        if (m_GameState == GAME_PAUSED)
                        {
                            m_GameState = GAME_RUNNING;
                            clock.restart();

                           // Reset the position of the paddles and ball
                           leftPaddle.reset();
                           leftPaddle2.reset();
                           rightPaddle.reset();
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (m_GameState == GAME_STOPPED)
                        {
                            menuText.moveUp();
                        }
                        else if (m_GameState == GAME_OPTIONS)
                        {
                            optionsText.moveUp();
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (m_GameState == GAME_STOPPED)
                        {
                            menuText.moveDown();
                        }
                        else if (m_GameState == GAME_OPTIONS)
                        {
                            optionsText.moveDown();
                        }
                        break;
                    case sf::Keyboard::Enter:
                        if (m_GameState == GAME_STOPPED)
                        {
                            switch (menuText.getSelectedItem())
                            {
                            case 0:
                                m_GameState = GAME_PAUSED;
                                m_AiMode = true;
                                m_IsPlayer2OnLeft = false;
                                break;
                            case 1:
                                m_GameState = GAME_PAUSED;
                                m_AiMode = false;
                                m_IsPlayer2OnLeft = false;
                                break;
                            case 2:
                                m_GameState = GAME_PAUSED;
                                m_AiMode = true;
                                m_IsPlayer2OnLeft = true;
                                break;
                            case 3:
                                m_GameState = GAME_OPTIONS;
                                break;
                            case 4:
                                m_GameState = GAME_STOPPED;
                                m_Parent->close();
                                break;
                            default:
                                m_GameState = GAME_STOPPED;
                                m_Parent->close();
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
                        }
                        else if (m_GameState == GAME_WON ||
                                 m_GameState == GAME_PAUSED) //Jump back to menu screen if press Enter
                        {
                            m_GameState = GAME_STOPPED;
                        }
                        else if (m_GameState == GAME_OPTIONS)
                        {
                            switch (optionsText.getSelectedItem())
                            {
                            case 0:
                                m_GameDifficulty = GAME_EASY;
                                ball.setDifficulty(GAME_EASY);
                                break;
                            case 1:
                                m_GameDifficulty = GAME_MEDIUM;
                                ball.setDifficulty(GAME_MEDIUM);
                                break;
                            case 2:
                                m_GameDifficulty = GAME_HARD;
                                ball.setDifficulty(GAME_HARD);
                                break;
                            }
                            
                            m_GameState = GAME_STOPPED; //Jump back to menu screen with correct difficulty
                        }
                        
                    default:
                        break;
                }
            }
        }
        
        ////////////////////////////////////////////////////////////
        // Inputs
        ////////////////////////////////////////////////////////////

        if (m_GameState == GAME_RUNNING)
        {
            float deltaTime = clock.restart().asSeconds();

            if (sf::Keyboard::isKeyPressed(configManager->getPlayerOneUpKey()))
            {
                leftPaddle.moveUp(deltaTime);
            }
            
            if (sf::Keyboard::isKeyPressed(configManager->getPlayerOneDownKey()))
            {
                leftPaddle.moveDown(deltaTime);
            }
            
            if (m_IsPlayer2OnLeft) // player 2 is on the left
            {
                if (sf::Keyboard::isKeyPressed(configManager->getPlayerTwoUpKey()))
                {
                    leftPaddle2.moveUp(deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(configManager->getPlayerTwoDownKey()))
                {
                    leftPaddle2.moveDown(deltaTime);
                }
            }
            
            if (m_AiMode)
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
                if (sf::Keyboard::isKeyPressed(configManager->getPlayerTwoUpKey()))
                {
                    rightPaddle.moveUp(deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(configManager->getPlayerTwoDownKey()))
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
                m_GameState = GAME_PAUSED;
                m_SoundManager->play(SoundManager::SOUNDMANAGER_SCORE);
                rightScoreText.add();
                ball.reset(Ball::BALL_LEFT);
                if (rightScoreText.getScore() >= 5) {
                    m_GameState = GAME_WON;
                    pauseText.setString("RIGHT PLAYER won\n\nPress Enter to restart\nPress Escape to exit");
                }
            }
            if (ball.getMaxPositionX() > configManager->getGameWidth())
            {
                m_GameState = GAME_PAUSED;
                m_SoundManager->play(SoundManager::SOUNDMANAGER_SCORE);
                leftScoreText.add();
                ball.reset(Ball::BALL_RIGHT);
                if (leftScoreText.getScore() >= 5) {
                    m_GameState = GAME_WON;
                    pauseText.setString("LEFT PLAYER won\n\nPress Enter to restart\nPress Escape to exit");
                }
            }
            if (ball.getMinPositionY() <= 0.f)
            {
                m_SoundManager->play(SoundManager::SOUNDMANAGER_WALL);
                ball.reboundWall(Ball::BALL_DOWN);
            }
            if (ball.getMaxPositionY() >= configManager->getGameHeight())
            {
                m_SoundManager->play(SoundManager::SOUNDMANAGER_WALL);
                ball.reboundWall(Ball::BALL_UP);
            }

            // Check the collisions between the ball and the paddles
            // Left Paddle
            if (ball.getMinPositionX() < leftPaddle.getMaxPositionX() &&
                ball.getMaxPositionY() >= leftPaddle.getMinPositionY() &&
                ball.getMinPositionY() <= leftPaddle.getMaxPositionY())
            {
                ball.reboundPaddle(leftPaddle);
                m_SoundManager->play(SoundManager::SOUNDMANAGER_PADDLE);
            }
            
            // Left Paddle Player 2
            if (m_IsPlayer2OnLeft &&
                ball.isBallMovingLeft() &&
                ball.getMinPositionX() < leftPaddle2.getMaxPositionX() &&
                ball.getMaxPositionY() >= leftPaddle2.getMinPositionY() &&
                ball.getMinPositionY() <= leftPaddle2.getMaxPositionY())
            {
                ball.reboundPaddle(leftPaddle2);
                m_SoundManager->play(SoundManager::SOUNDMANAGER_PADDLE);
            }
            

            // Right Paddle
            if (ball.getMaxPositionX() >= rightPaddle.getMinPositionX() &&
                ball.getMaxPositionY() >= rightPaddle.getMinPositionY() &&
                ball.getMinPositionY() <= rightPaddle.getMaxPositionY())
            {
                ball.reboundPaddle(rightPaddle);
                m_SoundManager->play(SoundManager::SOUNDMANAGER_PADDLE);
            }
        }
        
        ////////////////////////////////////////////////////////////
        // Output
        ////////////////////////////////////////////////////////////
        
        // Clear the window
        m_Parent->clear(sf::Color::Black);

        switch (m_GameState)
        {
            case GAME_STOPPED:
                menuText.draw(m_Parent);
                break;
            case GAME_PAUSED:
                pauseText.draw(m_Parent);
                break;
            case GAME_RUNNING:
                // Draw the paddles and the ball
                leftPaddle.draw(m_Parent);
                if (m_IsPlayer2OnLeft)
                {
                    leftPaddle2.draw(m_Parent);
                }
                rightPaddle.draw(m_Parent);
                leftScoreText.draw(m_Parent);
                rightScoreText.draw(m_Parent);
                ball.draw(m_Parent);
                break;
            case GAME_OPTIONS:
                optionsText.draw(m_Parent);
                break;
            case GAME_WON:
                pauseText.draw(m_Parent);
                break;
        }

        // Display things on screen
        m_Parent->display();
    }
}
