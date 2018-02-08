//
//  WipeEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef WipeEffect_hpp
#define WipeEffect_hpp

#include "LaserEffect.hpp"
#include <stdio.h>
#include "Wipe.h"

class WipeEffect : public LaserEffect
{
public:
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
};

#endif /* WipeEffect_hpp */
