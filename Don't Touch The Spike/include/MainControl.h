#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <SDL_ttf.h>

#include "Bird.h"
#include "Spike.h"
#include "Background.h"
#include "MainControl.h"

using namespace std;

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Dont touch the spike!";

const int RIGHT = 1;
const int LEFT = 0;

class MainControl
{
public:
    MainControl();
    ~MainControl();
    void logSDLError(ostream& os, const string &msg, bool fatal = false);
    void initializeSDL(string window_title, const int&x, const int& y, const int& width, const int& height, const int& screen_option);
    void handleEvent();
    void update();
    void loadFromFile();
    void render();
    void close();
    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;
    bool isEndLoop() const;
    void setEndLoop(const bool&);
    int  getScore();
    static int getWidth();
    static int getHeight();

protected: /*tai sao lai dung protected?*/
    static int WIDTH;
    static int HEIGHT;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool end_loop;
    int status;
    int score;
    bool hit;
};

#endif // MAINCONTROL_H
