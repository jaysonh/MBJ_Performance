//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LoadingBar_h
#define LoadingBar_h

#include "ofxIldaFrame.h"
#include "EffectTime.h"

class LoadingBar
{
public:
    
    LoadingBar( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        
        mEffectTime = EffectTime(startTime,endTime);
    }
    
    bool isGuiStart( float timelinePos )
    {
        return( timelinePos > 0.0 && timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            float timeRunning = timelinePos - mStart;
            float timeFromEnd = mEnd - timelinePos;
            float totalTime = mEnd - mStart;
            
            float opening=0.0;
            
            if(timeRunning < (totalTime/2.0) )
            {
                opening = ofMap(timeRunning, 0, totalTime/2.0, 0, 1);
                
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                
                frame->getLastPoly().lineTo(0.1,0.475);
                frame->getLastPoly().lineTo(0.1,0.525);
                frame->getLastPoly().lineTo(0.1 + 0.8*opening,0.525);
                frame->getLastPoly().lineTo(0.1 + 0.8*opening,0.475);
                frame->getLastPoly().lineTo(0.1,0.475);
            }else
            {
                opening = ofMap(timeRunning, totalTime/2.0, totalTime, 1, 0);
                
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                
                frame->getLastPoly().lineTo(0.9,0.475);
                frame->getLastPoly().lineTo(0.9,0.525);
                frame->getLastPoly().lineTo(0.9 - 0.8*opening,0.525);
                frame->getLastPoly().lineTo(0.9 - 0.8*opening,0.475);
                frame->getLastPoly().lineTo(0.9,0.475);
                
            }
            
        }
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("LoadingBar", mEffectTime);
    }
    EffectTime mEffectTime;
    const float OPEN_TIME = 4.0;
    
    float mStart, mEnd;
};
#endif



