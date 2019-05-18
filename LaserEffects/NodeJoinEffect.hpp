//
//  NodeJoinEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef NodeJoinEffect_hpp
#define NodeJoinEffect_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"
#include "EffectTime.h"

class NodeJoinEffect
{
public:
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("NodeJoin", mEffectTime);
    }
    EffectTime mEffectTime;
};
#endif /* NodeJoinEffect_hpp */
