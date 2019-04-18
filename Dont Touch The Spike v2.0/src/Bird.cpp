#include "Bird.h"

using namespace std;

Bird::Bird()
{
    x.push_back(0);
    y.push_back(SCREEN_HEIGHT/2.0);
    dx = 0;
    dy = 0;
    change_in_dx = 0.05;
    change_in_dy = 0.3;
    change_press_dx = 2;
    change_press_dy = -7.5;
    //fix loi dap tuong
}

Bird::~Bird()
{
    x.clear();
    y.clear();
    dx = 0;
    dy = 0;
    width.clear();
    height.clear();
    texture.clear();
    change_in_dx = 0;
    change_in_dy = 0;
    change_press_dx = 0;
    change_press_dy = 0;
}

void Bird::loadTexture(SDL_Renderer* renderer)
{
    texture.push_back(loadFromFile("assets/sprites/yellowbird-downflap.png", renderer));
    texture.push_back(loadFromFile("assets/sprites/yellowbird-midflap.png", renderer));
    texture.push_back(loadFromFile("assets/sprites/yellowbird-upflap.png", renderer));
}

void Bird::handleEvent(SDL_Event event, int &status)
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_KEYDOWN:
    {
        if(event.key.keysym.sym == SDLK_SPACE)
        {
            if(status == GO_LEFT)
            {
                dx = change_press_dx; //change in velocity when press SPACE
                dy = change_press_dy;
            }
            else if(status == GO_RIGHT)
            {
                dx = (-1)*change_press_dx;
                dy = change_press_dy;
            }
        }
        break;
    }
    }
}

void Bird::update(int &status, int &score, bool &isHittingWall)
{
    isHittingWall = false;
    if(status == GO_LEFT)
    {
        dx += change_in_dx; //cho de dieu chinh van toc cua cac con chim khac nhau
        dy += change_in_dy;
    }
    else if(status == GO_RIGHT)
    {
        dx -= change_in_dx;
        dy += change_in_dy;
    }
    x.at(0) += dx;
    y.at(0) += dy;
    if(x.at(0) > SCREEN_WIDTH-34)
    {
        x.at(0) = SCREEN_WIDTH-34;
        dx *= -1; //fix de chim dap tuong tu nhien hon
        dy *= 0.9;
        status = GO_RIGHT;
        isHittingWall = true;
        score++;
    }
    if(x.at(0) < 0)
    {
        x.at(0) = 0;
        dx *= -1;
        dy *= 0.9;
        status = GO_LEFT;
        isHittingWall = true;
        score++;
    }
    if(y.at(0) > SCREEN_HEIGHT-24)
    {
        y.at(0) = SCREEN_HEIGHT-24;
        status = DEATH;
    }
    if(y.at(0) < 0)
    {
        y.at(0) = 0;
        status = DEATH;
    }

}

float Bird::getDx()
{
    return dx;
}

float Bird::getDy()
{
    return dy;
}

HardBird::HardBird()
{
    x.push_back(0);
    y.push_back(SCREEN_HEIGHT/2.0);
    dx = 0;
    dy = 0;
    change_in_dx = 0.1;
    change_in_dy = 0.3;
    change_press_dx = 4;
    change_press_dy = -7.5;
}
