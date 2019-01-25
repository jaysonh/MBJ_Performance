//
//  Frame.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef Frame_h
#define Frame_h

#include "ofMain.h"
#include "ofxIldaFrame.h"

class Frame
{
public:
    
    Frame( float startPos, float endPos, ofRectangle drawRect )
    {
        mStart    = startPos;
        mEnd      = endPos;
        mDrawRect = drawRect;
    }
    
    bool isFrameStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if(timelinePos >= mStart && timelinePos < mEnd)
        {
            frame->addPoly();
            frame->getLastPoly().lineTo( mDrawRect.x,                   mDrawRect.y );
            frame->getLastPoly().lineTo( mDrawRect.x + mDrawRect.width, mDrawRect.y );
            
            frame->addPoly();
            frame->getLastPoly().lineTo( mDrawRect.x + mDrawRect.width, mDrawRect.y );
            frame->getLastPoly().lineTo( mDrawRect.x + mDrawRect.width, mDrawRect.y + mDrawRect.height );
            
            frame->addPoly();
            frame->getLastPoly().lineTo( mDrawRect.x + mDrawRect.width, mDrawRect.y + mDrawRect.height );
            frame->getLastPoly().lineTo( mDrawRect.x,                   mDrawRect.y + mDrawRect.height );
            
            frame->addPoly();
            frame->getLastPoly().lineTo( mDrawRect.x,                   mDrawRect.y + mDrawRect.height );
            frame->getLastPoly().lineTo( mDrawRect.x,                   mDrawRect.y );
            
        }
        
        return *frame;
    }
    
    float mStart, mEnd;
    ofRectangle mDrawRect;
};

#endif /* Frame_h */
