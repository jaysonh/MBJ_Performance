//
//  DMXEffectIPA.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#include "DMXEffectIPA.h"


DMXEffectIPA::DMXEffectIPA( EffectTime t )
{
    white=0;
    time = new EffectTime(t.start,t.end);
    
    effectName = "IPA";
}

void DMXEffectIPA::update( float timelinePos, float voiceLevel )
{
    if(time->isStart(timelinePos))
    {
        // All off first
        
        float timeFromEnd = time->end - timelinePos;
        
        for(int i = 0; i < numChannels; i++)
            dmxChannels[i]=0;
        float fade = 0.25;
        
        float fadeIn = ofMap( timelinePos - time->start, 0, 15,0,1,true);
        
        if(timeFromEnd < 10.0)
            fadeIn = ofMap( timeFromEnd, 0,10,1,0,true);
        
        int g = int(200.00 * fadeIn);
        int b = int(255.00 * fadeIn);
        dmxChannels[L1+1] =g;
        dmxChannels[L1+2] =0;
        dmxChannels[L2+1] =g;
        dmxChannels[L2+2] =0;
        dmxChannels[L3+1] =g;
        dmxChannels[L3+2] =b;
        dmxChannels[L4+1] =g;
        dmxChannels[L4+2] =b;
        
        
    }
}
