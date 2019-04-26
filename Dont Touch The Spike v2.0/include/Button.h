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

//cái class này có thể gộp về background được nếu muốn, tách ra cho dễ phân biệt thôi
class Button: public Texture
{
public:
    Button();
    ~Button();
    void loadTexture(SDL_Renderer* renderer);       //hàm load tất cả texture cửa đối tượng
protected:

private:

};

#endif // BUTTON_H
