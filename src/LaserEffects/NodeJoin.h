//
//  NodeJoin.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef NodeJoin_h
#define NodeJoin_h
#include "EffectTime.h"

class NodeJoin
{
public:
        NodeJoin( float timelineStart, float timelineEnd, ofVec2f lineBegin, ofVec2f lineEnd )
        {
            mTimelineStart = timelineStart;
            mTimelineEnd   = timelineEnd;
            
            mLineStart = lineBegin;
            mLineEnd   = lineEnd;
            mEffectTime = EffectTime(mTimelineStart,mTimelineEnd);
        }
    
        bool isJoinStart( float timelinePos )
        {
            return( timelinePos >= mTimelineStart && timelinePos < mTimelineEnd );
        }
    
        ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
        {
            frame->setColMode( ColourMode::PLAIN );
            if( timelinePos >= mTimelineStart && timelinePos < mTimelineEnd)
            {
                frame->addPoly();
                frame->getLastPoly().lineTo( mLineStart.x, mLineStart.y );
                frame->getLastPoly().lineTo( mLineEnd.x,   mLineEnd.y );
            }
            
            return *frame;
        }
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("NodeJoin", mEffectTime);
    }
    EffectTime mEffectTime;
    
        ofVec2f mLineStart, mLineEnd;
    
        float mTimelineStart, mTimelineEnd;
};

#endif /* NodeJoin_h */
