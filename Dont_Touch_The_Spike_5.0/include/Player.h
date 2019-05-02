#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Bird.h"

class Player1 : public Bird
{
public:
    Player1();
    void handleEvent(SDL_Event event, int &status, vector<Mix_Chunk*> sound);
    int getPlayerNumber();
    void reset();

protected:
};

class Player2 : public Bird
{
public:

    Player2();
    void handleEvent(SDL_Event event, int &status, vector<Mix_Chunk*> sound);
    int getPlayerNumber();
    void reset();
    void update(int &status, int &score, bool &isHittingWall);
};

#endif // PLAYER_H_INCLUDED
