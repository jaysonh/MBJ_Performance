//
//  DMXEffectPulse.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#include "DMXEffectPulse.h"


DMXEffectPulse::DMXEffectPulse( EffectTime t )
{
    white=0;
    time = new EffectTime(t.start,t.end);
    
    effectName = "PULSE";
}

void DMXEffectPulse::update( float timelinePos, float voiceLevel )
{
    if(time->isStart(timelinePos))
    {
        white++;
        if(white> 255) white=0;
        float t = timelinePos - time->start;
        
        float bright = abs(sin(t)) *255.0;
        
        for(int i = 0; i < numChannels; i+=3)
        {
            dmxChannels[i] = white;
            dmxChannels[i+1] = white;
            dmxChannels[i+2] = white;
        }
    }
}
