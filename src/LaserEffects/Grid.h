//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef Grid_h
#define Grid_h

#include "EffectTime.h"
class Grid
{
public:
    
    Grid( float startTime, float endTime )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
    }
    
    bool isGridStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            for( int y = 0; y < 5; y++)
            {
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                
                float yPos = ((float)y / 5.0);
                if(y % 2==0)
                {
                    frame->getLastPoly().lineTo( 0, yPos );
                    frame->getLastPoly().lineTo( 1.0,yPos);
                }else
                {
                    frame->getLastPoly().lineTo( 1.0, yPos );
                    frame->getLastPoly().lineTo( 0.0,yPos);
                }
            }
            for( int x = 0; x < 5; x++)
            {
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                
                float xPos = ((float)x / 5.0);
                if(x % 2==0)
                {
                    frame->getLastPoly().lineTo( xPos,0 );
                    frame->getLastPoly().lineTo( xPos,1);
                }else
                {
                    frame->getLastPoly().lineTo( xPos,1 );
                    frame->getLastPoly().lineTo( xPos,0);
                }
            }
        }
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Grid", mEffectTime);
    }
    EffectTime mEffectTime;
    float mStart, mEnd;
};
#endif /* Wipe_h */

