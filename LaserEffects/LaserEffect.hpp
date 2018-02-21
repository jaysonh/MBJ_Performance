//
//  LaserEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef LaserEffect_hpp
#define LaserEffect_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"

class LaserEffect
{
public:
    
    virtual void update( float timelinePos, float audioFileDamp, float audioFileMult ) = 0;
    virtual ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame) = 0;
    virtual void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult) = 0;
    virtual void stopEffect() =0;
};

#endif /* LaserEffect_hpp */
