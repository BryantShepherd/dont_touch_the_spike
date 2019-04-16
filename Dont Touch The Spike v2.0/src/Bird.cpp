#include "Bird.h"

using namespace std;

Bird::Bird()
{
    x.push_back(0);
    y.push_back(SCREEN_HEIGHT/2.0);
    dx.push_back(0);
    dy.push_back(0);
}

Bird::~Bird()
{
    x.clear();
    y.clear();
    dx.clear();
    dy.clear();
    width.clear();
    height.clear();
    texture.clear();
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
                dx.at(0) = 2;
                dy.at(0) = -7.5;
            }
            else if(status == GO_RIGHT)
            {
                dx.at(0) = -2;
                dy.at(0) = -7.5;
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
        dx.at(0) += 0.05;
        dy.at(0) += 0.3;
    }
    else if(status == GO_RIGHT)
    {
        dx.at(0) -= 0.05;
        dy.at(0) += 0.3;
    }
    x.at(0) += dx.at(0);
    y.at(0) += dy.at(0);
    if(x.at(0) > SCREEN_WIDTH-34)
    {
        x.at(0) = SCREEN_WIDTH-34;
        dx.at(0) = -1.75;
        dy.at(0) = -4.5;
        status = GO_RIGHT;
        isHittingWall = true;
        score++;
    }
    if(x.at(0) < 0)
    {
        x.at(0) = 0;
        dx.at(0) = 1.75;
        dy.at(0) = -4.5;
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

float Bird::getDx(int i)
{
    return dx.at(i);
}

float Bird::getDy(int i)
{
    return dy.at(i);
}
