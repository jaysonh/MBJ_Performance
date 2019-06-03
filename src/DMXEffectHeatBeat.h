//
//  DMXEffectHeatBeat.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DMXEffectHeatBeat_h
#define DMXEffectHeatBeat_h

#include "DMXEffect.h"

class DMXEffectHeartBeat : public DMXEffect
{
public:
    DMXEffectHeartBeat(){}
    DMXEffectHeartBeat( EffectTime t );
    void update( float timelinePos, float voiceLevel );
    
protected:
    int white = 0;
};


#endif /* DMXEffectHeatBeat_h */
