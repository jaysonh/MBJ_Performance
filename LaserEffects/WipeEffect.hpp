//
//  WipeEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef WipeEffect_hpp
#define WipeEffect_hpp

#include <stdio.h>
#include "Wipe.h"
#include "ofxIldaFrame.h"
#include "EffectTime.h"

class WipeEffect
{
public:
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Wipe", mEffectTime);
    }
    EffectTime mEffectTime;
};

#endif /* WipeEffect_hpp */
