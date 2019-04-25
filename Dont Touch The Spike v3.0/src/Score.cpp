#include "Score.h"

using namespace std;

Score::Score()
{

}

Score::~Score()
{

}

void Score::loadTexture(SDL_Renderer* renderer)
{
    loadFromFile("assets/sprites/0.png", renderer);
    loadFromFile("assets/sprites/1.png", renderer);
    loadFromFile("assets/sprites/2.png", renderer);
    loadFromFile("assets/sprites/3.png", renderer);
    loadFromFile("assets/sprites/4.png", renderer);
    loadFromFile("assets/sprites/5.png", renderer);
    loadFromFile("assets/sprites/6.png", renderer);
    loadFromFile("assets/sprites/7.png", renderer);
    loadFromFile("assets/sprites/8.png", renderer);
    loadFromFile("assets/sprites/9.png", renderer);
}

void Score::convertToString(int &score)
{
    score_string = to_string(score);
}
