//
//  DMXEffect.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#ifndef DMXEffect_h
#define DMXEffect_h

#include "ofMain.h"
#include "EffectTime.h"

class DMXEffect
{
public:
    DMXEffect();
    
    int * getChannels() { return dmxChannels; }
    
    virtual void update( float timelinePos ) = 0;
    
    static const int numLights   = 4;
    static const int numChannels = numLights * 3;
    
protected:
    EffectTime time;
    int dmxChannels[ numChannels ];
};
#endif /* DMXEffect_h */
