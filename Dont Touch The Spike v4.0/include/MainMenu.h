#ifndef MAINMENU_H
#define MAINMENU_H

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

class MainMenu
{
public:
    MainMenu();
    ~MainMenu();
    void loadTexture(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event, bool &end_loop, int &mode);
    void update(bool &end_loop, int &mode);
    void render(SDL_Renderer* renderer, bool end_loop);

protected:
    Background background;
    vector <Button> button;
    int frame;

private:

};

#endif // MAINMENU_H
