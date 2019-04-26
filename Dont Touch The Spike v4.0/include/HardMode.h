#ifndef HARDMODE_H_INCLUDED
#define HARDMODE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "HardBird.h"
#include "Background.h"
#include "Button.h"
#include "HardSpike.h"
#include "constant.h"
#include "Score.h"

using namespace std;

class HardMode
{
public:
    HardMode();
    ~HardMode();
    void loadTexture(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event, bool &end_loop, int &mode);
    void update(bool &end_loop, int& mode);
    void render(SDL_Renderer* renderer, bool end_loop);

protected:
    HardBird bird;
    HardSpike spike;
    Background background;
    Score s_score;

    int score;
    int frame;
    bool isHittingWall;
    int status;

private:

};



#endif // HARDMODE_H_INCLUDED
