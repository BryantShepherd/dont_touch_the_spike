#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Item.h"
#include "Bird.h"
#include "Background.h"
#include "Button.h"
#include "Spike.h"
#include "constant.h"
#include "MainMenu.h"
#include "ClassicMode.h"
#include "HardMode.h"


using namespace std;

class MainControl
{
public:
    MainControl();
    ~MainControl();
    void logSDLError(ostream& os, const string &msg, bool fatal = false);
    void initializeSDL(string window_title, const int&x, const int& y, const int& width, const int& height, const int& screen_option);

    void setMode();

    void reset();

    void close();

    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;

    bool isEndLoop() const;
//    void setEndLoop(const bool&);

    int getScore();
    static int getWidth();
    static int getHeight();

protected:
    static int WIDTH;
    static int HEIGHT;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool end_loop;
    bool isHittingWall;
    int status;
    int score;
    int mode;
//    MainMenu main_menu;
//    ClassicMode classic_mode;
//    HardMode hard_mode;
};

#endif // MAINCONTROL_H
