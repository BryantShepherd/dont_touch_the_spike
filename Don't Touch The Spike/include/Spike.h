#ifndef SPIKE_H
#define SPIKE_H

#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <SDL_ttf.h>

//#include "Bird.h"
//#include "Background.h"
//#include "MainControl.h"

using namespace std;

class Spike
{
public:
    Spike();
    ~Spike();
    void loadFromFile(string path, SDL_Renderer* renderer);
    void setSpikesNumber(int &score);
    void free();
    void update(int status, bool hit, int &score);
    void render(int x, int y, int w, int h, SDL_Renderer* renderer, int status);
    void moveSpikes(int i, float dist_x, float dist_y);
    float getX(int i);
    float getY(int i);
    int getWidth();
    int getHeight();
    int getQuality();

protected:
private:
    float *x;
    float *y;
    int quality;
    int width;
    int height;
    SDL_Texture* spike_texture;
};

const int SPIKE_MOVE_DISTANCE = 1;
class SpikeHard : public Spike
{
private:
    int switchDirectionCounter = 0;
protected:
public:
    void hard_update();
};

#endif // SPIKE_H
