//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef MicroWave_h
#define MicroWave_h

#include "ofxIldaFrame.h"

#include "EffectTime.h"
class MicroWaveTime
{
public:
    
    MicroWaveTime( float startTime, float endTime, ColourMode colMode, float centreY )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        mCol   = colMode;
        mCentreY = centreY;
        int bufferSize = 256;
        open=0.0;
        
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
    
    bool isWaveStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            microphoneWave.clear();
            for (unsigned int i = 0; i < right.size(); i++)
            {
                microphoneWave.push_back(right[i]);
            }
            frame->addPoly();
            frame->colMode = mCol;
            
            float timeSinceStart = timelinePos - mStart;
            float totalTime      = mEnd - mStart;
            float timeTillEnd    = mEnd - timelinePos;
            
            if(timeSinceStart < 2.0)
            {
                open = ofMap(timeSinceStart,0,2, 0,1);
            }else if(timeTillEnd < 2.0)
            {
                open = ofMap(timeTillEnd, 0, 2, 0,1);
            }else
            {
                open = 1.0;
            }
            for (unsigned int i = 0; i < microphoneWave.size(); i+=4)
            {
                ofVec2f p = ofVec2f( ofMap(i, 0, right.size(),0.05,0.95),
                                     ofClamp(microphoneWave[i]* mMicrophoneMult, -(1.0 - mCentreY), (1.0 - mCentreY)) + mCentreY
                                    );
                
                if(p.y < 0.1) p.y = 0.1;
                if(p.y > 0.9) p.y = 0.9;
                
                
                
                if(i > 0 && p.x > 0.5 *(1.0-open) && p.x < 0.5 + (0.5*open) )
                {
                    float colB = ofRandom(1);
                    
                    //frame->getLastPoly().color = ofFloatColor(1.0,0.0,colB);
                    frame->getLastPoly().lineTo( p.x, 1.0-p.y );
                   
                }
            }
            
            
            frame->update();
            

        }
        
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
            
            for (int i = 0; i < bufferSize; i++)
            {
                if(ofGetFrameNum()%3==0)
                {
                    
                    float curLeft  = (input[i*2]   * 0.5) * mMicrophoneMult;
                    float curRight = (input[i*2+1] * 0.5) * mMicrophoneMult;
                    
                    if(open >= 1.0)
                    {
                        left[i]        = curLeft  * (1.0-microphoneDamp) + prevLeftMic[i]  * microphoneDamp;
                        right[i]       = curRight * (1.0-microphoneDamp) + prevRightMic[i] * microphoneDamp;
                        
                        if(isnan(left[i]))
                            left[i] = 0.0;
                        if(isnan(right[i]))
                            right[i] = 0.0;
                        
                        prevLeftMic[i]  = left[i];
                        prevRightMic[i] = right[i];
                    }
                    
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
        return std::make_pair("VoiceLine", mEffectTime);
    }
    EffectTime mEffectTime;
    
private:
    
    float mStart, mEnd;
    
    ColourMode mCol;
    
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
    float mCentreY;
    float open;
    
};
#endif /* Wipe_h */




