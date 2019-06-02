//
//  DualLaserWipes.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#include "DualLaserWipes.h"

DualLaserWipes::DualLaserWipes( EffectTime t )
{
    time = t;
    
    effectName="laser wipes";
}

void DualLaserWipes::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals)
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        float h1 = abs(sin(ofGetElapsedTimef() * 0.2));
        float h2 = abs(sin(ofGetElapsedTimef() * 0.2));
        float h3 = abs(sin(ofGetElapsedTimef() * 0.2));
        
        LaserLine lineLeft1(ofVec2f(0,h1), ofVec2f(1,h1), ofFloatColor(0,1,0));
        frameLeft.push_back( lineLeft1 );
        
        LaserLine lineRight1(ofVec2f(0,h2), ofVec2f(1,h2), ofFloatColor(0,1,0));
        frameRight.push_back( lineRight1 );
        
        LaserLine lineCentre1(ofVec2f(0,h3), ofVec2f(1,h3), ofFloatColor(0,1,0));
        frameCentre.push_back( lineCentre1 );
    }
}
