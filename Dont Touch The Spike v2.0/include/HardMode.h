#ifndef HARDMODE_H_INCLUDED
#define HARDMODE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Bird.h"
#include "Background.h"
#include "Button.h"
#include "Spike.h"
#include "constant.h"

using namespace std;

class HardMode
{
public:
    HardMode();
    ~HardMode();
    void loadTexture(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event, int &status, bool &end_loop);
    void update(int &status, int &score, bool &isHittingWall, bool &end_loop);
    void render(SDL_Renderer* renderer, int status, bool end_loop);

protected:
    HardBird* bird = NULL;
    HardSpike* spike = NULL;
    Background* background = NULL;
private:

};



#endif // HARDMODE_H_INCLUDED
