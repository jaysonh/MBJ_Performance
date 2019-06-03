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
        
        float timeSinceStart =timelinePos - time.start;
        float t1 = ofMap(timeSinceStart,0,15,0,1.0,true);
        float t2 = ofMap(timelinePos,EffectTime::toSec(7,28),EffectTime::toSec(7,33),0,1.0,true);
        float t3 = ofMap(timelinePos,EffectTime::toSec(8,05),EffectTime::toSec(8,10),0,1.0,true);
        
        for(float x = 0.0; x < t2; x+= 0.2)
        {
            LaserLine line( ofVec2f(x,ofNoise(x,h1)*0.5+0.5), ofVec2f(x + 0.01,ofNoise(x,h1)*0.5+0.5), ofFloatColor(1,1,1));
          
            frameRight.push_back(line);
        }
        for(float x = 0.0; x < t3; x+= 0.2)
        {
            LaserLine line( ofVec2f(x,ofNoise(x,h2)*0.5+0.5), ofVec2f(x + 0.01,ofNoise(x,h2)*0.5+0.5), ofFloatColor(1,1,1));
            frameLeft.push_back(line);
        }
        for(float x = 0.0; x < t1; x+= 0.2)
        {
            LaserLine line( ofVec2f(x,ofNoise(x,h3)), ofVec2f(x + 0.01,ofNoise(x,h3)), ofFloatColor(1,1,1));
            frameCentre.push_back(line);
        }
        
    }
}
