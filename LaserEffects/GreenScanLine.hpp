//
//  VoiceEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef GreenScanLine_hpp
#define GreenScanLine_hpp

#include <stdio.h>
#include "LaserEffect.hpp"

class GreenScanLine : public LaserEffect
{
public:
    GreenScanLine( ColorMode colMode);
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
private:
    
    ofxIlda::Frame mIldaFrame;
    
    float mScan;
    ColorMode mCol;
    
};

#endif /* VoiceEffect_hpp */


