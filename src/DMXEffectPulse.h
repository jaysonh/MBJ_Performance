//
//  DMXEffectPulse.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#ifndef DMXEffectPulse_h
#define DMXEffectPulse_h

#include "DMXEffect.h"

class DMXEffectPulse : public DMXEffect
{
public:
    DMXEffectPulse(){}
    DMXEffectPulse( EffectTime t );
    void update( float timelinePos, float voiceLevel );
    
protected:
    int white = 0;
};

#endif /* DMXEffectPulse_h */
