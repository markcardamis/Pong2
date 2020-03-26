//
//  ConfigurationManager.h
//  Pong2
//
//  Created by Mark Cardamis on 26/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Window.hpp>
#include "SoundManager.h"
#include "Ball.h"
#include "Paddle.h"
#include "MenuText.h"
#include "ScoreText.h"
#include "PauseText.h"
#include "OptionsText.h"

class GameManager 
{
private:
    sf::RenderWindow* m_Parent;
    SoundManager* m_SoundManager;

    int m_GameState;
    int m_GameDifficulty;
    bool m_AiMode;
    bool m_IsPlayer2OnLeft;
    
public:
    GameManager(sf::RenderWindow* parent, SoundManager* SoundManager);
    ~GameManager(){};

    enum GAME_STATE { 
        GAME_STOPPED = 0, 
        GAME_PAUSED = 1, 
        GAME_RUNNING = 2, 
        GAME_OPTIONS = 3, 
        GAME_WON = 4
    };

    enum GAME_DIFFICULTY { 
        GAME_EASY = 0, 
        GAME_MEDIUM = 1, 
        GAME_HARD = 2
    };

    void run();
};

#endif // GAMEMANAGER_H
