//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LineHighlight_h
#define LineHighlight_h


#include <stdio.h>
#include "LaserEffect.hpp"

class LineHighlight
{
public:
    
    LineHighlight( float startTime, float endTime, ColourMode col, ofVec2f startPos,float lineLength )
    {
        mStart = startTime;
        mEnd   = endTime;
        mLinePos = startPos;
        mLineLength = lineLength;
        
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
            
            
            float lineSize = ofMap(timeRunning,0, (mEnd-mStart), 0, mLineLength);
            ofVec2f startPos = ofVec2f(mLinePos.x, mLinePos.y);
            ofVec2f endPos   = ofVec2f( mLinePos.x + lineSize, mLinePos.y);
            
            if(endPos.x > 0.995)endPos.x = 0.995;
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(startPos.x, startPos.y);
            frame->getLastPoly().lineTo(endPos.x,   endPos.y);
            
            
            
        }
        
        return *frame;
    }
    
    float mStart, mEnd;
    float mLineLength=0.0;
    ofVec2f mLinePos;
};
#endif



