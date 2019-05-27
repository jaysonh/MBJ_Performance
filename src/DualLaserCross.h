//
//  DualLaserGrid.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#ifndef DualLaserCross_h
#define DualLaserCross_h

#include "DualLaserEffect.h"

class DualLaserCross : public DualLaserEffect
{
public:
    
    DualLaserCross( EffectTime time );
    
    void update( float timelinePos, float audioLevel );
    
private:
    
};
#endif /* DualLaserGrid_h */
