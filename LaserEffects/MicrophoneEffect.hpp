//
//  VoiceEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef VoiceEffect_hpp
#define VoiceEffect_hpp

#include <stdio.h>
#include "LaserEffect.hpp"

class MicrophoneEffect : public LaserEffect
{
public:
    MicrophoneEffect(ColorMode colMode);
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
private:
    
    ColorMode mCol;
    
    ofxIlda::Frame mIldaFrame;
    
    float mMicrophoneMult;
    
    vector <float> left;
    vector <float> right;
    float prevRightMic[512];
    float prevLeftMic[512];
    
    vector <float> microphoneWave;
    vector <float> audioFileWave;
    
    int     bufferCounter;
    int     drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    float open;
};

#endif /* VoiceEffect_hpp */
