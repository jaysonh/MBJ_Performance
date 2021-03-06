//
//  DualLaserGrid.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#ifndef DualLaserGrid_h
#define DualLaserGrid_h

#include "DualLaserEffect.h"

class DualLaserGrid : public DualLaserEffect
{
public:
    
    DualLaserGrid( EffectTime time );
    
    void update( float timelinePos, float audioLevel,shared_ptr<vector<float>>audioVals );
    
private:
    
};
#endif /* DualLaserGrid_h */
