//
//  FrameEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef FrameEffect_hpp
#define FrameEffect_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"
#include "EffectTime.h"

class FrameEffect 
{
public:
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Frame", mEffectTime);
    }
    EffectTime mEffectTime;
};
#endif /* FrameEffect_hpp */
