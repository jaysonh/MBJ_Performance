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
    
    Wipe( float startTime, float endTime, float startMap, float endMap )
    {
        mStart = startTime;
        mEnd   = endTime;
        mStartMap = startMap;
        mEndMap  = endMap;
    }
    
    bool isWipeStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    float getWipePos( float timelinePos )
    {
        if(timelinePos >= mStart && timelinePos < mEnd)
        {
            
            float mapPos =ofMap( timelinePos, mStart, mEnd, mStartMap, mEndMap);
            
            //if(mapPos < 0.6)
             //   mapPos -= (mapPos / 0.6) * 0.015*0.5;
            cout << "Mappos: " << mapPos <<endl;
            return mapPos;
        }else
        {
            return -1.0;
        }
    }
    float mStartMap, mEndMap;
    float mStart, mEnd;
};
#endif /* Wipe_h */
