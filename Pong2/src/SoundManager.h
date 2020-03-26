//
//  SoundManager.h
//  Pong2
//
//  Created by Mark Cardamis on 5/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef SoundManager_h
#define SoundManager_h

using namespace sf;

enum enumSound { SOUNDMANAGER_BACKGROUND = 0, SOUNDMANAGER_PADDLE = 1, SOUNDMANAGER_WALL = 2, SOUNDMANAGER_SCORE = 3 };

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
    enumSound m_SoundSelect;
public:
    SoundManager();
    void play(enumSound eSound);
};

#endif /* SoundManager_h */
