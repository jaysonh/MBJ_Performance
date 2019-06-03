
#include "DualLaserTunnel.h"

DualLaserTunnel::DualLaserTunnel( EffectTime t )
{
    time = t;
    
    effectName="tunnel";
}

void DualLaserTunnel::update( float timelinePos, float audioLevel,shared_ptr<vector<float>>audioVals)
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        float h =0.5;
        
        colMode = ColourMode::PLAIN;
        
        // Column1
        ofFloatColor col = ofFloatColor(0,1,1);
        float xLeft = 0.753906;
        float yLeft = 0.70875;
        float xRight = 0.0;
        float yRight = 0.762187;
        
        if(timelinePos > EffectTime::toSec(10,43))
        {
             col = ofFloatColor(1,1,0);
         // Column2
         xLeft = 0.110937;
         yLeft = 0.72;
         xRight = 0.861719;
         yRight = 0.833906;
            
        }
        
        /*LaserLine lineLeft1(ofVec2f(xLeft,yLeft),
                            ofVec2f(xLeft,yLeft+0.1),
                            col);
        
        
        LaserLine lineRight(ofVec2f(xRight,yRight),
                            ofVec2f(xRight,yRight+0.15),
                            col); //0.523438
        */
        LaserLine lineLeft1(ofVec2f(xLeft,yLeft),
                            ofVec2f(xLeft+0.1,yLeft),
                            col);
        
        
        LaserLine lineRight(ofVec2f(xRight,yRight),
                            ofVec2f(xRight+0.1,yRight),
                            col);
        frameRight.push_back( lineRight );
        frameLeft.push_back( lineLeft1 );
        // pos1
        // float xLeft = 0.753906;
        // float yLeft = 0.70875;
        // float xRight = 0.0;
        // float yRight = 0.762187
        // pos2
        // float yLeft = 0.110937;
        // float yLeft = 0.72;
        // float xRight = 0.861719;
        // float yRight = 0.833906;
        //cout <<"right: " << xRight << " y " << yRight <<endl;
        
        
        
    }
}
