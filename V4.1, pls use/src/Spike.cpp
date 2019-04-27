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
        if(status == GO_LEFT)
        {
            for(int i = 0; i < spike_number; i++)
            {
                x.push_back(SCREEN_WIDTH - width.at(0));
                y.push_back((0 + rand() % (60 + 1 - 0))*height.at(0));
            }
        }
        else if(status == GO_RIGHT)
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
            spike_number = 2;
        else if(score <= 4)
            spike_number = 3;
        else if (score <= 10)
            spike_number = 4;
        else if (score <= 15)
            spike_number = 5;
        else if (score <= 25)
            spike_number = 6;
        else if(score <= 40)
            spike_number = 7;
        else
            spike_number = 8;
}

/*Hard Mode*/
void Spike::moveSpike()
{
    for(int i = 0; i < getSpikeNumber(); i++) //voi tat ca gai
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
