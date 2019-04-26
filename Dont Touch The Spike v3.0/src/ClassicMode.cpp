#include "ClassicMode.h"

using namespace std;

ClassicMode::ClassicMode()
{
    frame = 0;
//    background = new Background;
//    bird = new Bird;
//    spike = new Spike;
}

ClassicMode::~ClassicMode()
{
//    delete background;
//    delete bird;
//    delete spike;

//    background = NULL;
//    bird = NULL;
//    spike = NULL;
}

void ClassicMode::loadTexture(SDL_Renderer* renderer)
{
    background.loadTexture(renderer);
    bird.loadTexture(renderer);
    spike.loadTexture(renderer);
    item.loadTexture(renderer);
}

void ClassicMode::handleEvent(SDL_Event event, int &status, bool& end_loop, int &mode)
{
    if(status != DEATH)
    {
        while(SDL_PollEvent(&event))
        {
            bird.handleEvent(event, status);
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
                    status = DEATH;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
    else if(status == DEATH)
    {
        while(SDL_PollEvent(&event))
        {
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
                    status = DEATH;
                }
                else if(event.key.keysym.sym==SDLK_SPACE)
                {
                    mode = 0;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void ClassicMode::update(int &status, int &score, bool &isHittingWall, bool &end_loop, int &mode)
{
    bird.update(status, score, isHittingWall);
    spike.update(status, score, isHittingWall);
    item.update(status, score, isHittingWall);
    for(int i = 0; i < spike.getSpikeNumber(); i++)
    {
        if(status == GO_LEFT)
        {
            if((bird.getY(0)+24 >= spike.getY(i))
                    &&(bird.getY(0) <= spike.getY(i)+10)
                    &&(bird.getX(0)+34 >= spike.getX(i))
                    &&(bird.getX(0) <= spike.getX(i)+30))
            {
                status = DEATH;
                cout << score << endl;
            }
        }
        else if(status == GO_RIGHT)
        {
            if((bird.getY(0) <= spike.getY(i)+10)
                    &&(bird.getY(0)+24 >= spike.getY(i))
                    &&(bird.getX(0) <= spike.getX(i)+30)
                    &&(bird.getX(0)+30 >= spike.getX(i)))
            {
                status = DEATH;
                cout << score << endl;
            }
        }
    }

    if(bird.getY(0) == 0 || bird.getY(0) == SCREEN_HEIGHT-24)
    {
        status = DEATH;
        cout << score << endl;
    }
    if(status == DEATH)
    {
        bird.pause();
    }

}

void ClassicMode::render(SDL_Renderer* renderer, int status, bool end_loop)
{
    if(!end_loop)
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        if(status == GO_LEFT)
        {
            background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);

            bird.render(frame/3, bird.getX(0), bird.getY(0), bird.getWidth(0), bird.getHeight(0), renderer, 0, NULL,SDL_FLIP_NONE);
            item.render(0, item.getX(0), item.getY(0), item.getWidth(0), item.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);

            for (int i = 0; i< (spike.getSpikeNumber()); i++)
            {
                spike.render(0, spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_HORIZONTAL);
            }
        }
        else if(status == GO_RIGHT)
        {
            background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
            bird.render(frame/3, bird.getX(0), bird.getY(0), bird.getWidth(0), bird.getHeight(0), renderer, 0, NULL,SDL_FLIP_HORIZONTAL);
            item.render(0, item.getX(0), item.getY(0), item.getWidth(0), item.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
            for (int i = 0; i< spike.getSpikeNumber(); i++)
            {
                spike.render(0, spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
            }
        }
        else if(status == DEATH)
        {
            background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
            background.render(1, (SCREEN_WIDTH-background.getWidth(1))/2, (SCREEN_HEIGHT-background.getHeight(1))/2, background.getWidth(1), background.getHeight(1), renderer, 0, NULL, SDL_FLIP_NONE);
        }
        frame++;
        if(frame/3 >= 3)
            frame = 0;

        SDL_RenderPresent(renderer);
    }
}
