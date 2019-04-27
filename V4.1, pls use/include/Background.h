#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Texture.h"
#include "constant.h"

using namespace std;

class Background: public Texture
{
public:
    Background();
    ~Background();
    void loadTexture(SDL_Renderer* renderer);       //hàm load toàn bộ texture của đối tượng

protected:

private:

};

#endif // BACKGROUND_H
