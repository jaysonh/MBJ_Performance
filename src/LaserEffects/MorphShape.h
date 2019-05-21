//
//  MorphShape.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef MorphShape_h
#define MorphShape_h

#define NUM_SIDES 4
#include "ofxIldaFrame.h"

#include "EffectTime.h"
class MorphShape
{
public:
    
    MorphShape( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        
        for(int i = 0; i < NUM_SIDES; i++)
        {
            noiseOff[i] = ofRandom(0,100);
            float a= ((float)i / (float)NUM_SIDES)*TWO_PI;
            
            positionsX[i]= 0.5 + 0.2*cos(a);//0.5+ofRandom(-0.2,0.2);
            positionsY[i]= 0.5 + 0.2*sin(a);//0.5+ofRandom(-0.2,0.2);
        }
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
            
            
            float radius = 0.25;
            
            float startX = 0.0;
            float startY = 0.0;
            
            
            float xoff = 0;
            frame->clear();
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,1,0);
            
            for(int i = 0 ;i < NUM_SIDES; i++)
            {
                
                float x = positionsX[i] + ofMap(ofNoise(ofGetElapsedTimef()*0.15, noiseOff[i], positionsX[i]),0,1,-0.35,0.35);
                float y = positionsY[i] + ofMap(ofNoise(ofGetElapsedTimef()*0.15, noiseOff[i], positionsY[i]),0,1,-0.35,0.35);
                
                x= ofClamp(x,0.1,0.9);
                y= ofClamp(y,0.1,0.9);
                if(i==0)
                {
                    startX=x;
                    startY=y;
                }
                frame->getLastPoly().lineTo(x, y);
                xoff+= 0.01;
                
                
            }
            frame->getLastPoly().lineTo(startX, startY);
            yoff += 0.01;
        }
        
        return *frame;
    }
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("MorphShape", mEffectTime);
    }
    EffectTime mEffectTime;
    
    float randNoise[NUM_SIDES];
    float positionsX[NUM_SIDES];
    float positionsY[NUM_SIDES];
    float noiseOff[NUM_SIDES];
    const float OPEN_TIME = 4.0;
    float yoff=0.0;
    
    float mStart, mEnd;
};
#endif
