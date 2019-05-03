#ifndef DUELMODE_H_INCLUDED
#define DUELMODE_H_INCLUDED

#include "Player.h"
#include "ClassicMode.h"

class DuelMode : public ClassicMode
{
public:
    DuelMode();
    ~DuelMode();
    void loadMedia(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event, bool &end_loop, int &mode);
    void update(bool &end_loop, int& mode);
    void playSound();
    void render(SDL_Renderer* renderer, bool end_loop);
    void reset();

protected:
    Player1 player1;
    Player2 player2;
    int winner;
};

#endif // DUELMODE_H_INCLUDED
