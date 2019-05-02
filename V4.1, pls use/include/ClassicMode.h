#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Item.h"
#include "Rock.h"
#include "Score.h"
#include "Bird.h"
#include "Background.h"
#include "Button.h"
#include "Spike.h"
#include "constant.h"
#include "MainMenu.h"

using namespace std;

class ClassicMode
{
public:
    ClassicMode();
    ~ClassicMode();
    void loadMedia(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event, bool &end_loop, int &mode);
    void update(bool &end_loop, int& mode);
    void playSound();
    void render(SDL_Renderer* renderer, bool end_loop);

    void reset();

protected:
    Background background;
    Bird bird;
    Spike spike;
    Rock rock;
    Item item;
    Score s_score;

    vector<Mix_Chunk*> sound;
    int score;
    int frame;
    bool isHittingWall;
    int status;
    bool playMusic;

private:

};

#endif // CLASSICMODE_H
