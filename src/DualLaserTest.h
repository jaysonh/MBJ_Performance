//
//  DualLaserTest.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#ifndef DualLaserTest_h
#define DualLaserTest_h

#include "DualLaserEffect.h"

class DualLaserTest : public DualLaserEffect
{
public:
    
    DualLaserTest( EffectTime time );
    
    void update( float timelinePos, float audioLevel,shared_ptr<vector<float>>audioVals);
    
private:
    
};

#endif /* DualLaserTest_h */
