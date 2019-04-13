#ifndef SPIKEHARD_H
#define SPIKEHARD_H

#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <SDL_ttf.h>

#include "Bird.h"
#include "Background.h"
#include "MainControl.h"
#include <Spike.h>

const int SPIKE_MOVE_DISTANCE = 1;
class SpikeHard : public Spike
{
private:
    int switchDirectionCounter = 0;
protected:
public:
    void hard_update();
};

#endif //SPIKEHARD_H
