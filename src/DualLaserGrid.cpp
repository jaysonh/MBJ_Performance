//
//  DualLaserGrid.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#include "DualLaserGrid.h"

DualLaserGrid::DualLaserGrid( EffectTime t )
{
    time = t;
}

void DualLaserGrid::update( float timelinePos )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameLeft.addPoly();
        frameLeft.getLastPoly().color = ofFloatColor(0,1,0);
        frameLeft.getLastPoly().lineTo(0,0);
        frameLeft.getLastPoly().lineTo(1,0);
        
        frameRight.clear();
        frameRight.addPoly();
        frameRight.getLastPoly().color = ofFloatColor(1,0,0);
        frameRight.getLastPoly().lineTo(0,0);
        frameRight.getLastPoly().lineTo(1,0);
    }
}
