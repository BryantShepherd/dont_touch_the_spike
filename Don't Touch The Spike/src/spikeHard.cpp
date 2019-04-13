#include "spikeHard.h"
using namespace std;

void SpikeHard::hard_update()
{
    for(int i = 0; i < getQuality(); i++) //voi tat ca gai
    {
        switchDirectionCounter++;
        if (switchDirectionCounter > 10)
        {
            if(switchDirectionCounter == 10) switchDirectionCounter = 0;
            moveSpikes(i, 0, -0.5);
        }
        else
        {
            moveSpikes(i, 0, 0.5);
        }

    }
}
