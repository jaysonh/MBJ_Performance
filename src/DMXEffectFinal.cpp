
#include "DMXEffectFinal.h"


DMXEffectFinal::DMXEffectFinal( EffectTime t )
{
    white=0;
    time = new EffectTime(t.start,t.end);
    
    effectName = "Final";
}

void DMXEffectFinal::update( float timelinePos, float voiceLevel )
{
    if(time->isStart(timelinePos))
    {
        float fade = 1.0;
        float timeSinceStart = timelinePos - time->start;
        float timeTillEnd    = time->end - timelinePos;
        float totalTime      = time->end - time->start;
        
        if(timeSinceStart < 2.0)
            fade = ofMap(timeSinceStart,0,2,0,1,true);
       else
           fade = ofMap(timeSinceStart,2, totalTime, 1,0,true);
        
        
        // Nature - the natural physical, material world or universe
        int b = (255.0 *fade);
        int g = (255.0 *fade);
        
        //if( timelinePos >= EffectTime::toSec(9,10) &&
        //    timelinePos < EffectTime::toSec(9,14))
        //{
        dmxChannels[L1+2] =b;
        dmxChannels[L2+2] =b;
        //dmxChannels[L3+2] =b;
        //dmxChannels[L4+2] =b;
        dmxChannels[R1+2] =b;
        dmxChannels[R2+2] =b;
        //dmxChannels[R3+2] =b;
        //dmxChannels[R3+2] =b;
        
        dmxChannels[L1+1] =g;
        dmxChannels[L2+1] =g;
        //dmxChannels[L3+1] =g;
        //dmxChannels[L4+1] =g;
        dmxChannels[R1+1] =g;
        dmxChannels[R2+1] =g;
        //dmxChannels[R3+1] =g;
        //dmxChannels[R3+1] =g;
        // }
        
    }
}
