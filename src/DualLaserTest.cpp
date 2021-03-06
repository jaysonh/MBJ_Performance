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
    effectName="test";
    
}

void DualLaserTest::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals)
{
    if( time.isStart( timelinePos ))
    {
        // Red    right
        // Left   blue
        // Centre green
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        LaserLine lineRight1(ofVec2f(0.0,0.5), ofVec2f(1.0,0.5), ofFloatColor(1,0,0));
        LaserLine lineRight2(ofVec2f(1.0,0.5), ofVec2f(1.0,1.0), ofFloatColor(1,0,0));
        LaserLine lineRight3(ofVec2f(1.0,1.0), ofVec2f(0.0,1.0), ofFloatColor(1,0,0));
        LaserLine lineRight4(ofVec2f(0.0,1.0), ofVec2f(0.0,0.5), ofFloatColor(1,0,0));
        frameRight.push_back(lineRight1);
        frameRight.push_back(lineRight2);
        frameRight.push_back(lineRight3);
        frameRight.push_back(lineRight4);
        
        
        LaserLine lineLeft1(ofVec2f(0.0,0.5), ofVec2f(1.0,0.5), ofFloatColor(0,0,1));
        LaserLine lineLeft2(ofVec2f(1.0,0.5), ofVec2f(1.0,1.0), ofFloatColor(0,0,1));
        LaserLine lineLeft3(ofVec2f(1.0,1.0), ofVec2f(0.0,1.0), ofFloatColor(0,0,1));
        LaserLine lineLeft4(ofVec2f(0.0,1.0), ofVec2f(0.0,0.5), ofFloatColor(0,0,1));
        frameLeft.push_back(lineLeft1);
        frameLeft.push_back(lineLeft2);
        frameLeft.push_back(lineLeft3);
        frameLeft.push_back(lineLeft4);
        
        
        LaserLine lineCentre1(ofVec2f(0.0,0.5), ofVec2f(1.0,0.5), ofFloatColor(0,1,0));
        LaserLine lineCentre2(ofVec2f(1.0,0.5), ofVec2f(1.0,1.0), ofFloatColor(0,1,0));
        LaserLine lineCentre3(ofVec2f(1.0,1.0), ofVec2f(0.0,1.0), ofFloatColor(0,1,0));
        LaserLine lineCentre4(ofVec2f(0.0,1.0), ofVec2f(0.0,0.5), ofFloatColor(0,1,0));
        frameCentre.push_back(lineCentre1);
        frameCentre.push_back(lineCentre2);
        frameCentre.push_back(lineCentre3);
        frameCentre.push_back(lineCentre4);
        
        
        /*LaserLine lineLeft1(ofVec2f(0,0), ofVec2f(0,1), ofFloatColor(1,1,1));
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
        frameLeft.push_back(lineRight4);*/
        
        
        /*LaserLine lineRight1(ofVec2f(0.5,0.5), ofVec2f(0.5,0.55), ofFloatColor(1,1,1));
        frameRight.push_back(lineRight1);
        
        LaserLine lineLeft1(ofVec2f(0.5,0.5), ofVec2f(0.5,0.55), ofFloatColor(1,1,1));
        frameLeft.push_back(lineLeft1);
        
        
        LaserLine lineCentre(ofVec2f(0.475,0.5), ofVec2f(0.525,0.5), ofFloatColor(1,1,1));
        frameCentre.push_back(lineCentre);*/
        
    }
}
