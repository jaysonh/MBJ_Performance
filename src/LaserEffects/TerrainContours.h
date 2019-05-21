//
//  TerrainContours.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef TerrainContours_h
#define TerrainContours_h

#include "ofxIldaFrame.h"
#include "EffectTime.h"

class TerrainContours
{
public:
    
    TerrainContours( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        
        int bufferSize = 256;
        
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
    
    bool isStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            
            float timeRunning = timelinePos - mStart;
            float timeFromEnd = mEnd - timelinePos;
            
            float opening = 1.0;
            
            if(timeRunning < OPEN_TIME)
            {
                opening = ofMap(timeRunning, 0, OPEN_TIME, 0, 1);
                
            }
            
            if(timeFromEnd < OPEN_TIME)
            {
                opening = ofMap(timeFromEnd, 0, OPEN_TIME, 0, 1);
                
            }
            
            float radius = 0.35 * opening;
            
            float startX = 0.0;
            float startY = 0.0;
            
            //for(int i = 0; i < 3; i++)
            //{
                float xoff = 0;
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(0,1,1);
                for( float a = 0.0; a < TWO_PI; a+= 0.1)
                {
                    
                    float offset = ofMap(ofNoise(xoff, yOff), 0, 1, -0.04, 0.04) * opening;
                    
                    float x = 0.5 + (radius   + offset) * cos(a);
                    float y = 0.5 + (radius*0.5     + offset) * sin(a);
                    
                    if(a==0.0)
                    {
                        startX = x;
                        startY = y;
                    }
                    
                    frame->getLastPoly().lineTo(x,y);
                    
                    xoff += 0.1;
                }
                frame->getLastPoly().lineTo(startX, startY);
                radius += 0.1;
        //    }
        }
        
        yOff += 0.01 * loudness;
        
        return *frame;
    }
    
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult, float timelinePos)
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            mMicrophoneMult = microphoneMult;
            float curVol = 0.0;
            
            // samples are "interleaved"
            int numCounted = 0;
            //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
            if(ofGetFrameNum()%3==0)
                loudness=0;
            
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
                    loudness += abs(left[i]);
                    
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
    }
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Blob", mEffectTime);
    }
    EffectTime mEffectTime;
    
    const float OPEN_TIME = 4.0;
    float yOff=0.0;
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
    float mStart, mEnd;
    float loudness = 1.0;
};
#endif
