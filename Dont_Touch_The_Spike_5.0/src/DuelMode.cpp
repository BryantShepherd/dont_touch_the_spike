#include "DuelMode.h"

DuelMode::DuelMode()
{
    frame = 0;
    isHittingWall = false;
    status = GOING_RIGHT;
    score = 0;
    playMusic = false;
    winner = 0;
}

DuelMode::~DuelMode()
{
    sound.clear();
    sound.shrink_to_fit();
}
void DuelMode::loadMedia(SDL_Renderer* renderer)
{
    background.loadMedia(renderer);
    player1.loadMedia(renderer);
    player2.loadMedia(renderer);
    spike.loadMedia(renderer);
    s_score.loadMedia(renderer);
    item.loadMedia(renderer);

    sound.push_back(Mix_LoadWAV("assets/audio/jump.wav"));
    sound.push_back(Mix_LoadWAV("assets/audio/point.wav"));
    sound.push_back(Mix_LoadWAV("assets/audio/dead.wav"));
    sound.push_back(Mix_LoadWAV("assets/audio/candy.wav"));
}

void DuelMode::handleEvent(SDL_Event event, bool& end_loop, int &mode)
{
    if(status != DEATH)
    {
        while(SDL_PollEvent(&event))
        {
            player1.handleEvent(event, status, sound);
            player2.handleEvent(event, status, sound);
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
                    mode = MENU;
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
                mode = MENU;
            default:
            {
                break;
            }
            }
        }
    }
}

void DuelMode::update(bool &end_loop, int &mode)
{
    player1.update(status, score, isHittingWall);
    player2.update(status, score, isHittingWall);
    spike.update(status, score, isHittingWall);
    for(int i = 0; i < spike.getSpikeNumber(); i++)
    {
        if(status == GOING_RIGHT)
        {
            if((player1.getY(0)+24 >= spike.getY(i))
                    &&(player1.getY(0) <= spike.getY(i)+10)
                    &&(player1.getX(0)+34 >= SCREEN_WIDTH - spike.getWidth(0))
                    &&(player1.getX(0) <= SCREEN_WIDTH - spike.getWidth(0) + 30))
            {
                status = DEATH;
            }

            if((player2.getY(0) <= spike.getY(i)+10)
                    &&(player2.getY(0)+24 >= spike.getY(i))
                    &&(player2.getX(0) <= 30)
                    &&(player2.getX(0)+30 >= 0))
            {
                status = DEATH;
            }

        }
        else if(status == GOING_LEFT)
        {
            if((player1.getY(0) <= spike.getY(i)+10)
                    &&(player1.getY(0)+24 >= spike.getY(i))
                    &&(player1.getX(0) <= 30)
                    &&(player1.getX(0)+30 >= 0))
            {
                status = DEATH;
            }
            if((player2.getY(0)+24 >= spike.getY(i))
                    &&(player2.getY(0) <= spike.getY(i)+10)
                    &&(player2.getX(0)+34 >= SCREEN_WIDTH - spike.getWidth(0))
                    &&(player2.getX(0) <= SCREEN_WIDTH - spike.getWidth(0) + 30))
            {
                status = DEATH;
            }
        }
    }

    if(player1.getY(0) == 0 || player1.getY(0) == SCREEN_HEIGHT-24 || player2.getY(0) == 0 || player2.getY(0) == SCREEN_HEIGHT-24)
    {
        status = DEATH;
    }
    if(status == DEATH)
    {
        player1.pause();
        player2.pause();
        if (playMusic == false)
        {
            Mix_PlayChannel( -1, sound.at(2), 0 ); //only play once
            playMusic = true;
        }
    }
    else
    {
        playMusic = false;
    }

}

void DuelMode::playSound()
{
    player1.playSound(sound, isHittingWall);
    player2.playSound(sound, isHittingWall);
}

void DuelMode::render(SDL_Renderer* renderer, bool end_loop)
{

    if(!end_loop)
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
        if(status == GOING_RIGHT)
        {

            player1.render(frame/3, player1.getX(0), player1.getY(0), player1.getWidth(0), player1.getHeight(0), renderer, 0, NULL,SDL_FLIP_NONE);
            player2.render(frame/3, player2.getX(0), player2.getY(0), player2.getWidth(0), player2.getHeight(0), renderer, 0, NULL,SDL_FLIP_HORIZONTAL);

            for (int i = 0; i< (spike.getSpikeNumber()); i++)
            {
                spike.render(0, spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_HORIZONTAL);
                spike.render(0, SCREEN_WIDTH - spike.getWidth(0) + 1 - spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
            }
        }
        else if(status == GOING_LEFT)
        {
            player1.render(frame/3, player1.getX(0), player1.getY(0), player1.getWidth(0), player1.getHeight(0), renderer, 0, NULL,SDL_FLIP_HORIZONTAL);
            player2.render(frame/3, player2.getX(0), player2.getY(0), player2.getWidth(0), player2.getHeight(0), renderer, 0, NULL,SDL_FLIP_NONE);

            for (int i = 0; i< spike.getSpikeNumber(); i++)
            {
                spike.render(0, SCREEN_WIDTH - spike.getWidth(0) + 1 - spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_HORIZONTAL);
                spike.render(0, spike.getX(i), spike.getY(i), spike.getWidth(0), spike.getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
            }
        }
        else if(status >= DEATH)
        {
            //render match result
            background.render(1, (SCREEN_WIDTH-background.getWidth(1))/2, (SCREEN_HEIGHT-background.getHeight(1))/2, background.getWidth(1), background.getHeight(1), renderer, 0, NULL, SDL_FLIP_NONE);
        }

        s_score.renderScore(renderer, score);
        frame++;
        if(frame/3 >= 3)
            frame = 0;

        SDL_RenderPresent(renderer);
    }
}


void DuelMode::reset()
{
    player1.reset();
    player2.reset();
    spike.reset();
    frame = 0;
    isHittingWall = false;
    status = GOING_RIGHT;
    score = 0;
    playMusic = false;
}
