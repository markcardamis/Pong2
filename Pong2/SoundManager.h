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
    SoundBuffer bufferBackground;
    SoundBuffer bufferPaddle;
    SoundBuffer bufferWall;
    SoundBuffer bufferScore;
    Sound soundBackground;
    Sound soundPaddle;
    Sound soundWall;
    Sound soundScore;
    enumSound soundSelect;
public:
    SoundManager();
    void play(enumSound eSound);
};

#endif /* SoundManager_h */
