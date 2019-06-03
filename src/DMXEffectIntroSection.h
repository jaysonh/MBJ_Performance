//
//  DMXEffectIntroSection.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DMXEffectIntroSection_h
#define DMXEffectIntroSection_h

#include "DMXEffect.h"

class DMXEffectIntroSection : public DMXEffect
{
public:
    DMXEffectIntroSection(){}
    DMXEffectIntroSection( EffectTime t );
    void update( float timelinePos, float voiceLevel );
    
protected:
    int white = 0;
};

#endif /* DMXEffectIntroSection_h */
