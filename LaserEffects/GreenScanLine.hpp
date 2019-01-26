//
//  VoiceEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef GreenScanLine_hpp
#define GreenScanLine_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"

class GreenScanLine  
{
public:
    GreenScanLine( ColourMode colMode);
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
private:
    
    ofxIlda::Frame mIldaFrame;
    
    float mScan;
    ColourMode mCol;
    
};

#endif /* VoiceEffect_hpp */


