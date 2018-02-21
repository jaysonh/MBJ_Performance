//
//  AudioFileEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef AudioFileEffect_hpp
#define AudioFileEffect_hpp

#include <stdio.h>
#include "ofxSoundPlayerObject.h"
#include "waveformDraw.h"
#include "LaserEffect.hpp"

class AudioFileEffect : public LaserEffect
{
public:
    
    AudioFileEffect(string filepath);
    void stopEffect();
    void start();
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame );
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult);
    
private:
    
    vector <float> audioFileWave;
    vector <float> prevSamplesWav;
    
    ofxSoundOutput       output;
    ofSoundStream        stream;
    ofxSoundPlayerObject player;
    waveformDraw         wave;
    
    ofxIlda::Frame mIldaFrame;
    float               mAudioMult;
};
#endif /* AudioFileEffect_hpp */
