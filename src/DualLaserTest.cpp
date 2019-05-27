//
//  DualLaserGrid.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#include "DualLaserTest.h"

DualLaserTest::DualLaserTest( EffectTime t )
{
    time = t;
    
}

void DualLaserTest::update( float timelinePos, float audioLevel )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        
        LaserLine lineLeft1(ofVec2f(0,0), ofVec2f(0,1), ofFloatColor(1,1,1));
        LaserLine lineLeft2(ofVec2f(0,1), ofVec2f(1,1), ofFloatColor(1,1,1));
        LaserLine lineLeft3(ofVec2f(1,1), ofVec2f(1,0), ofFloatColor(1,1,1));
        LaserLine lineLeft4(ofVec2f(0,0), ofVec2f(1,0), ofFloatColor(1,1,1));
        frameLeft.push_back( lineLeft1 );
        frameLeft.push_back( lineLeft2 );
        frameLeft.push_back( lineLeft3 );
        frameLeft.push_back( lineLeft4 );
        
        LaserLine lineRight1(ofVec2f(0,0), ofVec2f(0,1), ofFloatColor(1,1,1));
        LaserLine lineRight2(ofVec2f(0,1), ofVec2f(1,1), ofFloatColor(1,1,1));
        LaserLine lineRight3(ofVec2f(1,1), ofVec2f(1,0), ofFloatColor(1,1,1));
        LaserLine lineRight4(ofVec2f(0,0), ofVec2f(1,0), ofFloatColor(1,1,1));
        frameLeft.push_back(lineRight1);
        frameLeft.push_back(lineRight2);
        frameLeft.push_back(lineRight3);
        frameLeft.push_back(lineRight4);
        
    }
}
