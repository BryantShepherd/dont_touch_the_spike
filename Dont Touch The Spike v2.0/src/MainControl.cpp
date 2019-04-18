#include "MainControl.h"

using namespace std;

int MainControl::WIDTH;
int MainControl::HEIGHT;

ClassicMode* classic_mode = NULL;
HardMode* hard_mode = NULL;

MainControl::MainControl()
{
    window = NULL;
    renderer = NULL;
    end_loop = false;
    isHittingWall = false;
    status = 0;
    score = -1;
    mode  = 0;
}

MainControl::~MainControl()
{

}

void MainControl::logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void MainControl::initializeSDL(string window_title, const int&x, const int& y, const int& width, const int& height, const int& screen_option)
{

    WIDTH = width;
    HEIGHT = height;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        logSDLError(cout, "SDL_Init", true);
    }

    window = SDL_CreateWindow(window_title.c_str(), x, y, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        logSDLError(cout, "SDL_CreateWindow", true);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
    {
        logSDLError(cout, "SDL_CreateRenderer", true);
    }

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        logSDLError(cout, "IMG_Init", true);
    }

    classic_mode = new ClassicMode;
    classic_mode->loadTexture(renderer);

    hard_mode = new HardMode;
    hard_mode->loadTexture(renderer);
}

void MainControl::setMode()
{
//    switch(mode)
//    {
//    case MENU:
//        {
//            break;
//        }
//    case CLASSIC:
//        {
//            classic_mode->handleEvent(event, status, end_loop);
//            classic_mode->update(status, score, isHittingWall, end_loop);
//            classic_mode->render(renderer, status, end_loop);
            hard_mode->handleEvent(event, status, end_loop);
            hard_mode->update(status, score, isHittingWall, end_loop);
            hard_mode->render(renderer, status, end_loop);
//            break;
//        }
//    case HARD:
//        {
//            break;
//        }
//    case DUEL:
//        {
//            break;
//        }
//    }
}

void MainControl::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

SDL_Window* MainControl::getWindow() const
{
    return this->window;
}

SDL_Renderer* MainControl::getRenderer()const
{
    return this->renderer;
}

bool MainControl::isEndLoop() const
{
    return this->end_loop;
}

void MainControl::setEndLoop(const bool& end_loop)
{
    this->end_loop=end_loop;
}

int MainControl::getWidth()
{
    return WIDTH;
}

int MainControl::getHeight()
{
    return HEIGHT;
}

int MainControl::getScore()
{
    return score;
}
