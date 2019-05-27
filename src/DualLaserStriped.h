//
//  DualLaserStriped.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserStriped_h
#define DualLaserStriped_h


#include "DualLaserEffect.h"

class DualLaserStriped : public DualLaserEffect
{
public:
    
    DualLaserStriped( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals);
    
private:
    
};
#endif /* DualLaserStriped_h */
