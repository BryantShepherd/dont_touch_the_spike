#include "Player.h"

//Note: status is DuelMode properties, not Player properties, so the naming can be misleading.
Player1::Player1()
{
    x.push_back(SCREEN_WIDTH/2.0);
    y.push_back(SCREEN_HEIGHT/2.0 + 50);
    dx = 0;
    dy = 0;
    ddx = 0.05;
    ddy = 0.3;
    change_press_dx = 2;
    change_press_dy = -7.5;
    is_key_pressed = false;
}

void Player1::handleEvent(SDL_Event event, int &status, vector<Mix_Chunk*> sound)
{
    switch(event.type)
    {
    case SDL_KEYDOWN:
    {
        if(event.key.keysym.sym == SDLK_SPACE && event.key.repeat == 0)
        {
            if(status == GOING_RIGHT)
            {
                dx = change_press_dx; //change in velocity when press SPACE
                dy = change_press_dy;
            }
            else if(status == GOING_LEFT)
            {
                dx = (-1)*change_press_dx;
                dy = change_press_dy;
            }
            is_key_pressed = true;
        }
        break;
    }
}}

Player2::Player2()
{
    x.push_back(SCREEN_WIDTH/2.0);
    y.push_back(SCREEN_HEIGHT/2.0 - 50);
    dx = 0;
    dy = 0;
    ddx = -0.05;
    ddy = 0.3;
    change_press_dx = -2;
    change_press_dy = -7.5;
    is_key_pressed = false;
}

void Player2::handleEvent(SDL_Event event, int &status, vector<Mix_Chunk*> sound)
{
    switch(event.type)
    {
    case SDL_KEYDOWN:
    {
        if(event.key.keysym.sym == SDLK_BACKSPACE && event.key.repeat == 0)
        {
            if(status == GOING_RIGHT)
            {
                dx = (-1)*change_press_dx; //change in velocity when press SPACE
                dy = change_press_dy;
            }
            else if(status == GOING_LEFT)
            {
                dx = change_press_dx;
                dy = change_press_dy;
            }
            is_key_pressed = true;
        }
        break;
    }
}}

void Player1::reset()
{
    x.at(0)=(SCREEN_WIDTH/2.0-26);
    y.at(0)=(SCREEN_HEIGHT/2.0+76);
    dx = 0;
    dy = 0;
    ddx = 0.1;
    ddy = 0.3;
    change_press_dx = 0;
    change_press_dy = -7.5;
    is_key_pressed = false;
}

void Player2::reset()
{
    x.at(0)=(SCREEN_WIDTH/2.0-26);
    y.at(0)=(SCREEN_HEIGHT/2.0-76);
    dx = 0;
    dy = 0;
    ddx = 0.1;
    ddy = 0.0;
    change_press_dx = 0;
    change_press_dy = -7.5;
    is_key_pressed = false;
}

void Player2::update(int &status, int &score, bool &isHittingWall)
{
//    isHittingWall = true;
    if(status == GOING_RIGHT)
    {
        dx -= ddx; //cho de dieu chinh van toc cua cac con chim khac nhau
        dy += ddy;
    }
    else if(status == GOING_LEFT)
    {
        dx += ddx;
        dy += ddy;
    }

    x.at(0) += dx;
    y.at(0) += dy;
    if(x.at(0) > SCREEN_WIDTH-48-20)
    {
        x.at(0) = SCREEN_WIDTH-48-20;
        dx *= -1; //fix de chim dap tuong tu nhien hon
        dy *= 0.9;
        status = GOING_LEFT;
        isHittingWall = true; //for playing sound effect
        score++;

    }
    else if(x.at(0) < 18)
    {
        x.at(0) = 18;
        dx *= -1;
        dy *= 0.9;
        status = GOING_RIGHT;
        isHittingWall = true;
        score++;
    }
    else
    {
        isHittingWall = false;
    }

    if(y.at(0) > SCREEN_HEIGHT-70-48)
    {
        y.at(0) = SCREEN_HEIGHT-70-48;
        status = DEATH;
    }
    if(y.at(0) < 24)
    {
        y.at(0) = 24;
        status = DEATH;
    }

}
