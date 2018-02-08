//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef Wipe_h
#define Wipe_h

class Wipe
{
public:
    
    Wipe( float startTime, float endTime )
    {
        mStart = startTime;
        mEnd   = endTime;
    }
    
    bool isWipeStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    float getWipePos( float timelinePos )
    {
        if(timelinePos >= mStart && timelinePos < mEnd)
        {
            return ofMap( timelinePos, mStart, mEnd, 0, 1);
        }else
        {
            return -1.0;
        }
    }
    
    float mStart, mEnd;
};
#endif /* Wipe_h */
