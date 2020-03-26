//
//  ConfigurationManager.h
//  Pong2
//
//  Created by Mark Cardamis on 26/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <SFML/Graphics.hpp>
#include <string>

class ConfigurationManager 
{
private:
    static ConfigurationManager* m_pInstance;
    void read(const char* filePath);
    void interpolateValue(std::string key, std::string value);
    float m_Pi = 3.14159f;
    int m_GameWidth = 1024;
    int m_GameHeight = 768;
    sf::Vector2f m_PaddleSize;
    float m_PaddleSpeed;
    float m_BallSpeed;
    float m_BallRadius;
    sf::Keyboard::Key m_PlayerOneUpKey;
    sf::Keyboard::Key m_PlayerOneDownKey;
    sf::Keyboard::Key m_PlayerTwoUpKey;
    sf::Keyboard::Key m_PlayerTwoDownKey;
    sf::String m_FontPath;
    sf::String m_BackgroundSoundPath;
    sf::String m_PaddleSoundPath;
    sf::String m_WallSoundPath;
    sf::String m_ScoreSoundPath;
    
public:
    static ConfigurationManager* createInstance(const char* configPath);
    static ConfigurationManager* getInstance();
    ~ConfigurationManager();

    // Getters
    inline float getPi() const { return m_Pi; }
    inline int getGameWidth() const { return m_GameWidth; }
    inline int getGameHeight() const { return m_GameHeight; }
    inline sf::Vector2f getPaddleSize() const { return m_PaddleSize; }
    inline float getPaddleSpeed() const { return m_PaddleSpeed; }
    inline float getBallSpeed() const { return m_BallSpeed; }
    inline float getBallRadius() const { return m_BallRadius; }
    inline sf::Keyboard::Key getPlayerOneUpKey() const { return m_PlayerOneUpKey; }
    inline sf::Keyboard::Key getPlayerOneDownKey() const { return m_PlayerOneDownKey; }
    inline sf::Keyboard::Key getPlayerTwoUpKey() const { return m_PlayerTwoUpKey; }
    inline sf::Keyboard::Key getPlayerTwoDownKey() const { return m_PlayerTwoDownKey; }
    inline sf::String getFontPath() const { return m_FontPath; }
    inline sf::String getBackgroundSoundPath() const { return m_BackgroundSoundPath; }
    inline sf::String getPaddleSoundPath() const { return m_PaddleSoundPath; }
    inline sf::String getWallSoundPath() const { return m_WallSoundPath; }
    inline sf::String getScoreSoundPath() const { return m_ScoreSoundPath; }

    // Setters
    inline void setPi(float pi) { m_Pi = pi; }
    inline void setGameWidth(int width) { m_GameWidth = width; }
    inline void setGameHeight(int height) { m_GameHeight = height; }
    inline void setPaddleSize(sf::Vector2f size) { m_PaddleSize = size; }
    inline void setPaddleSpeed(float speed) { m_PaddleSpeed = speed; }
    inline void setBallSpeed(float speed) { m_BallSpeed = speed; }
    inline void setBallRadius(float radius) { m_BallRadius = radius; }
    inline void setPlayerOneUpKey(sf::Keyboard::Key key) { m_PlayerOneUpKey = key; }
    inline void setPlayerOneDownKey(sf::Keyboard::Key key) { m_PlayerOneDownKey = key; }
    inline void setPlayerTwoUpKey(sf::Keyboard::Key key) { m_PlayerTwoUpKey = key; }
    inline void setPlayerTwoDownKey(sf::Keyboard::Key key) { m_PlayerTwoDownKey = key; }
    inline void setFontPath(sf::String path) { m_FontPath = path; }
    inline void setBackgroundSoundPath(sf::String path) { m_BackgroundSoundPath = path; }
    inline void setPaddleSoundPath(sf::String path) { m_PaddleSoundPath = path; }
    inline void setWallSoundPath(sf::String path) { m_WallSoundPath = path; }
    inline void setScoreSoundPath(sf::String path) { m_ScoreSoundPath = path; }
};

#endif // CONFIGREADER_H
