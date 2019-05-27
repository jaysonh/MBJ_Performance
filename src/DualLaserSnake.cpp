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
        cout << v << endl;
        if(v < 1.0)
        {
            LaserLine lineLeft( ofVec2f(1.0,0.5), ofVec2f(1.0-v,0.5), ofFloatColor(1,1,1));
            frameLeft.push_back(lineLeft);
         }else if(v < 2.0)
         {
             
             LaserLine lineLeft( ofVec2f(0.0,0.5),
                                 ofVec2f((2.0-v),0.5), ofFloatColor(1,1,1));
             frameLeft.push_back(lineLeft);
             
             LaserLine lineRight( ofVec2f( 0 , 0.5 ),
                                  ofVec2f( (v - 1.0), 0.5 ),
                                  ofFloatColor(1,1,1));
             frameRight.push_back(lineRight);
         }else if(v < 3.0)
         {
             LaserLine lineRight( ofVec2f(0.0,0.5),
                                ofVec2f((3.0-v),0.5), ofFloatColor(1,1,1));
             frameRight.push_back(lineRight);
             
             LaserLine lineCentre( ofVec2f( 0 , 0.5 ),
                                 ofVec2f( (v - 2.0), 0.5 ),
                                 ofFloatColor(1,1,1));
             frameCentre.push_back(lineCentre);
         }
        
        
    }
}
