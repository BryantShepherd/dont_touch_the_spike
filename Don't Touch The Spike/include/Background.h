#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <SDL_ttf.h>

//#include "Bird.h"
//#include "Spike.h"
//#include "Background.h"
//#include "MainControl.h"

using namespace std;

class Background
{
public:
    Background();
    ~Background();
    void loadFromFile(string path, SDL_Renderer* renderer);
    void free();
    void render(int x, int y, int w, int h, SDL_Renderer* renderer);
private:
    SDL_Texture* background_texture;
};

#endif // BACKGROUND_H
