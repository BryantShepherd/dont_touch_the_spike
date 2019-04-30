#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
//    background = new Background;
//    button = new Button;
    frame = 0;
}

MainMenu::~MainMenu()
{
//    delete background;
//    delete button;

//    background = NULL;
//    button = NULL;
    button.clear();
    button.shrink_to_fit();
    sound.clear();
    sound.shrink_to_fit();
}

void MainMenu::loadMedia(SDL_Renderer* renderer)
{
    background.loadMedia(renderer);

    button.push_back(Button());
    button.at(0).loadFromFile("assets/assets/sprites/message0.png", renderer);
    button.at(0).loadFromFile("assets/assets/sprites/message1.png", renderer);
    button.at(0).loadFromFile("assets/assets/sprites/message2.png", renderer);
    button.at(0).setPosition(75, 50);

    button.push_back(Button());
    button.at(1).loadFromFile("assets/RPG_UI/PNG/buttonRound_beige.png", renderer);
    button.at(1).setPosition(10, SCREEN_HEIGHT/4);

    sound.push_back(Mix_LoadWAV("assets/audio/jump.wav"));
}

void MainMenu::handleEvent(SDL_Event event, bool &end_loop, int &mode)
{
    while(SDL_PollEvent(&event))
    {
        button.at(0).handleEvent(event);
        button.at(1).handleEvent(event);
        switch(event.type)
        {
        case SDL_QUIT:
        {
            end_loop = true;
            break;
        }
        case SDL_KEYUP:
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                end_loop = true;
            }
            if(event.key.keysym.sym == SDLK_SPACE)
            {
                mode = 1;
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

void MainMenu::update(bool &end_loop, int &mode)
{
    if(button.at(0).isHittingButton() == true)
    {
        mode = 1;
        Mix_PlayChannel( -1, sound.at(0), 0 );
    }
    if(button.at(1).isHittingButton() == true)
    {
        mode = 2;
        Mix_PlayChannel( -1, sound.at(0), 0 );
    }
}

void MainMenu::render(SDL_Renderer* renderer, bool end_loop)
{
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255,0,0,255);

    background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);

    button.at(0).render(frame/3, button.at(0).getX(0), button.at(0).getY(0), button.at(0).getWidth(0), button.at(0).getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);

    button.at(1).render(0, button.at(1).getX(0), button.at(1).getY(0), button.at(1).getWidth(0), button.at(1).getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);

    frame++;
    if(frame/3 >= 3)
        frame = 0;

    SDL_RenderPresent(renderer);
}

void MainMenu::reset()
{
    button.at(0).reset();
    button.at(1).reset();
}
