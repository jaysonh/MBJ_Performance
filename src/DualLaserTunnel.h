//
//  DualLaserTunnel.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserTunnel_h
#define DualLaserTunnel_h

#include "DualLaserEffect.h"

class DualLaserTunnel : public DualLaserEffect
{
public:
    
    DualLaserTunnel( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals);
    
private:
    
};

#endif /* DualLaserTunnel_h */
