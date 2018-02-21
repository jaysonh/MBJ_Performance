//
//  VoiceEffect.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "VoiceWave.hpp"

VoiceWave::VoiceWave(ColorMode col)
{
    int bufferSize = 256;
    
    mCol = col;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    for (int i = 0; i < bufferSize; i++)
    {
        
        left[i]  = 0.0;
        right[i] = 0.0;
        
        prevLeftMic[i] =0;
        prevRightMic[i]=0;
        
    }
    
    bufferCounter    = 0;
    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
}

void VoiceWave::update( float timelinePos, float audioFileDamp, float audioFileMult )
{
    
    microphoneWave.clear();
    for (unsigned int i = 0; i < right.size(); i++)
    {
        microphoneWave.push_back(right[i]);
    }
    
    
    
}
ofxIlda::Frame VoiceWave::getFrame( ofxIlda::Frame * drawFrame )
{
    drawFrame->clear();
    
    ofVec2f lastPos;
    
    float loudness=0.0;
    
    for (unsigned int i = 0; i < microphoneWave.size(); i++)
    {
        loudness += abs(microphoneWave[i]);
        
    }
    loudness *= 0.1;
    if(loudness>1.0)loudness=1.0;
    
    float width = 600;
    float height =400;
    float mX =30.0;
    float mY = 10.0;
    
    
    drawFrame->addPoly();
    
    float maxHeight = 0.4 * loudness * 10.0 ;
    
    for(float x = 0; x < width; x += 5)
    {
        float y = ofMap(mY
                        *sin(v+(x/ofMap(mX,0,width,1,300)))
                        *tan(w+(x/ofMap(mY,0,width,50,200)))
                        *sin(v+(x/ofMap(mY,0,height,1,50))), 0,height, 0,0.5) ;
        if(y >  maxHeight) y =  maxHeight;
        if(y < -maxHeight) y = -maxHeight;
        
        ofVec2f p = ofVec2f( ofMap(x,0,width,0,1),
                            y + 0.5
                            );
        
        if(p.y < 0.0)p.y=0.0;
        if(p.y > 1.0)p.y=1.0;
        
        drawFrame->getLastPoly().lineTo(p.x,p.y);
        
    }
    
    v -= 0.02* loudness * 30.0;
    w += 0.04* loudness * 30.0;
    
    //drawFrame->colMode = YELLOW_BLUE;
    drawFrame->colMode = mCol;
    drawFrame->update();
    
    return *drawFrame;
}

void VoiceWave::sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult)
{
    mMicrophoneMult = microphoneMult;
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    float loudness=0;
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
            loudness += left[i];
            
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

