#ifndef BIRD_H
#define BIRD_H

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

class Bird
{
public:
    Bird();
    ~Bird();

    void loadFromFile(string path, SDL_Renderer* renderer);
    void free();
    void render(int x, int y, int w, int h, SDL_Renderer* renderer, int status);
    void update(int &status, bool &hit, int &score);
    void handleEvent(SDL_Event &event, int status);
    int getWidth();
    int getHeight();
    float getX();
    float getY();

protected:
private:
    float x, y;
    float dx, dy;
    float ddx, ddy;
    int width;
    int height;
    SDL_Texture* bird_texture;

};

#endif // BIRD_H
