
#include "DMXEffectHeatBeat.h"


DMXEffectHeartBeat::DMXEffectHeartBeat( EffectTime t )
{
    white=0;
    time = new EffectTime(t.start,t.end);
    
    effectName = "HeartBeat";
}

void DMXEffectHeartBeat::update( float timelinePos, float voiceLevel )
{
    if(time->isStart(timelinePos))
    {
        float fade = 0.25;
        // Nature - the natural physical, material world or universe
        
        float timeSinceStart = timelinePos - time->start;
        int b = (abs(sin(timeSinceStart*0.75)) * 255.0);
        
        dmxChannels[L1+2] =b;
        dmxChannels[L2+2] =b;
        dmxChannels[L3+2] =b;
        dmxChannels[L4+2] =b;
        dmxChannels[R1+2] =b;
        dmxChannels[R2+2] =b;
        dmxChannels[R3+2] =b;
        dmxChannels[R3+2] =b;
        
    }
}
