//
//  LaserGui2.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef LaserGui2_h
#define LaserGui2_h

#include "ofxIldaFrame.h"

class LaserGui2
{
public:
    
    LaserGui2( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        
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
            
            double intPart=0;
            float upDownLinePos = ofMap(modf(ofGetElapsedTimef() * 0.2, &intPart),0,1,0.1,0.9);
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,1,0);
            frame->getLastPoly().lineTo(0.1,0.1);
            frame->getLastPoly().lineTo(0.1,0.9);
            
            frame->addPoly();
            frame->getLastPoly().lineTo(0.1, upDownLinePos);
            frame->getLastPoly().lineTo(0.05, upDownLinePos);
            
            // draw frame for oscilloscope
            frame->addPoly();
            frame->getLastPoly().lineTo(0.6, 0.9);
            frame->getLastPoly().lineTo(0.9, 0.9);
            frame->getLastPoly().lineTo(0.9, 0.65);
            
            
        }
        
        return *frame;
    }
    const float OPEN_TIME = 4.0;
    
    float mStart, mEnd;
};
#endif
