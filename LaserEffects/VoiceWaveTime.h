//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef VoiceWaveTime_h
#define VoiceWaveTime_h

#include "ofxIldaFrame.h"

class VoiceWaveTime
{
public:
    
    VoiceWaveTime( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        
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
    
    void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult, float timelinePos)
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
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
    }
    
    bool isVoiceStart( float timelinePos )
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
            frame->clear();
            
            ofVec2f lastPos;
            
            float timeSinceStart = timelinePos - mStart;
            float timeTillEnd    = mEnd - timelinePos;
            float open=0;
            
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
            
            
            frame->addPoly();
            
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
                
                if(p.y < 0.05) p.y=0.05;
                if(p.y > 0.95) p.y=0.95;
                if(p.x < 0.05) p.x = 0.05;
                if(p.x > 0.95) p.x = 0.95;
                
                if(x > 0 && p.x > 0.5 *(1.0-open) && p.x < 0.5 + (0.5*open) )
                {
                    frame->getLastPoly().lineTo(p.x,p.y);
                }
            }
            
            v -= 0.02* loudness * 30.0;
            w += 0.04* loudness * 30.0;
            
            
            
            
            
            
            frame->colMode = mCol;//WHITE_FADE;
        }
        
       
        
        return *frame;
    }
    float mStart, mEnd;
    
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
#endif /* Wipe_h */



