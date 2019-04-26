#include "Background.h"

using namespace std;

Background::Background()
{
    x.push_back(0);
    y.push_back(0);
}

Background::~Background()
{
    x.clear();
    y.clear();
    width.clear();
    height.clear();
    texture.clear();
}

void Background::loadTexture(SDL_Renderer* renderer)
{
    texture.push_back(loadFromFile("assets/sprites/background-day.png", renderer));
}
