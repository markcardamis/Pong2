//
//  ConfigurationManager.cpp
//  Pong2
//
//  Created by Mark Cardamis on 26/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include "ConfigurationManager.h"
#include "Constants.h"
#include <fstream>
#include <sstream>
#include <iostream>

ConfigurationManager* ConfigurationManager::m_pInstance = NULL;

ConfigurationManager* ConfigurationManager::createInstance(const char* configPath)
{
    m_pInstance = new ConfigurationManager;
    m_pInstance->setPi(PI);
    m_pInstance->setGameWidth(GAME_WIDTH);
    m_pInstance->setGameHeight(GAME_HEIGHT);
    m_pInstance->setPaddleSize(PADDLE_SIZE);
    m_pInstance->setPaddleSpeed(PADDLE_SPEED);
    m_pInstance->setBallSpeed(BALL_SPEED);
    m_pInstance->setBallRadius(BALL_RADIUS);
    m_pInstance->setPlayerOneUpKey(PLAYER1_UP_KEY);
    m_pInstance->setPlayerOneDownKey(PLAYER1_DOWN_KEY);
    m_pInstance->setPlayerTwoUpKey(PLAYER2_UP_KEY);
    m_pInstance->setPlayerTwoDownKey(PLAYER2_DOWN_KEY);
    m_pInstance->setFontPath(FONT_PATH);
    m_pInstance->setBackgroundSoundPath(BACKGROUND_SOUND_PATH);
    m_pInstance->setPaddleSoundPath(PADDLE_SOUND_PATH);
    m_pInstance->setWallSoundPath(WALL_SOUND_PATH);

    m_pInstance->read(configPath);

    return m_pInstance;
}

void ConfigurationManager::interpolateValue(std::string key, std::string value)
{   
    std::cout << key << " : " << value << std::endl;
    if (key == "PI") {
        setPi(std::stof(value));
    } else if (key == "GAME_WIDTH") {
        setGameWidth(std::stoi(value));
    } else if (key == "GAME_HEIGHT") {
        setGameHeight(std::stoi(value));
    } else if (key == "PADDLE_SIZE") {
        std::string x;
        std::string y;
        std::istringstream valueStream(value);
        if (
            std::getline(valueStream, x, ',') && 
            std::getline(valueStream, y)
        ) {
            sf::Vector2f vec2(std::stof(x), std::stof(y));
            setPaddleSize(vec2);
        }
    } else if (key == "PADDLE_SPEED") {
        setPaddleSpeed(std::stof(value));
    } else if (key == "BALL_SPEED") {
        setBallSpeed(std::stof(value));
    } else if (key == "BALL_RADIUS") {
        setBallRadius(std::stof(value));
    } else if (key == "PLAYER1_UP_KEY") {
        setPlayerOneUpKey((sf::Keyboard::Key) std::stoi(value));
    } else if (key == "PLAYER1_DOWN_KEY") {
        setPlayerOneDownKey((sf::Keyboard::Key) std::stoi(value));
    } else if (key == "PLAYER2_UP_KEY") {
        setPlayerTwoUpKey((sf::Keyboard::Key) std::stoi(value));
    } else if (key == "PLAYER2_DOWN_KEY") {
        setPlayerTwoDownKey((sf::Keyboard::Key) std::stoi(value));
    } else if (key == "FONT_PATH") {
        setFontPath(value);
    } else if (key == "BACKGROUND_SOUND_PATH") {
        setBackgroundSoundPath(value);
    } else if (key == "PADDLE_SOUND_PATH") {
        setPaddleSoundPath(value);
    } else if (key == "WALL_SOUND_PATH") {
        setWallSoundPath(value);
    } else if (key == "SCORE_SOUND_PATH") {
        setScoreSoundPath(value);
    }
}

void ConfigurationManager::read(const char* filePath)
{
    std::fstream fileStream;
    fileStream.open(filePath, std::ios::in);

    if (fileStream.fail() || fileStream.bad()) {
        return;
    }

    std::string line;
    while (std::getline(fileStream, line))
    {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '='))
        {
            std::string value;
            if (key[0] == '#')
                continue;

            if (std::getline(is_line, value))
            {
                interpolateValue(key, value);
            }
        }
    }

    fileStream.close();
}

ConfigurationManager* ConfigurationManager::getInstance()
{
    if (m_pInstance) {
        return m_pInstance;   
    }

    return nullptr;
}

ConfigurationManager::~ConfigurationManager()
{
    if (m_pInstance) {
        delete m_pInstance;
    }
}
