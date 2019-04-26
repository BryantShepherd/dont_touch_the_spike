#include "Item.h"
using namespace std;

Item::Item()
{

}

Item::~Item()
{
    x.clear();
    y.clear();
}

void Item::loadTexture(SDL_Renderer* renderer) //sua de load duoc icon khac nhau
{
    loadFromFile("assets/sprites/candy(24px).png", renderer);
}

void Item::update(int& status, int&score, bool& hasBeenEaten)
{
    srand((int) time(0));
    x.clear();
    y.clear();
    if (status == GO_RIGHT)
    {
        x.push_back(40); //vi tri x cua keo
        y.push_back(200);
    }
    else
    {
        x.push_back(SCREEN_WIDTH - 40 - width.at(0));
        y.push_back(400);
    }

}

void Item::checkIfEaten(Bird& bird)
{
    if((bird.getY(0)+bird.getWidth(0) >= getY(0))
        &&(bird.getY(0) <= getY(0)+getWidth(0))
        &&(bird.getX(0)+bird.getHeight(0) >= getX(0))
        &&(bird.getX(0) <= getX(0)+getHeight(0)))
        {

        }
}


