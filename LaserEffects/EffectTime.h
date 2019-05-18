//
//  EffectTime.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 30/01/2019.
//

#ifndef EffectTime_h
#define EffectTime_h

struct EffectTime
{
public:
    EffectTime()
    {
        start = 0;
        end   = 0;
    }
    EffectTime(float _start, float _end)
    {
        start = _start;
        end   = _end;
    }
    
    bool isStart( float timelinePos )
    {
        return( timelinePos > 0.0 && timelinePos >= start && timelinePos < end );
    }
    float start, end;
};


#endif /* EffectTime_h */
