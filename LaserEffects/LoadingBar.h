//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LoadingBar_h
#define LoadingBar_h

#include "ofxIldaFrame.h"

class LoadingBar
{
public:
    
    LoadingBar( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        
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
            
            float opening = ofMap(timeRunning, 0, mEnd, 0, 1);
                
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            
            frame->getLastPoly().lineTo(0.1,0.475);
            frame->getLastPoly().lineTo(0.1,0.5);
            frame->getLastPoly().lineTo(0.1 + 0.8*opening,0.5);
            frame->getLastPoly().lineTo(0.1 + 0.8*opening,0.45);
            frame->getLastPoly().lineTo(0.1 + 0.8*opening,0.5);
            frame->getLastPoly().lineTo(0.1 + 0.8,0.5);
            frame->getLastPoly().lineTo(0.1 + 0.8,0.475);
            
            
           
        }
        
        return *frame;
    }
    const float OPEN_TIME = 4.0;
    
    float mStart, mEnd;
};
#endif



