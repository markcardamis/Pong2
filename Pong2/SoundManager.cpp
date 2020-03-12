//
//  SoundManager.cpp
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include <SFML/Audio.hpp>
#include "SoundManager.h"
#include "Constants.h"

SoundManager::SoundManager()
{
    bufferBackground.loadFromFile(BACKGROUND_SOUND_PATH);
    bufferPaddle.loadFromFile(PADDLE_SOUND_PATH);
    bufferWall.loadFromFile(WALL_SOUND_PATH);
    bufferScore.loadFromFile(SCORE_SOUND_PATH);
    soundBackground.setBuffer(bufferBackground);
    soundPaddle.setBuffer(bufferPaddle);
    soundWall.setBuffer(bufferWall);
    soundScore.setBuffer(bufferScore);
}

void SoundManager::play(enumSound eSound)
{
    switch (eSound)
    {
    case SOUNDMANAGER_BACKGROUND:
        soundBackground.setLoop(true);
        soundBackground.play();
        break;
    case SOUNDMANAGER_PADDLE:
        soundPaddle.play();
        break;
    case SOUNDMANAGER_WALL:
        soundWall.play();
        break;
    case SOUNDMANAGER_SCORE:
        soundScore.play();
        break;
    default:
        soundBackground.stop();
        soundPaddle.stop();
        soundWall.stop();
        soundScore.stop();
        break;
    }
}
