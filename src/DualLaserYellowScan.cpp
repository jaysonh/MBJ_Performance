//
//  DualLaserYellowScan.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#include "DualLaserYellowScan.h"

DualLaserYellowScan::DualLaserYellowScan( EffectTime t )
{
    time = t;
    
    effectName="YellowScan";
}

void DualLaserYellowScan::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals)
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        float timeSinceStart = timelinePos - time.start;
        float open = ofMap(timeSinceStart, 0,4,0,0.5,true);
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        float h1 = abs(sin(ofGetElapsedTimef() * 0.2));
        colMode = ColourMode::WHITE_YELLOW;
        LaserLine lineCentre1(ofVec2f(0.5-open,h1), ofVec2f(0.5+open,h1), ofFloatColor(0,1,0));
        frameCentre.push_back( lineCentre1 );
    }
}
