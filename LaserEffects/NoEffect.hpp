//
//  NoEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef NoEffect_hpp
#define NoEffect_hpp


#include "LaserEffect.hpp"
#include <stdio.h>
#include "Wipe.h"

class NoEffect : public LaserEffect
{
public:
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
};
#endif /* NoEffect_hpp */
