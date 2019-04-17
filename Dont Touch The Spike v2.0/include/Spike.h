#ifndef SPIKE_H
#define SPIKE_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Texture.h"
#include "constant.h"

using namespace std;

class Spike: public Texture
{
public:
    Spike();
    ~Spike();

    void loadTexture(SDL_Renderer* renderer);
    void update(int &status, int &score, bool &isHittingWall);

    float getDx(int i);
    float getDy(int i);
    int getSpikeNumber();
    void setSpikeNumber(int &score);

protected:
//    vector <float> dx,dy;   //t khai báo sẵn vận tốc gai cho rồi đấy :D
    int spike_number;
private:

};

class HardSpike: public Spike
{
private:
    int switchDirectionCounter = 0;
protected:
public:
    void moveSpikes(int, float, float);
    void hardUpdate();
};
#endif // SPIKE_H
