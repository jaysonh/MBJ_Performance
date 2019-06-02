//
//  DualLaserGrid.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#include "DualLaserStriped.h"

DualLaserStriped::DualLaserStriped( EffectTime t )
{
    time = t;
    
    effectName="striped";
}

void DualLaserStriped::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals)
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        float h1 = abs(sin(ofGetElapsedTimef()     * 0.2));
        float h2 = abs(sin(0.3+ ofGetElapsedTimef()* 0.2));
        float h3 = abs(sin(1.1+ofGetElapsedTimef() * 0.2));
        
        for(float x = 0.0; x < 1.0; x+= 0.2)
        {
            LaserLine line( ofVec2f(x,ofNoise(x,h1)), ofVec2f(x + 0.01,ofNoise(x,h1)), ofFloatColor(1,1,1));
          
            frameRight.push_back(line);
        }
        for(float x = 0.0; x < 1.0; x+= 0.2)
        {
            LaserLine line( ofVec2f(x,ofNoise(x,h2)), ofVec2f(x + 0.01,ofNoise(x,h2)), ofFloatColor(1,1,1));
            frameLeft.push_back(line);
        }
        for(float x = 0.0; x < 1.0; x+= 0.2)
        {
            LaserLine line( ofVec2f(x,ofNoise(x,h3)), ofVec2f(x + 0.01,ofNoise(x,h3)), ofFloatColor(1,1,1));
            frameCentre.push_back(line);
        }
        
    }
}
