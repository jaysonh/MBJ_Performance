//
//  DualLaserGrid.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 22/05/2019.
//

#include "DualLaserStars.h"

DualLaserStars::DualLaserStars( EffectTime t )
{
    time = t;
    
    effectName="stars";
}

void DualLaserStars::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        if(ofGetFrameNum()%2==0)
        {
            int numCentre = ofRandom(0,4);
            int numLeft   = ofRandom(0,4);
            int numRight  = ofRandom(0,4);
            
            if(numCentre>0)
                frameCentre.clear();
            for(int i = 0; i < numCentre;i++)
            {
                float sz = 0.1;
                ofVec2f p = ofVec2f(ofRandom(1.0 - sz),ofRandom(1.0-sz));
                
                LaserLine line(ofVec2f(p.x,p.y),ofVec2f(p.x+sz,p.y), ofFloatColor(1,1,1));
                frameCentre.push_back(line);
            }
            
            if(numRight>0)
                frameRight.clear();
            for(int i = 0; i < numRight;i++)
            {
                float sz = 0.1;
                ofVec2f p = ofVec2f(ofRandom(1.0 - sz),ofRandom(1.0-sz));
                
                LaserLine line(ofVec2f(p.x,p.y),ofVec2f(p.x+sz,p.y), ofFloatColor(1,1,1));
                frameRight.push_back(line);
            }
            
            if(numLeft>0)
                frameLeft.clear();
            for(int i = 0; i < numLeft;i++)
            {
                float sz = 0.1;
                ofVec2f p = ofVec2f(ofRandom(1.0 - sz),ofRandom(1.0-sz));
                
                LaserLine line(ofVec2f(p.x,p.y),ofVec2f(p.x+sz,p.y), ofFloatColor(1,1,1));
                frameLeft.push_back(line);
            }
           
        }
    }
}
