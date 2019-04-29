#include "ClassicMode.h"

using namespace std;

ClassicMode::ClassicMode()
{
    frame = 0;
    isHittingWall = false;
    status = 0;
    score = -1;
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

void ClassicMode::loadMedia(SDL_Renderer* renderer)
{
    background.loadMedia(renderer);
    bird.loadMedia(renderer);
    spike.loadMedia(renderer);
    s_score.loadMedia(renderer);
    item.loadTexture(renderer);

    sound.push_back(Mix_LoadWAV("assets/audio/jump.wav"));
    sound.push_back(Mix_LoadWAV("assets/audio/point.wav"));
    sound.push_back(Mix_LoadWAV("assets/audio/dead.wav"));

}

void ClassicMode::handleEvent(SDL_Event event, bool& end_loop, int &mode)
{
    if(status != DEATH)
    {
        while(SDL_PollEvent(&event))
        {
            bird.handleEvent(event, status, sound);
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
            case SDL_MOUSEBUTTONUP:
                mode = 0;
            default:
            {
                break;
            }
            }
        }
    }
}

void ClassicMode::update(bool &end_loop, int &mode)
{
    bird.update(status, score, isHittingWall);
    spike.update(status, score, isHittingWall);
    item.update(status, isHittingWall);
    item.itemAnimation();
    item.checkIfEaten(bird, score);
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
            }
        }
    }

    if(bird.getY(0) == 0 || bird.getY(0) == SCREEN_HEIGHT-24)
    {
        status = DEATH;
    }
    if(status == DEATH)
    {
        bird.pause();
        Mix_PlayChannel( -1, sound.at(2), 0 );
    }

}

void ClassicMode::playSound()
{
    bird.playSound(sound, isHittingWall);
}

void ClassicMode::render(SDL_Renderer* renderer, bool end_loop)
{

    if(!end_loop)
    {
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        if(status == GO_LEFT)
        {
            background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);

            bird.render(frame/3, bird.getX(0), bird.getY(0), bird.getWidth(0), bird.getHeight(0), renderer, 0, NULL,SDL_FLIP_NONE);
            if(!item.getItemState()) item.render(0, item.getX(0), item.getY(0), item.getWidth(0), item.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE); //if item hasn't been eaten

            for (int i = 0; i< (spike.getSpikeNumber()); i++)
            {
                spike.render(0, spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_HORIZONTAL);
            }
        }
        else if(status == GO_RIGHT)
        {
            background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
            bird.render(frame/3, bird.getX(0), bird.getY(0), bird.getWidth(0), bird.getHeight(0), renderer, 0, NULL,SDL_FLIP_HORIZONTAL);
            if(!item.getItemState()) item.render(0, item.getX(0), item.getY(0), item.getWidth(0), item.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE); //if item hasn't been eaten
            for (int i = 0; i< spike.getSpikeNumber(); i++)
            {
                spike.render(0, spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
            }
        }
        else if(status >= DEATH)
        {
            background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
            background.render(1, (SCREEN_WIDTH-background.getWidth(1))/2, (SCREEN_HEIGHT-background.getHeight(1))/2, background.getWidth(1), background.getHeight(1), renderer, 0, NULL, SDL_FLIP_NONE);
        }

        s_score.renderScore(renderer, score);
        frame++;
        if(frame/3 >= 3)
            frame = 0;

        SDL_RenderPresent(renderer);
    }
}
