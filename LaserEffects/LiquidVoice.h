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

class LiquidVoice 
{
public:
    LiquidVoice(float startTime, float endTime, ColourMode col)
    {
        mStart = startTime;
        mEnd = endTime;
        
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
    ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame )
    {
        drawFrame->setColMode(mCol);
        drawFrame->clear();
        
        ofVec2f lastPos;
        
        float loudness=0.0;
        
        for (unsigned int i = 0; i < right.size(); i++)
        {
            loudness += abs(right[i]);
            
        }
        loudness *= 0.1;
        if(loudness>1.0)loudness=1.0;
        
       
        
        drawFrame->addPoly();
        t1 += (ofGetElapsedTimef()- lastTime) * 10.5 * loudness + 0.005;
        t2 += (ofGetElapsedTimef()- lastTime) * 7.5 * loudness  + 0.005;
        lastTime = ofGetElapsedTimef();
        
        float period = 2.0;
        float amp    = 0.25;
        
        for(float a = 0; a < 1.0; a+= 0.01)
        {
            float angle = TWO_PI * a * period;
            
            float h = amp * sin(a);
            drawFrame->getLastPoly().lineTo(a, 0.5 + h * cos( angle + t1 ));
        }
        drawFrame->addPoly();
        period = 1.0;
        amp    = 0.15;
        
        for(float a = 0.99; a >=0.0; a-= 0.01)
        {
            float angle = TWO_PI * a * period;
            
            float h = amp * cos(a);
            
            drawFrame->getLastPoly().lineTo(a, 0.5 + h * cos( angle + t1 ));
        }
        
        
        
        drawFrame->colMode = mCol;
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
    
    bool isGuiStart( float timelinePos )
    {
        return( timelinePos > 0.0 && timelinePos >= mStart && timelinePos < mEnd );
    }
    
    void stopEffect() {}
    
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
    
    float mStart, mEnd;
    float t1=0.0 ,t2=0.0;
    ColourMode mCol;
    float lastTime=0.0;
};

#endif /* VoiceEffect_hpp */

