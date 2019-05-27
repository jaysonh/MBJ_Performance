//
//  DualLaserVoiceWave.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserVoiceWave_h
#define DualLaserVoiceWave_h


#include "DualLaserEffect.h"

class DualLaserVoiceWave : public DualLaserEffect
{
public:
    
    DualLaserVoiceWave( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
private:
    
};

#endif /* DualLaserVoiceWave_h */
