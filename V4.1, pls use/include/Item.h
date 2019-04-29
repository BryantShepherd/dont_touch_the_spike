#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Bird.h"
#include "Texture.h"
#include "constant.h"
#include "time.h"
#include "random"


class Item: public Texture
{
protected:
    int item_type; //candy, energy drink, shield, ...
    bool hasBeenEaten = false;
    bool activate_effect;
    int k; //animation counter
public:
    Item();
    ~Item();
    void loadTexture(SDL_Renderer* renderer);
    void update(int &status, bool&);
    void checkIfEaten(Bird& bird, int&); //check if item is eaten
    void itemAnimation(); //item move up and down
    bool getItemState(); //return hasBeenEaten
    void activateEffect(int& ); //for each type of item, activate effect accordingly
};

#endif // ITEM_H_INCLUDED
