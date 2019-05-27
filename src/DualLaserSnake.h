//
//  DualLaserSnake.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserSnake_h
#define DualLaserSnake_h

#include "DualLaserEffect.h"

class DualLaserSnake : public DualLaserEffect
{
public:
    
    DualLaserSnake( EffectTime time );
    
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
private:
    
};
#endif /* DualLaserSnake_h */
