//
//  DualLaserGrid.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#include "DualLaserCross.h"

DualLaserCross::DualLaserCross( EffectTime t )
{
    time = t;
    
    effectName="cross";
}

void DualLaserCross::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals  )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        LaserLine lineLeft1(ofVec2f(0.5,0), ofVec2f(0.5,1), ofFloatColor(0,1,0));
        LaserLine lineLeft2(ofVec2f(0,0), ofVec2f(0,1), ofFloatColor(0,1,0));
        frameLeft.push_back( lineLeft1 );
        frameLeft.push_back( lineLeft2 );
        
        LaserLine lineRight1(ofVec2f(0.5,0), ofVec2f(0.5,1), ofFloatColor(0,1,0));
        LaserLine lineRight2(ofVec2f(0,0), ofVec2f(0.0,1), ofFloatColor(0,1,0));
        frameRight.push_back( lineRight1 );
        frameRight.push_back( lineRight2 );
        
        
        LaserLine lineCentre1(ofVec2f(0.0,0.5), ofVec2f(1,0.5), ofFloatColor(0,1,0));
        LaserLine lineCentre2(ofVec2f(1.0,0.5), ofVec2f(0.5,0.0), ofFloatColor(0,1,0));
        LaserLine lineCentre3(ofVec2f(0.5,0.0), ofVec2f(0,0.5), ofFloatColor(0,1,0));
        frameCentre.push_back( lineCentre1 );
        frameCentre.push_back( lineCentre2 );
        frameCentre.push_back( lineCentre3 );
    }
}
