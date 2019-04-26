#ifndef CLASSICMODE_H
#define CLASSICMODE_H

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

class ClassicMode
{
public:
    ClassicMode();
    ~ClassicMode();
    void loadTexture(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event, int &status, bool &end_loop);
    void update(int &status, int &score, bool &isHittingWall, bool &end_loop);
    void render(SDL_Renderer* renderer, int status, bool end_loop);

protected:

private:

};

#endif // CLASSICMODE_H
