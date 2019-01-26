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

class WipeEffect
{
public:
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
};

#endif /* WipeEffect_hpp */
