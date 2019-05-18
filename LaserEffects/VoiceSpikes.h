//
//  VoiceEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef VoiceSpikes_hpp
#define VoiceLiquidVoice_hppWave_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxIldaFrame.h"

#include "EffectTime.h"
class VoiceSpikes
{
public:
    VoiceSpikes(float startTime, float endTime, ColourMode col)
    {
        spikeListPosY=0.5;// = ofVec2f(0.5,ofRandom(1));
        mStart = startTime;
        mEnd = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        
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
        drawFrame->clear();
        drawFrame->setColMode(mCol);
        float totalTime = mEnd-mStart;
        
        float timeRunning = timelinePos - mStart;
        float open = 1.0;
        
        if(timeRunning < 4.0)
        {
            open = ofMap(timeRunning,0,4.0,0,1.0);
        }
        if (timeRunning > totalTime-4.0)
        {
            open =  ofMap(timeRunning, totalTime-4.0,totalTime,1,0);
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
        
        float off = ofMap(timeRunning,0,totalTime,1.0,10.0);//4;
        float r = 250.0;
        
        float lastX=0;
        float lastY=0;
        
        float speedMult = ofMap(timeRunning,0,totalTime,0.2,3.0) * 0.15;
        
        float aChange = ofMap(timeRunning,0,totalTime, 1,2);
        float bChange = ofMap(timeRunning,0,totalTime, 1,0.5);
        
        float a = aChange;//1.0;
        float b = bChange;//1.0;
        for(int i = 0; i < 5;i++)
        {
            
            float t1 = timeRunning;//ofGetElapsedTimef();//((float)millis()) / 1000.0;
            float angle1 = (t1* speedMult+ i*0.1) ;
            float  posx1 = 600/2 + r * sin(a * angle1*off);
            float  posy1 = 600/2 + r * cos(b * angle1);
            
            float xScaled1 = ofMap(posx1,0,600,0,1);
            float yScaled1 = ofMap(posy1,0,600,0,1);
            
            float xScaled2 = ofMap(lastX,0,600,0,1);
            float yScaled2 = ofMap(lastY,0,600,0,1);
            
            
            if(i > 0)
            {
                drawFrame->getLastPoly().lineTo(xScaled1,yScaled1);
            }
            lastX = posx1;
            lastY = posy1;
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
        
        
        for (int i = 0; i < bufferSize; i++)
        {
            
            float curLeft  = (input[i*2]   * 0.5) * mMicrophoneMult;
            float curRight = (input[i*2+1] * 0.5) * mMicrophoneMult;
                
                
                left[i]        = curLeft  * (1.0-microphoneDamp) + prevLeftMic[i]  * microphoneDamp;
                right[i]       = curRight * (1.0-microphoneDamp) + prevRightMic[i] * microphoneDamp;
                
                if(isnan(left[i]))
                    left[i] = 0.0;
                if(isnan(right[i]))
                    right[i] = 0.0;
                
                prevLeftMic[i]  = left[i];
                prevRightMic[i] = right[i];
                
            
        }
        
    }
    
    bool isStart( float timelinePos )
    {
        bool started =( timelinePos > 0.0 && timelinePos >= mStart && timelinePos < mEnd );
        
        if(!started) lastLoudness= 0.0;
        
        return started;
    }
    
    void stopEffect() {}
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("VoiceSpikes", mEffectTime);
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
    
    int     drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    float v,w;
    float lastLoudness=0.0;
    float mStart, mEnd;
    float t1=0.0 ,t2=0.0;
    ColourMode mCol;
    float lastTime=0.0;
    
    float spikeListPosY;
    float loudness=0.0;
    int currentPos=0;
    float xPos1=0;
    float yPos1=0;
    float xDir1=0;
    float yDir1=0;
    float xPos2=0;
    float yPos2=0;
    float xDir2=0;
    float yDir2=0;
    
};

#endif /* VoiceEffect_hpp */

