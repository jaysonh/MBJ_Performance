
#include "DMXEffectTunnel.h"


DMXEffectTunnel::DMXEffectTunnel( EffectTime t )
{
    white=0;
    time = new EffectTime(t.start,t.end);
    
    effectName = "Tunnel";
}

void DMXEffectTunnel::update( float timelinePos, float voiceLevel )
{
    if(time->isStart(timelinePos))
    {
        float fade = 0.25;
        // Nature - the natural physical, material world or universe
        int b = (255.0 *voiceLevel);
        int g = (255.0 *voiceLevel);
        
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
