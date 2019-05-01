#include "MainControl.h"

using namespace std;

int MainControl::WIDTH;
int MainControl::HEIGHT;

MainControl::MainControl()
{
//    main_menu = new MainMenu;
//    hard_mode = new HardMode;
//    classic_mode = new ClassicMode;

    window = NULL;
    renderer = NULL;
    end_loop = false;
//    isHittingWall = false;
//    status = 0;
//    score = -1;
    mode = MENU;
}

MainControl::~MainControl()
{
//    delete main_menu;
//    delete classic_mode;
//    delete hard_mode;
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

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        logSDLError(cout, "Mix_OpenAudio", true);
    }

    main_menu.loadMedia(renderer);
    classic_mode.loadMedia(renderer);
    hard_mode.loadMedia(renderer);
//    duel_mode.loadMedia(renderer);
}

void MainControl::setMode()
{
    switch(mode)
    {
    case MENU:
    {
//        MainMenu main_menu;
//        main_menu.loadMedia(renderer);
        main_menu.reset();
        while(!end_loop)
        {
            main_menu.handleEvent(event, end_loop, mode);
            main_menu.update(end_loop, mode);
            if(mode != 0)
                break;
            main_menu.render(renderer, end_loop);
        }
        break;
    }
    case CLASSIC:
    {
//        ClassicMode classic_mode;
//        classic_mode.loadMedia(renderer);
        classic_mode.reset();
        while(!end_loop)
        {
            classic_mode.handleEvent(event, end_loop, mode);
            classic_mode.update(end_loop, mode);
            classic_mode.playSound();
            if(mode != 1)
            {
                reset();
                break;
            }
            classic_mode.render(renderer, end_loop);
        }
        break;
    }
    case HARD:
    {
//        HardMode hard_mode;
//        hard_mode.loadMedia(renderer);
        hard_mode.reset();
        while(!end_loop)
        {
            hard_mode.handleEvent(event, end_loop, mode);
            hard_mode.update(end_loop, mode);
            hard_mode.playSound();
            if(mode != 2)
            {
                reset();
                break;
            }
            hard_mode.render(renderer, end_loop);
        }
        break;
    }
    case DUEL:
    {
//        duel_mode.reset();
//        while(!end_loop)
//        {
//            duel_mode.handleEvent(event, end_loop, mode);
//            duel_mode.update(end_loop, mode);
//            duel_mode.playSound();
//            if(mode != 3)
//            {
//                reset();
//                break;
//            }
//            duel_mode.render(renderer, end_loop);
//        }
        break;
    }
    }
}

void MainControl::reset()
{
//    isHittingWall = false;
//    status = 0;
//    score = -1;
    mode  = 0;

//    delete main_menu;
//    delete classic_mode;
//    delete hard_mode;

//    main_menu = NULL;
//    classic_mode = NULL;
//    hard_mode = NULL;

//    main_menu = new MainMenu;
//    main_menu.loadMedia(renderer);
//
//    classic_mode = new ClassicMode;
//    classic_mode.loadMedia(renderer);
//
//    hard_mode = new HardMode;
//    hard_mode.loadMedia(renderer);
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
    return window;
}

SDL_Renderer* MainControl::getRenderer()const
{
    return renderer;
}

bool MainControl::isEndLoop() const
{
    return end_loop;
}

//void MainControl::setEndLoop(const bool& end_loop)
//{
//    end_loop=end_loop;
//}

int MainControl::getWidth()
{
    return WIDTH;
}

int MainControl::getHeight()
{
    return HEIGHT;
}

//int MainControl::getScore()
//{
//    return score;
//}
