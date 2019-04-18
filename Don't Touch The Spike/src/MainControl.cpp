#include "MainControl.h"

using namespace std;

int MainControl::WIDTH;
int MainControl::HEIGHT;
Bird* bird = NULL;
Background* background = NULL;
Spike* spike = NULL;

MainControl::MainControl()
{
    window = NULL;
    renderer = NULL;
    end_loop = false;
    status = 0;
    hit = false;
    score = 0;
}

MainControl::~MainControl()
{
    background->free();
    bird->free();
    spike->free();
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
        logSDLError(cout, "CreateWindow", true);
    }

    renderer = SDL_CreateRenderer(this -> window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
    {
        logSDLError(cout, "CreateRenderer", true);
    }

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        logSDLError(cout, "SDL_Init_image", true);
    }

    bird = new Bird();
    background = new Background();
    spike = new Spike();

    loadFromFile();
}

void MainControl::loadFromFile()
{
    background->loadFromFile("assets/sprites/background-day.png", renderer);
    bird->loadFromFile("assets/sprites/yellowbird-midflap.png", renderer);
    spike->loadFromFile("assets/sprites/spike.png", renderer);
}

void MainControl::handleEvent()
{
    for( int i = 0; i < spike->getQuality(); i++) //detect collision
    {
        if( status == 0)
        {
            if((bird->getY()+24 >= spike->getY(i))
                    &&(bird->getY() <= spike->getY(i)+10)
                    &&(bird->getX()+34 >= spike->getX(i))
                    &&(bird->getX() <= spike->getX(i)+30)) //bird hit left/right spikes
                end_loop = true;
        }
        else
        {
            if((bird->getY() <= spike->getY(i)+10)
                    &&(bird->getY()+24 >= spike->getY(i))
                    &&(bird->getX() <= spike->getX(i)+30)
                    &&(bird->getX()+30 >= spike->getX(i)))
                end_loop = true;
        }
    }

    if(bird->getY() == 0 || bird->getY() == SCREEN_HEIGHT-24) //bird hit top/bottom spikes
    {
        end_loop = true;
    }

    bird->handleEvent(event, status);
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
    {
        end_loop = true;
        break;
    }
    case SDL_KEYUP:
    {
        if(event.key.keysym.sym==SDLK_ESCAPE)
        {
            end_loop=true;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void MainControl::update()
{
    bird->update(status, hit, score);
    spike->update(status, hit, score);
}

void MainControl::render()
{
    if(!end_loop)
    {
        //set background color
        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,0,0,255);

        background->render(0,0,SCREEN_WIDTH,SCREEN_HEIGHT, renderer);
        bird->render(bird->getX(),bird->getY(), bird->getWidth(), bird->getHeight(), renderer, status);
        for (int i = 0; i< spike->getQuality(); i++)
        {
            spike->render(spike->getX(i), spike->getY(i), spike->getWidth(), spike->getHeight(), renderer, status);
        }

        SDL_RenderPresent(renderer);
    }
}

void MainControl::close()
{
    delete bird;
    delete background;
    delete spike;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
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
