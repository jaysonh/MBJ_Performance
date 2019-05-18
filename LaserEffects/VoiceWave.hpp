//
//  VoiceEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef VoiceWave_hpp
#define VoiceWave_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"
#include "EffectTime.h"

class VoiceWave
{
public:
    VoiceWave( ColourMode col );
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    void stopEffect() {}
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("VoiceWave", mEffectTime);
    }
    EffectTime mEffectTime;
private:
    
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
    
    float v,w;
    
    ColourMode mCol;
    
};

#endif /* VoiceEffect_hpp */

