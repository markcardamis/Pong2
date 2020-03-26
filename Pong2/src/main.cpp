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
#include "Constants.h"
#include "MenuText.h"
#include "PauseText.h"
#include "ScoreText.h"
#include "OptionsText.h"
#include "Ball.h"
#include "Paddle.h"
#include "SoundManager.h"
#include "GameManager.h"
#include "ConfigurationManager.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Read in our config
    ConfigurationManager* configManager = ConfigurationManager::createInstance("./resources/config.txt");

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(configManager->getGameWidth(), configManager->getGameHeight(), 32), "Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
        
    // Load the sounds used in the game
    SoundManager soundManager = SoundManager();
    soundManager.play(SoundManager::SOUNDMANAGER_BACKGROUND);

    GameManager gameManager(&window, &soundManager);
    gameManager.run();

    return EXIT_SUCCESS;
}
