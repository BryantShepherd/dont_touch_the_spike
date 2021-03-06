#include "Bird.h"

using namespace std;

Bird::Bird()
{
    x.push_back(0);
    y.push_back(SCREEN_HEIGHT/2.0);
    dx = 0;
    dy = 0;
    ddx = 0.05;
    ddy = 0.3;
    change_press_dx = 2;
    change_press_dy = -7.5;
    //fix loi dap tuong
}

Bird::~Bird()
{
    x.clear();
    y.clear();
    width.clear();
    height.clear();
    texture.clear();

    x.shrink_to_fit();
    y.shrink_to_fit();
    width.shrink_to_fit();
    height.shrink_to_fit();
    texture.shrink_to_fit();
}

void Bird::loadTexture(SDL_Renderer* renderer)
{
    loadFromFile("assets/sprites/yellowbird-downflap.png", renderer);
    loadFromFile("assets/sprites/yellowbird-midflap.png", renderer);
    loadFromFile("assets/sprites/yellowbird-upflap.png", renderer);
}

void Bird::handleEvent(SDL_Event event, int &status)
{
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
    case SDL_MOUSEBUTTONDOWN:
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
        break;
    }
}

void Bird::update(int &status, int &score, bool &isHittingWall)
{
    isHittingWall = true; //need to be TRUE to use generate item the first time, see more in item.cpp/update
    if(status == GO_LEFT)
    {
        dx += ddx; //cho de dieu chinh van toc cua cac con chim khac nhau
        dy += ddy;
    }
    else if(status == GO_RIGHT)
    {
        dx -= ddx;
        dy += ddy;
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
    else if(x.at(0) < 0)
    {
        x.at(0) = 0;
        dx *= -1;
        dy *= 0.9;
        status = GO_LEFT;
        isHittingWall = true;
        score++;
    }
    else
    {
        isHittingWall = false;
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
void Bird::pause()
{
    x.at(0) = 0;
    y.at(0) = 0;
    dx = 0;
    dy = 0;
    ddx = 0;
    ddy = 0;
    change_press_dx = 0;
    change_press_dy = 0;

}

float Bird::getDx()
{
    return dx;
}

float Bird::getDy()
{
    return dy;
}
