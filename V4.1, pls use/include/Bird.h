#ifndef BIRD_H
#define BIRD_H

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

class Bird: public Texture
{
public:
    Bird();
    ~Bird();
    void loadMedia(SDL_Renderer* renderer);                                     //hàm load tất cả các texture của đối tượng
    void handleEvent(SDL_Event event, int &status, vector<Mix_Chunk*>);         //hàm nhận tín hiệu bàn phím cửa chim
    void update(int &status, int &score, bool &isHittingWall);                  //hàm update vị trí con chim
    void playSound(vector<Mix_Chunk*>, bool &);
    void pause();
    float getDx();
    float getDy();
    void hardBird();

protected:
    float dx, dy;
    //to change bird properties more easily
    float change_in_dx, change_in_dy; //gravity
    float change_press_dx, change_press_dy; //change of velocity when press SPACE
    bool isKeyPressed;

private:

};

#endif // BIRD_H
