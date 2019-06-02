//
//  DMXHandler.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#ifndef DMXHandler_h
#define DMXHandler_h

#include "ofxDmx.h"
#include "DMXEffect.h"
#include "DMXEffectPulse.h"
#include "DEFINITIONS.h"

class DMXHandler
{
public:
    
    void init();
    void update( float time );
    void draw();
    
private:
    float  currTime = 0.0;
    ofxDmx dmxOutput;
    ofVec2f timelineDrawPos;
    ofVec2f timelineDrawSz;
    vector <shared_ptr<DMXEffect>> effectList;
    
};
#endif /* DMXHandler_h */
