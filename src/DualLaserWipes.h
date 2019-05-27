//
//  DualLaserWipes.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserWipes_h
#define DualLaserWipes_h

#include "DualLaserEffect.h"

class DualLaserWipes : public DualLaserEffect
{
public:
    
    DualLaserWipes( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals);
    
private:
    
};

#endif /* DualLaserWipes_h */
