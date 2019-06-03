//
//  DualLaserHeartBeat.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#ifndef DualLaserHeartBeat_h
#define DualLaserHeartBeat_h


#include "DualLaserEffect.h"

class DualLaserHeartBeat : public DualLaserEffect
{
public:
    
    DualLaserHeartBeat( EffectTime time,ColourMode c );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
private:
    
    const float openTime  = 10.0;
    const float closeTime = 4.0;
    
    float lastLoudness=0.0;
    
    float smoothedVol;
    float scaledVol;
    
    float v,w;
    
};

#endif /* DualLaserHeartBeat_h */
