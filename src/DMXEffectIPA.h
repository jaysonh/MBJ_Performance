//
//  DMXEffectIPA.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DMXEffectIPA_h
#define DMXEffectIPA_h


#include "DMXEffect.h"

class DMXEffectIPA : public DMXEffect
{
public:
    DMXEffectIPA(){}
    DMXEffectIPA( EffectTime t );
    void update( float timelinePos, float voiceLevel );
    
protected:
    int white = 0;
};
#endif /* DMXEffectIPA_h */
