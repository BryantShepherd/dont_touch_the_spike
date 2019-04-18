#include "HardMode.h"

using namespace std;

HardMode::HardMode()
{
    background = new Background;
    bird = new HardBird;
    spike = new HardSpike;
}

HardMode::~HardMode()
{
    delete background;
    delete bird;
    delete spike;
}

void HardMode::loadTexture(SDL_Renderer* renderer)
{
    background->loadTexture(renderer);
    bird->loadTexture(renderer);
    spike->loadTexture(renderer);
}

void HardMode::handleEvent(SDL_Event event, int &status, bool& end_loop)
{
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
            end_loop = true;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void HardMode::update(int &status, int &score, bool &isHittingWall, bool &end_loop)
{
    bird->update(status, score, isHittingWall);
    spike->update(status, score, isHittingWall);
    spike->hardUpdate();
    for(int i = 0; i < spike->getSpikeNumber(); i++)
    {
        if(status == GO_LEFT)
        {
            if((bird->getY(0)+24 >= spike->getY(i))
                    &&(bird->getY(0) <= spike->getY(i)+10)
                    &&(bird->getX(0)+34 >= spike->getX(i))
                    &&(bird->getX(0) <= spike->getX(i)+30))
            {
//                mode = 0;
                end_loop = true;
                cout << score << endl;
            }
        }
        else if(status == GO_RIGHT)
        {
            if((bird->getY(0) <= spike->getY(i)+10)
                    &&(bird->getY(0)+24 >= spike->getY(i))
                    &&(bird->getX(0) <= spike->getX(i)+30)
                    &&(bird->getX(0)+30 >= spike->getX(i)))
            {
//                mode = 0;
                end_loop = true;
                cout << score<< endl;
            }
        }
    }

    if(bird->getY(0) == 0 || bird->getY(0) == SCREEN_HEIGHT-24)
    {
//        mode  = 0;
        end_loop = true;
        cout << score << endl;
    }
}

void HardMode::render(SDL_Renderer* renderer, int status, bool end_loop)
{
    if(!end_loop)
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        if(status == GO_LEFT)
        {
            background->render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);

            bird->render(0, bird->getX(0), bird->getY(0), bird->getWidth(0), bird->getHeight(0), renderer, 0, NULL,SDL_FLIP_NONE);

            for (int i = 0; i< (spike->getSpikeNumber()); i++)
            {
                spike->render(0, spike->getX(i), spike->getY(i), spike->getWidth(0), spike->getHeight(0), renderer, 0, NULL, SDL_FLIP_HORIZONTAL);
            }
        }
        else if(status == GO_RIGHT)
        {
            background->render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
            bird->render(0, bird->getX(0), bird->getY(0), bird->getWidth(0), bird->getHeight(0), renderer, 0, NULL,SDL_FLIP_HORIZONTAL);
            for (int i = 0; i< spike->getSpikeNumber(); i++)
            {
                spike->render(0, spike->getX(i), spike->getY(i), spike->getWidth(0), spike->getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
            }
        }

        SDL_RenderPresent(renderer);
    }
}
