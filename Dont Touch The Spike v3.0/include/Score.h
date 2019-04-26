#ifndef SCORE_H
#define SCORE_H

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

class Score: public Texture
{
public:
    Score();
    ~Score();
    void loadTexture(SDL_Renderer* renderer);
    void convertToString(int &score);

protected:
    string score_string;
private:

};

#endif // SCORE_H
