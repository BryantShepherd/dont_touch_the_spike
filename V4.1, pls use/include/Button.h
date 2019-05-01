#ifndef BUTTON_H
#define BUTTON_H

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

class Button: public Texture
{
public:
    Button();
    ~Button();
    void loadMedia(SDL_Renderer* renderer);       //hàm load tất cả texture cửa đối tượng
    void setPosition(int x, int y);
    void handleEvent(SDL_Event event);
    bool isHittingButton();

    void reset();

protected:
    int current_status;
    bool hittingButton;

private:

};

#endif // BUTTON_H
