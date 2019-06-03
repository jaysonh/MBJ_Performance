//
//  DualLaserFollow.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#include "DualLaserFollow.h"

DualLaserFollow::DualLaserFollow( EffectTime t )
{
    time = t;
    
    effectName="Follow";
}

void DualLaserFollow::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        
        frameRight.clear();
        frameLeft.clear();
        frameCentre.clear();
        
        float t = (timelinePos - time.start)*0.25;
        
        ofVec2f lastPos;
        
        float mod = (float)(t - (int)t) * 3.0;
        
        float length1 = mod;
        if(length1>1.0)length1=1.0;
        
        float length2 = mod - 1.0;
        if(length2 > 1.0) length2=1.0;
        
        float length3 = mod-2.0;
        if(length3>1.0) length3 = 1.0;
        
        LaserLine lineL(ofVec2f(0,0.5), ofVec2f(length1,0.5),ofFloatColor(1,1,1));
        frameLeft.push_back(lineL);
        
        if(length2>0)
        {
            LaserLine lineR(ofVec2f(0,0.5), ofVec2f(length2,0.5),ofFloatColor(1,1,1));
            frameRight.push_back(lineR);
        }
        
        if(length3>0)
        {
            LaserLine lineC(ofVec2f(0,0.5), ofVec2f(length3,0.5),ofFloatColor(1,1,1));
            frameCentre.push_back(lineC);
        }
            
        /*for(float x = 0; x < width; x += 5)
        {
            
            if(x > 0)
            {
                LaserLine line( ofVec2f(lastPos.x,lastPos.y),
                               ofVec2f(p.x,p.y),ofFloatColor(1,1,1));
                line.continous=true;
                frameCentre.push_back(line);
            }
            lastPos = ofVec2f(p.x,p.y);
            
            //drawFrame->getLastPoly().lineTo(p.x,p.y);
            
        }*/
        
        
        //LaserLine lineLeft( ofVec2f(0.0,0.5),
        //                   ofVec2f((2.0-v),0.5), ofFloatColor(1,1,1));
        //frameLeft.push_back(lineLeft);
        
    }
}
