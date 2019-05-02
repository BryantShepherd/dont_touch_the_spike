#include "Spike.h"
#include "time.h"
#include "random"

using namespace std;

Spike::Spike()
{
    spike_number = 0;
}

Spike::~Spike()
{
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

void Spike::loadMedia(SDL_Renderer* renderer)
{
    loadFromFile("assets/sprites/spike.png", renderer);
}

void Spike::update(int &status, int & score, bool &isHittingWall)
{
    srand((int) time(0));
    if(isHittingWall == true) //when bird hit wall, generate randomly-positioned spikes
    {
        setSpikeNumber(score);
        x.clear();
        y.clear();
        if(status == GOING_RIGHT)
        {
            for(int i = 0; i < spike_number; i++)
            {
                x.push_back(SCREEN_WIDTH - width.at(0));
                y.push_back((0 + rand() % (60 + 1 - 0))*height.at(0));
            }
        }
        else if(status == GOING_LEFT)
        {
            for(int i = 0; i < spike_number; i++)
            {
                x.push_back(0);
                y.push_back((0 + rand() % (60 + 1 - 0))*height.at(0));
            }
        }
    }
}

void Spike::setSpikeNumber(int &score)
{
    if (score <= 1)
        spike_number = 1;
    else if(score <= 6)
        spike_number = 2;
    else if (score <= 12)
        spike_number = 3;
    else if (score <= 20)
        spike_number = 4;
    else if (score <= 30)
        spike_number = 5;
    else if(score <= 50)
        spike_number = 6;
    else
        spike_number = 7;
}

/*Hard Mode*/
void Spike::moveSpike()
{
    for(int i = 0; i < spike_number; i++) //voi tat ca gai
    {
        switchDirectionCounter++;
//        cout << switchDirectionCounter << " ";
        if (switchDirectionCounter > 15*getSpikeNumber())
        {
            y.at(i) -= 2;
            if(switchDirectionCounter >= 30*getSpikeNumber()) switchDirectionCounter = 0;
        }
        else
        {
            y.at(i) += 2;
        }

    }
}

int Spike::getSpikeNumber()
{
    return spike_number;
}

void Spike::reset()
{
    spike_number = 0;
}

void Spike::setCollider(int &i, int &status)
{
    if(status == GOING_LEFT)
    {
        collider.at(0).x = x.at(i);
        collider.at(0).y = y.at(i)+4;
        collider.at(0).w = 4;
        collider.at(0).h = 6;

        collider.at(1).x = x.at(i);
        collider.at(1).y = y.at(i)+10;
        collider.at(1).w = 10;
        collider.at(1).h = 6;

        collider.at(2).x = x.at(i);
        collider.at(2).y = y.at(i)+16;
        collider.at(2).w = 16;
        collider.at(2).h = 6;

        collider.at(3).x = x.at(i);
        collider.at(3).y = y.at(i)+22;
        collider.at(3).w = 22;
        collider.at(3).h = 6;

        collider.at(4).x = x.at(i);
        collider.at(4).y = y.at(i)+28;
        collider.at(4).w = 16;
        collider.at(4).h = 6;

        collider.at(5).x = x.at(i);
        collider.at(5).y = y.at(i)+34;
        collider.at(5).w = 10;
        collider.at(5).h = 6;

        collider.at(6).x = x.at(i);
        collider.at(6).y = y.at(i)+40;
        collider.at(6).w = 4;
        collider.at(6).h = 6;
    }
    else if(status == GOING_RIGHT)
    {
        collider.at(0).x = x.at(i)+24-4;
        collider.at(0).y = y.at(i)+4;
        collider.at(0).w = 4;
        collider.at(0).h = 6;

        collider.at(1).x = x.at(i)+24-10;
        collider.at(1).y = y.at(i)+10;
        collider.at(1).w = 10;
        collider.at(1).h = 6;

        collider.at(2).x = x.at(i)+24-16;
        collider.at(2).y = y.at(i)+16;
        collider.at(2).w = 16;
        collider.at(2).h = 6;

        collider.at(3).x = x.at(i)+24-22;
        collider.at(3).y = y.at(i)+22;
        collider.at(3).w = 22;
        collider.at(3).h = 6;

        collider.at(4).x = x.at(i)+24-16;
        collider.at(4).y = y.at(i)+28;
        collider.at(4).w = 16;
        collider.at(4).h = 6;

        collider.at(5).x = x.at(i)+24-10;
        collider.at(5).y = y.at(i)+34;
        collider.at(5).w = 10;
        collider.at(5).h = 6;

        collider.at(6).x = x.at(i)+24-4;
        collider.at(6).y = y.at(i)+40;
        collider.at(6).w = 4;
        collider.at(6).h = 6;
    }
}
