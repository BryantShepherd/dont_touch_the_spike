#include "HardSpike.h"

using namespace std;

HardSpike::HardSpike()
{
    spike_number = 0;
}

HardSpike::~HardSpike()
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

void HardSpike::moveSpikes(int i, float dis_x, float dis_y)
{
    x[i] += dis_x;
    y[i] += dis_y;
}

void HardSpike::hardUpdate()
{
    for(int i = 0; i < getSpikeNumber(); i++) //voi tat ca gai
    {
        switchDirectionCounter++;
//        cout << switchDirectionCounter << " ";
        if (switchDirectionCounter > 15*getSpikeNumber())
        {
            moveSpikes(i, 0, -2);
            if(switchDirectionCounter == 30*getSpikeNumber()) switchDirectionCounter = 0;
        }
        else
        {
            moveSpikes(i, 0, 2);
        }

    }
}
