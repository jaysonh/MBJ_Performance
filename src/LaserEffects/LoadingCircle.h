//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LoadingCircle_h
#define LoadingCircle_h

#include "ofxIldaFrame.h"
#include "LaserEffect.hpp"
#include "EffectTime.h"

class LoadingCircle
{
public:
    
    LoadingCircle( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        off    = 0;
    }
    
    bool isCircleStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            double intPart=0;
            float off=0.0;
            
            float timeRunning = timelinePos - mStart;
            float totalTime = mEnd - mStart;
            
            for(int i = 0; i < 2; i++)
            {
                float openAmt = ofMap(timeRunning,0,totalTime, 0,2.0);//modf(timeRunning*0.05 + (float)i * off, &intPart) * 2.0;
                
                float radX = 0.11 * (float(i+1));
                float radY = 0.2 * (float(i+1));
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,0.35,0);
                if(openAmt < 1.0)
                {
                    for( float a = 0; a <= TWO_PI * openAmt; a+= 0.05)
                    {
                        float x = 0.5 + radX * cos(a);
                        float y = 0.5 + radY * sin(a);
                        frame->getLastPoly().lineTo(x,y);
                    }
                }else
                {
                    float closedAmt = openAmt - 1.0;
                    
                    for( float a = closedAmt*TWO_PI; a <= TWO_PI; a+= 0.05)
                    {
                        float x = 0.5 + radX * cos(a);
                        float y = 0.5 + radY * sin(a);
                        frame->getLastPoly().lineTo(x,y);
                    }
                    frame->getLastPoly().lineTo(0.5 + radX * cos(TWO_PI), 0.5 + radY * sin(TWO_PI));
                }
            }
        }
        
        off += 0.0200;
        
        if(off > TWO_PI) off = 0.01;
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("LoadingCircle", mEffectTime);
    }
    EffectTime mEffectTime;
    float off;
    float mStart, mEnd;
};
#endif /* Wipe_h */



