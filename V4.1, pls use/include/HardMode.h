#ifndef HARDMODE_H_INCLUDED
#define HARDMODE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "ClassicMode.h"
#include "Background.h"
#include "Button.h"
#include "constant.h"
#include "Score.h"

using namespace std;

class HardMode: public ClassicMode //ke thua tu classic mode, cave mode lam tuong tu
{
public:
    HardMode();
    ~HardMode();
    void update(bool &end_loop, int& mode);

protected:

private:

};



#endif // HARDMODE_H_INCLUDED
