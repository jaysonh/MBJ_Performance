//
//  DualLaserStars.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserStars_h
#define DualLaserStars_h


#include "DualLaserEffect.h"

class DualLaserStars : public DualLaserEffect
{
public:
    
    DualLaserStars( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
private:
    
};

#endif /* DualLaserStars_h */
