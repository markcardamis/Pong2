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
    m_BufferBackground.loadFromFile(BACKGROUND_SOUND_PATH);
    m_BufferPaddle.loadFromFile(PADDLE_SOUND_PATH);
    m_BufferWall.loadFromFile(WALL_SOUND_PATH);
    m_BufferScore.loadFromFile(SCORE_SOUND_PATH);
    m_SoundBackground.setBuffer(m_BufferBackground);
    m_SoundPaddle.setBuffer(m_BufferPaddle);
    m_SoundWall.setBuffer(m_BufferWall);
    m_SoundScore.setBuffer(m_BufferScore);
}

void SoundManager::play(int eSound)
{
    switch (eSound)
    {
    case SOUNDMANAGER_BACKGROUND:
        m_SoundBackground.setLoop(true);
        m_SoundBackground.play();
        break;
    case SOUNDMANAGER_PADDLE:
        m_SoundPaddle.play();
        break;
    case SOUNDMANAGER_WALL:
        m_SoundWall.play();
        break;
    case SOUNDMANAGER_SCORE:
        m_SoundScore.play();
        break;
    default:
        m_SoundBackground.stop();
        m_SoundPaddle.stop();
        m_SoundWall.stop();
        m_SoundScore.stop();
        break;
    }
}
