//
//  VoiceEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef LiquidVoice_hpp
#define VoiceLiquidVoice_hppWave_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"
#include "EffectTime.h"

class LiquidVoice 
{
public:
    LiquidVoice(float startTime, float endTime, ColourMode col, ofFloatColor col1, ofFloatColor col2)
    {
        mStart = startTime;
        mEnd = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        mCol1 = col1;
        mCol2 = col2;
        
        int bufferSize = 256;
        
        mCol = col;
        
        left.assign(bufferSize, 0.0);
        right.assign(bufferSize, 0.0);
        
        for (int i = 0; i < left.size(); i++)
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
        lastTime = ofGetElapsedTimef();
        
    }
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult )
    {
        
        microphoneWave.clear();
        for (unsigned int i = 0; i < right.size(); i++)
        {
            microphoneWave.push_back(right[i]);
        }
        
        
        
    }
    ofxIlda::Frame getFrame(float timelinePos, ofxIlda::Frame * drawFrame )
    {
        drawFrame->setColMode(mCol);
        drawFrame->clear();
        float totalTime = mEnd-mStart;
        
        float timeRunning = timelinePos - mStart;
        float open = 1.0;
        
        if(timeRunning < 8.0)
        {
            open = ofMap(timeRunning,0,8.0,0,1.0);
        }
        if (timeRunning > totalTime-8.0)
        {
            open =  ofMap(timeRunning, totalTime-8.0,totalTime,1,0);
        }
            
        ofVec2f lastPos;
        
        float loudness=0.0;
        
        for (unsigned int i = 0; i < right.size(); i++)
        {
            loudness += abs(right[i]);
            
        }
        
        if(loudness>1.0)loudness=1.0;
        
        
        loudness = lastLoudness * 0.95 + loudness*0.05;
        
        lastLoudness = loudness;
        
        t1 += (ofGetElapsedTimef()- lastTime) * 10.0 * loudness + 0.000;
        t2 += (ofGetElapsedTimef()- lastTime) * 5.0 * loudness  + 0.000;
        lastTime = ofGetElapsedTimef();
        
        float period = 2.0;
        float amp    = 0.1 + 0.2 * loudness*10.0;
        if(amp > 0.5) amp =0.5;
        
        drawFrame->colMode = mCol;
        
        drawFrame->addPoly();
        drawFrame->getLastPoly().color =mCol2;
        for(float a = 0; a < 1.0 * open; a+= 0.01)
        {
            float angle = TWO_PI * a * period;
            
            float h = amp * sin(a);
            float x = a;
            float y = (0.5 + h * cos( angle + t1 )) * 0.5 + 0.5;
            
            drawFrame->getLastPoly().lineTo(x,1.0- y);
        }
        
        period = 1.0;
        amp    = 0.15;
        
        drawFrame->addPoly();
        drawFrame->getLastPoly().color = mCol1;
        for(float a = 0.99 * open; a >=0.0; a-= 0.01)
        {
            float angle = TWO_PI * a * period;
            
            float h = amp *0.9 * cos(a);
            float x = a;
            float y = (0.5 + h * cos( angle + t1 )) * 0.5 + 0.5;
            drawFrame->getLastPoly().lineTo(x, 1.0-y);
        }
        
        drawFrame->update();
        
        return *drawFrame;
    }
    
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult)
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
                
                float curLeft  = (input[i*2]   * 0.5) * mMicrophoneMult;
                float curRight = (input[i*2+1] * 0.5) * mMicrophoneMult;
                
                
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
    
    bool isGuiStart( float timelinePos )
    {
        return( timelinePos > 0.0 && timelinePos >= mStart && timelinePos < mEnd );
    }
    
    void stopEffect() {}
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Liquid", mEffectTime);
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
    float lastLoudness=0.0;
    float mStart, mEnd;
    float t1=0.0 ,t2=0.0;
    ColourMode mCol;
    float lastTime=0.0;
    
    ofFloatColor mCol1, mCol2;
};

#endif /* VoiceEffect_hpp */

