//
//  DualLaserSnake.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#include "DualLaserSnake.h"

DualLaserSnake::DualLaserSnake( EffectTime t )
{
    time = t;
    
    effectName="snake";
}

void DualLaserSnake::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        float t = (timelinePos - time.start)*0.025;
        
        double param,  intpart;
        
        frameRight.clear();
        frameLeft.clear();
        frameCentre.clear();
        
        float v = modf (t , &intpart) * 3.0;
        
        //left->right->centre
        
        float xRight = ofMap(v,0,1,1,0,true);
        //LaserLine lineRight( ofVec2f(1.0,0.5), ofVec2f(xRight,0.5), ofFloatColor(1,1,1));
        //frameLeft.push_back(lineRight);
        ofVec2f last;
        for(float a1 = 1; a1 > xRight; a1-= 0.01)
        {
            float t1 = timelinePos * 0.1 + a1*TWO_PI;
            //LaserLine lineRight( ofVec2f(1.0,0.5), ofVec2f(xRight,0.5), ofFloatColor(1,1,1));
            ofVec2f p1 = ofVec2f(a1, 0.5 + 0.1 * sin(t1));
            if(a1 < 1.0)
            {
                LaserLine lineRight( p1, last, ofFloatColor(1,1,1));
                lineRight.continous=true;
                frameLeft.push_back(lineRight);
            }
            last = p1;
        }
        
        if(v>1.0)
        {
            float xLeft = ofMap(v,1,2,1,0,true);
            ofVec2f last2;
            for(float a2 = 1; a2 > xLeft; a2 -= 0.01)
            {
                float t2 = timelinePos * 0.1 + a2*TWO_PI;
                ofVec2f p2 = ofVec2f(a2, 0.5 + 0.1 * sin(t2));
                if(a2 < 1.0)
                {
                    LaserLine lineLeft( p2, last2, ofFloatColor(1,0,1));
                    lineLeft.continous=true;
                    frameRight.push_back(lineLeft);
                }
                last2 = p2;
            }
            //LaserLine lineLeft( ofVec2f(0.0,0.5), ofVec2f(1.0-xLeft,0.5), ofFloatColor(1,1,1));
            //frameRight.push_back(lineLeft);
            
            
        }
        if(v>2.0)
        {
            float xCentre = ofMap(v,2,3,1,0,true);
            //LaserLine lineCentre( ofVec2f(1.0,0.5), ofVec2f(xCentre,0.5), ofFloatColor(1,1,1));
            //frameCentre.push_back(lineCentre);
            
            ofVec2f last3;
            for(float a3 = 1; a3 > xCentre; a3 -= 0.01)
            {
                float t3 = timelinePos * 0.1 + a3*TWO_PI;
                ofVec2f p3 = ofVec2f(a3, 0.5 + 0.1 * sin(t3));
                if(a3 < 1.0)
                {
                    LaserLine lineCentre( p3, last3, ofFloatColor(1,1,1));
                    lineCentre.continous=true;
                    frameCentre.push_back(lineCentre);
                }
                last3 = p3;
            }
        }
        
        
    }
}
