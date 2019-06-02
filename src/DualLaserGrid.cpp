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
    
    effectName="grid";
}

void DualLaserGrid::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        
        LaserLine lineLeft(ofVec2f(0,0), ofVec2f(1,0), ofFloatColor(1,0,0));
        frameLeft.push_back( lineLeft );
        
        
        LaserLine lineRight1(ofVec2f(1,0), ofVec2f(0,1), ofFloatColor(1,0,1));
        LaserLine lineRight2(ofVec2f(1,1), ofVec2f(0,1), ofFloatColor(1,1,1));
        frameRight.push_back( lineRight1 );
        frameRight.push_back( lineRight2 );
        
    }
}
