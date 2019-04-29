#include "HardMode.h"

using namespace std;

HardMode::HardMode()
{
    isHittingWall = false;
    status = 0;
    score = -1;
    frame = 0;
    bird.hardBird(); //change bird speed, ...
}

HardMode::~HardMode()
{
//    delete background;
//    delete bird;
//    delete spike;
//
//    background = NULL;
//    bird = NULL;
//    spike = NULL;
}

void HardMode::update(bool &end_loop, int &mode)
{
    bird.update(status, score, isHittingWall);
    spike.update(status, score, isHittingWall);
    spike.moveSpike(); //move the spike up and down, increase the difficulty
    item.update(status, isHittingWall);
    item.itemAnimation();
    item.checkIfEaten(bird, score);
    background.update(mode); //change background for each mode
    //cout << mode << endl;
    for(int i = 0; i < spike.getSpikeNumber(); i++)
    {
        if(status == GO_LEFT)
        {
            if((bird.getY(0)+24 >= spike.getY(i))
                    &&(bird.getY(0) <= spike.getY(i)+10)
                    &&(bird.getX(0)+34 >= spike.getX(i))
                    &&(bird.getX(0) <= spike.getX(i)+30))
            {
                status = DEATH;
            }
        }
        else if(status == GO_RIGHT)
        {
            if((bird.getY(0) <= spike.getY(i)+10)
                    &&(bird.getY(0)+24 >= spike.getY(i))
                    &&(bird.getX(0) <= spike.getX(i)+30)
                    &&(bird.getX(0)+30 >= spike.getX(i)))
            {
                status = DEATH;
            }
        }
    }

    if(bird.getY(0) == 0 || bird.getY(0) == SCREEN_HEIGHT-24)
    {
        status = DEATH;
    }
    if(status == DEATH)
    {
        bird.pause();
        Mix_PlayChannel(-1, sound.at(2), 0);
    }
}

