//
//  DMXEffectPulse.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#include "DMXEffectPulse.h"


DMXEffectPulse::DMXEffectPulse( EffectTime t )
{
    
}

void DMXEffectPulse::update( float timelinePos )
{
    if(time.isStart(timelinePos))
    {
        float t = timelinePos - time.start;
        
        float bright = abs(sin(t)) *255.0;
        
        for(int i = 0; i < numChannels; i+=3)
        {
            
        }
    }
}
