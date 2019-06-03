//
//  DMXEffectTunnel.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DMXEffectTunnel_h
#define DMXEffectTunnel_h


#include "DMXEffect.h"

class DMXEffectTunnel : public DMXEffect
{
public:
    DMXEffectTunnel(){}
    DMXEffectTunnel( EffectTime t );
    void update( float timelinePos, float voiceLevel );
    
protected:
    int white = 0;
};
#endif /* DMXEffectTunnel_h */
