//
//  NodeJoinEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef NodeJoinEffect_hpp
#define NodeJoinEffect_hpp

#include <stdio.h>
#include "LaserEffect.hpp"

class NodeJoinEffect : public LaserEffect
{
public:
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    
};
#endif /* NodeJoinEffect_hpp */
