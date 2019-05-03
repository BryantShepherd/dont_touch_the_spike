#include "HardBird.h"

using namespace std;

HardBird::HardBird()
{
    x.push_back(0);
    y.push_back(SCREEN_HEIGHT/2.0);
    dx = 0;
    dy = 0;
    ddx = 0.1;
    ddy = 0.3;
    change_press_dx = 4;
    change_press_dy = -7.5;
}

HardBird::~HardBird()
{
//    for(auto i: texture)
//    {
//        delete i;
//        i = NULL;
//    }
    x.clear();
    y.clear();
    width.clear();
    height.clear();
    texture.clear();

    x.shrink_to_fit();
    y.shrink_to_fit();
    width.shrink_to_fit();
    height.shrink_to_fit();
    texture.shrink_to_fit();
}
