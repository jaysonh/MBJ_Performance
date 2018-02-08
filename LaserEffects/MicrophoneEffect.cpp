//
//  VoiceEffect.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "MicrophoneEffect.hpp"

MicrophoneEffect::MicrophoneEffect()
{
    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    for (int i = 0; i < bufferSize; i++)
    {
        
        left[i]  = 0.0;
        right[i] = 0.0;
        
    }
    
    bufferCounter    = 0;
    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
}

void MicrophoneEffect::update( float timelinePos, float audioFileDamp, float audioFileMult )
{
    
    microphoneWave.clear();
    for (unsigned int i = 0; i < right.size(); i++)
    {
        microphoneWave.push_back(right[i]);
    }
    
    
    
}
ofxIlda::Frame MicrophoneEffect::getFrame( ofxIlda::Frame * drawFrame )
{
    drawFrame->clear();
    
    ofVec2f lastPos;
    
    for (unsigned int i = 0; i < microphoneWave.size(); i++)
    {
        ofVec2f p = ofVec2f( ofMap(i, 0, right.size(),0,1), ofClamp(microphoneWave[i]* mMicrophoneMult, -0.5, 0.5) + 0.5 );
        
        if(i > 0)
        {
            drawFrame->addPoly();
            float colB = ofMap(i, 0, microphoneWave.size(), 0, 1);
            drawFrame->getLastPoly().color = ofFloatColor(1.0,0.0,colB);
            
            drawFrame->getLastPoly().lineTo( lastPos.x, lastPos.y );
            drawFrame->getLastPoly().lineTo( p.x,       p.y );
        }
        lastPos = p ;
    }
    
    drawFrame->update();
    
    return *drawFrame;
}

void MicrophoneEffect::sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult)
{
    mMicrophoneMult = microphoneMult;
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    
    for (int i = 0; i < bufferSize; i++)
    {
        if(ofGetFrameNum()%3==0)
        {
            
            float curLeft  = (input[i*2]   * 0.5);
            float curRight = (input[i*2+1] * 0.5);
            
            
            left[i]        = curLeft  * (1.0-microphoneDamp) + prevLeftMic[i]  * microphoneDamp;
            right[i]       = curRight * (1.0-microphoneDamp) + prevRightMic[i] * microphoneDamp;
            
            if(isnan(left[i]))
                left[i] = 0.0;
            if(isnan(right[i]))
                right[i] = 0.0;
            
            prevLeftMic[i]  = left[i];
            prevRightMic[i] = right[i];
            
        }else
        {
            left[i]        *= microphoneDamp;
            right[i]       *= microphoneDamp;
        }
    }
    
    bufferCounter++;
}
