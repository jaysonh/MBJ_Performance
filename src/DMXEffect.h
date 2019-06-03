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
    
    virtual void update( float timelinePos, float voiceLevel ) = 0;
    
    static const int numLights   = 8;
    static const int numChannels = numLights * 3;
    string getName() { return effectName; }
    ofColor getColor() { return guiCol; }
    EffectTime * getTime() { return time; }
    
    bool isRunning( float timelinePos);
protected:
    
    const int L1 = 0;
    const int L2 = 3;
    const int L3 = 6;
    const int L4 = 9;
    
    const int R1 = 12;
    const int R2 = 15;
    const int R3 = 18;
    const int R4 = 21;
    ofColor guiCol;
    string effectName = "";
    EffectTime * time;
    int dmxChannels[ numChannels ];
};
#endif /* DMXEffect_h */
