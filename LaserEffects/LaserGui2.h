//
//  LaserGui2.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef LaserGui2_h
#define LaserGui2_h

#include "ofxIldaFrame.h"
#include "EffectTime.h"

class LaserGui2
{
public:
    
    LaserGui2( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        
        mEffectTime = EffectTime(startTime,endTime);
        mCol=col;
    }
    
    bool isGuiStart( float timelinePos )
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
            float fade = opening;
            
            double intPart=0;
            float upDownLinePos = ofMap(modf(ofGetElapsedTimef() * 0.2, &intPart),0,1,0.1,0.9);
            frame->setColMode(mCol);
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,fade,0);
            frame->getLastPoly().lineTo(0.1,0.1);
            frame->getLastPoly().lineTo(0.1,0.9);
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,fade,0);
            frame->getLastPoly().lineTo(0.1, upDownLinePos);
            frame->getLastPoly().lineTo(0.15, upDownLinePos);
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,fade,0);
            frame->getLastPoly().lineTo(0.75, 0.9);
            frame->getLastPoly().lineTo(0.9, 0.9);
            frame->getLastPoly().lineTo(0.9, 0.1);
        }
        
        return *frame;
    }
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Gui2", mEffectTime);
    }
    EffectTime mEffectTime;
    const float OPEN_TIME = 4.0;
    ColourMode mCol;
    float mStart, mEnd;
};
#endif
