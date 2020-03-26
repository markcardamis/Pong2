//
//  SoundManager.h
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef SoundManager_h
#define SoundManager_h

#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager
{
private:
    SoundBuffer m_BufferBackground;
    SoundBuffer m_BufferPaddle;
    SoundBuffer m_BufferWall;
    SoundBuffer m_BufferScore;
    Sound m_SoundBackground;
    Sound m_SoundPaddle;
    Sound m_SoundWall;
    Sound m_SoundScore;
    int m_SoundSelect;
public:
    SoundManager();
    void play(int eSound);

    enum { 
        SOUNDMANAGER_BACKGROUND = 0, 
        SOUNDMANAGER_PADDLE = 1, 
        SOUNDMANAGER_WALL = 2, 
        SOUNDMANAGER_SCORE = 3 
    };
};

#endif /* SoundManager_h */
