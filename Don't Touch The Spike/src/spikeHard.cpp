#include "MainControl.h"
#include "spikeHard.h"
using namespace std;

void SpikeHard::hard_update()
{
    for(int i = 0; i < getQuality(); i++) //voi tat ca gai
    {
        switchDirectionCounter++;
        if (switchDirectionCounter > 10*getQuality())
        {
            moveSpikes(i, 0, -2);
            if(switchDirectionCounter == 20*getQuality()) switchDirectionCounter = 0;
        }
        else
        {
            moveSpikes(i, 0, 2);
        }

    }
}
