#ifndef HARDBIRD_H
#define HARDBIRD_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Texture.h"
#include "constant.h"
#include "Bird.h"

using namespace std;

class HardBird: public Bird
{
public:
    HardBird();
    ~HardBird();
};

#endif // HARDBIRD_H
