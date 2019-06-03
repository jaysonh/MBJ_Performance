//
//  DMXEffectIntroSection.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#include "DMXEffectIntroSection.h"


DMXEffectIntroSection::DMXEffectIntroSection( EffectTime t )
{
    white=0;
    time = new EffectTime(t.start,t.end);
    
    effectName = "intro";
}

void DMXEffectIntroSection::update( float timelinePos, float voiceLevel )
{
    if(time->isStart(timelinePos))
    {
        float fade = 0.25;
        // Nature - the natural physical, material world or universe
        if(timelinePos > 24.36 && timelinePos < 30.00 )
        {
            int g = ofMap(timelinePos, 24.36, 24.36+fade, 0, 255,true);
            int b = ofMap(timelinePos, 24.36, 24.36+fade, 0, 255,true);
            dmxChannels[L1+1] =g;
            dmxChannels[L1+2] =b;
            dmxChannels[R1+1] =g;
            dmxChannels[R1+2] =b;
        }
        
        // Foot print mined, choices forecast
        if(timelinePos > 51.00 && timelinePos < 54) //till 54
        {
            int g = ofMap(timelinePos, 51.00, 51.00+fade, 0, 255,true);
            int b = ofMap(timelinePos, 51.00, 51.00+fade, 0, 255,true);
            dmxChannels[L2+1] =g;
            dmxChannels[L2+2] =b;
            dmxChannels[R2+1] =g;
            dmxChannels[R2+2] =b;
        }
        
        // Nourish the mind body with goji berries
        if(timelinePos > 61.00 && timelinePos < 64.00) // till 1.04
        {
            int g = ofMap(timelinePos, 61, 61+fade, 0, 255,true);
            int b = ofMap(timelinePos, 61, 61+fade, 0, 255,true);
            dmxChannels[L3+1] =g;
            dmxChannels[L3+2] =b;
            dmxChannels[R3+1] =g;
            dmxChannels[R3+2] =b;
        }
        
        // Optimind, 5HTP neuromaster...
        // 91.00 - 106.00
        if(timelinePos > 91.00 && timelinePos < 106) // till 1.04
        {
            int g = ofMap(timelinePos, 91, 91+fade, 0, 255,true);
            int b = ofMap(timelinePos, 91, 91+fade, 0, 255,true);
            dmxChannels[R1+1] =g;
            dmxChannels[R1+2] =b;
            dmxChannels[R2+1] =b;
            dmxChannels[R2+2] =b;
            dmxChannels[R3+1] =g;
            dmxChannels[R3+2] =b;
            dmxChannels[R4+1] =g;
            dmxChannels[R4+2] =b;
        }
    }
}
