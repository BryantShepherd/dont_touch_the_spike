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
}

void MainMenu::loadTexture(SDL_Renderer* renderer)
{
    background.loadTexture(renderer);

    button.push_back(Button());
    button.at(0).loadFromFile("assets/sprites/message.png", renderer);
    button.at(0).loadFromFile("assets/sprites/message1.png", renderer);
    button.at(0).setPosition(100, 150);

    button.push_back(Button());
    button.at(1).loadFromFile("assets/RPG_UI/PNG/buttonRound_beige.png", renderer);
    button.at(1).setPosition(0, SCREEN_HEIGHT/4);
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
    }
    if(button.at(1).isHittingButton() == true)
    {
        mode = 2;
    }
}

void MainMenu::render(SDL_Renderer* renderer, bool end_loop)
{
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255,0,0,255);

    background.render(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, renderer, 0, NULL, SDL_FLIP_NONE);
    if(frame%30 < 16)
        button.at(0).render(0, button.at(0).getX(0), button.at(0).getY(0), button.at(0).getWidth(0), button.at(0).getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
    else if(frame%30 < 30)
        button.at(0).render(1, button.at(0).getX(0), button.at(0).getY(0), button.at(0).getWidth(0), button.at(0).getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
    button.at(1).render(0, button.at(1).getX(0), button.at(1).getY(0), button.at(1).getWidth(0), button.at(1).getHeight(0), renderer, 0, NULL, SDL_FLIP_NONE);
    frame ++;

    SDL_RenderPresent(renderer);
}
