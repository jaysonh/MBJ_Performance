//
//  NoEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef NoEffect_hpp
#define NoEffect_hpp

#include <stdio.h>
#include "Wipe.h"
#include "ofxIldaFrame.h"
#include "EffectTime.h"

class NoEffect 
{
public:
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("NoEffect", mEffectTime);
    }
    EffectTime mEffectTime;
};
#endif /* NoEffect_hpp */
