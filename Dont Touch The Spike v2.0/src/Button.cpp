#include "Button.h"

using namespace std;

Button::Button()
{

}

Button::~Button()
{
    x.clear();
    y.clear();
    width.clear();
    height.clear();
    texture.clear();
}

void Button::loadTexture(SDL_Renderer* renderer)
{
    x.push_back(100);
    y.push_back(150);
    texture.push_back(loadFromFile("assets/sprites/message.png", renderer));
}
