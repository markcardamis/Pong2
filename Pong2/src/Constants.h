
//
//  Constants.h
//  Pong2
//
//  Created by Mark Cardamis on 7/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include <SFML/Graphics.hpp>

// Define some constants
const float PI = 3.14159f;
const int GAME_WIDTH = 1024;
const int GAME_HEIGHT = 768;
const sf::Vector2f PADDLE_SIZE(24, 100);
const float PADDLE_SPEED = 400.f;
const float BALL_SPEED = 600.f;
const float BALL_RADIUS = 10.f;
const sf::Keyboard::Key PLAYER1_UP_KEY = sf::Keyboard::W;
const sf::Keyboard::Key PLAYER1_DOWN_KEY = sf::Keyboard::S;
const sf::Keyboard::Key PLAYER2_UP_KEY = sf::Keyboard::I;
const sf::Keyboard::Key PLAYER2_DOWN_KEY = sf::Keyboard::K;
const sf::String FONT_PATH = "resources/sansation.ttf";
const sf::String BACKGROUND_SOUND_PATH = "sound/music.wav";
const sf::String PADDLE_SOUND_PATH = "sound/paddle.wav";
const sf::String WALL_SOUND_PATH = "sound/wall.wav";
const sf::String SCORE_SOUND_PATH = "sound/score.wav";

#endif /* Constants_h */
