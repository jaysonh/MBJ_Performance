//
//  DualLaserYellowScan.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DualLaserYellowScan_h
#define DualLaserYellowScan_h

#include "DualLaserEffect.h"

class DualLaserYellowScan : public DualLaserEffect
{
public:
    
    DualLaserYellowScan( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals);
    
private:
    
};

#endif /* DualLaserYellowScan_h */
