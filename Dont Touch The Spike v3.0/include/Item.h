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

public:
    Item();
    ~Item();
    void loadTexture(SDL_Renderer* renderer);
    void update(int &status, int& score, bool& hasBeenEaten);
    void checkIfEaten(Bird& bird);
};

#endif // ITEM_H_INCLUDED
