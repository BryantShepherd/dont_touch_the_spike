#ifndef HARDSPIKE_H
#define HARDSPIKE_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Texture.h"
#include "constant.h"
#include "Spike.h"

using namespace std;

class HardSpike: public Spike
{
private:
    int switchDirectionCounter = 0;
protected:
public:
    HardSpike();
    ~HardSpike();
    void moveSpikes(int, float, float);
    void hardUpdate();
};

#endif // HARDSPIKE_H
