#include "HardMode.h"

using namespace std;
HardMode::HardMode()
{
    isHittingWall = false;
    status = GOING_RIGHT;
    score = 0;
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
    sound.clear();
    sound.shrink_to_fit();
}

void HardMode::update(bool &end_loop, int &mode)
{
    bird.update(status, score, isHittingWall);
    spike.update(status, score, isHittingWall);
    spike.moveSpike(); //move the spike up and down, increase the difficulty
    item.update(status, isHittingWall);
    item.itemAnimation();
    item.checkIfEaten(bird, score, sound);
    for(int i = 0; i < spike.getSpikeNumber(); i++)
    {
        if(status == GOING_RIGHT)
        {
            if((bird.getY(0)+24 >= spike.getY(i))
                    &&(bird.getY(0) <= spike.getY(i)+10)
                    &&(bird.getX(0)+34 >= spike.getX(i))
                    &&(bird.getX(0) <= spike.getX(i)+30))
            {
                status = DEATH;
            }
        }
        else if(status == GOING_LEFT)
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
        if (playMusic == false)
        {
            Mix_PlayChannel( -1, sound.at(2), 0 ); //only play once
            playMusic = true;
        }
    }
    else
    {
        playMusic = false;
    }
}

void HardMode::reset()
{
    isHittingWall = false;
    status = GOING_RIGHT;
    score = 0;
    frame = 0;
    bird.hardBird();
    spike.reset();
    rock.reset();
}
