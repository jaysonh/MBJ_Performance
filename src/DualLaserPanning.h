//
//  DualLaserPanning.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DualLaserPanning_h
#define DualLaserPanning_h


#include "DualLaserEffect.h"

class DualLaserPanning : public DualLaserEffect
{
public:
    
    DualLaserPanning( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
private:
    
    
};

#endif /* DualLaserPanning_h */
