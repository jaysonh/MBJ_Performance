//
//  DMXEffectFinal.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DMXEffectFinal_h
#define DMXEffectFinal_h


#include "DMXEffect.h"

class DMXEffectFinal : public DMXEffect
{
public:
    DMXEffectFinal(){}
    DMXEffectFinal( EffectTime t );
    void update( float timelinePos, float voiceLevel );
    
protected:
    int white = 0;
};

#endif /* DMXEffectFinal_h */
