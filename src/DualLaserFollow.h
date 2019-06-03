//
//  DualLaserFollow.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DualLaserFollow_h
#define DualLaserFollow_h

#include "DualLaserEffect.h"

class DualLaserFollow : public DualLaserEffect
{
public:
    
    DualLaserFollow( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
private:
    
    
    
};
#endif /* DualLaserFollow_h */
