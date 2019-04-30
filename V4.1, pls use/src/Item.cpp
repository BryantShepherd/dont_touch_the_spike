#include "Item.h"
using namespace std;

const int CANDY  = 0; //texture index number
const int ENERGY_DRINK = 1;
const int SHIELD = 2;
//need to inherit from MainControl to access score, speed, ...
Item::Item()
{
    item_type = CANDY;
    hasBeenEaten = true;
    activate_effect = false;
    k = 0; //var for item animation
    x.push_back(0);
    y.push_back(0);
}

Item::~Item()
{
    x.clear();
    y.clear();
}

void Item::loadMedia(SDL_Renderer* renderer) //sua de load duoc icon khac nhau
{
    loadFromFile("assets/assets/sprites/candy-32.png", renderer);
    loadFromFile("assets/assets/sprites/energy-drink-32.png", renderer);
}

void Item::update(int& status, bool& isHittingWall)
{
    if (hasBeenEaten == true && isHittingWall == true) //if bird eat item and hit wall, render item on opposite wall
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
        hasBeenEaten = false;
    }
}

void Item::checkIfEaten(Bird& bird, int& score, vector <Mix_Chunk*> &sound)
{
    if((bird.getY(0)+bird.getHeight(0) >= getY(0)) //need to improve, use a better way to detect collision
        &&(bird.getY(0) <= getY(0)+getHeight(0))
        &&(bird.getX(0)+bird.getWidth(0) >= getX(0))
        &&(bird.getX(0) <= getX(0)+getWidth(0)))
        {
            hasBeenEaten = true; //stop rendering item

            if (activate_effect == true) //put in here to do once
            {
                activateEffect(score);
                activate_effect = false;
                playSound(sound);
                srand((int) time(0));
                item_type = rand() % texture.size(); //randomly choose an item type;
                //std::cout << item_type << std::endl;
            }

        }
    else //if bird not collide with item
    {
        activate_effect = true;
    }

}

bool Item::getItemState()
{
    return hasBeenEaten;
}

void Item::itemAnimation() //move candy up and down
{
    k++;
    if (k > 30) //travel distance
    {
        y.at(0) -= 0.2; //speed
        if(k >= 2*30) k = 0;
    }
    else
    {
        y.at(0) += 0.2;
    }
}

void Item::activateEffect(int& score) //need to use other class properties
{
//    bool activate_effect = false;
    switch(item_type)
    {
    case CANDY: //need access to score
        {
            score++;
            break;
        }
    case ENERGY_DRINK:
        {
            std::cout << "I'm a superhero" << std::endl;
            break;
        }
    }
}

int Item::getItemType()
{

    return item_type;
}

void Item::playSound(vector <Mix_Chunk*> &sound)
{
    if(hasBeenEaten == true)
    {
        Mix_PlayChannel(-1, sound.at(3), 0);

    }
}

