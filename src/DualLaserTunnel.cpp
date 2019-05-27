
#include "DualLaserTunnel.h"

DualLaserTunnel::DualLaserTunnel( EffectTime t )
{
    time = t;
    
}

void DualLaserTunnel::update( float timelinePos, float audioLevel,shared_ptr<vector<float>>audioVals)
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        float h = ofMap(ofGetMouseY(), 0,ofGetHeight(),0,1);
    
       // cout << h << endl;
        
        LaserLine lineLeft1(ofVec2f(0.232812,0.5),
                            ofVec2f(0.232812,0.5+0.1),
                            ofFloatColor(0,1,1));
        frameLeft.push_back( lineLeft1 );
        
        /*
        LaserLine lineRight1(ofVec2f(0,0.325+0.05),
                             ofVec2f(0,0.325+0.125),
                             ofFloatColor(0,1,1)); //0.523438
        frameRight.push_back( lineRight1 );
        
        
        LaserLine lineCentre1(ofVec2f(0.267188,0.325-0.03),
                              ofVec2f(0.267188,0.325+0.07),
                              ofFloatColor(0,1,1));
        frameCentre.push_back( lineCentre1 );
        */
        /*LaserLine lineLeft1(ofVec2f(0.5,0.5),
                            ofVec2f(0.5,0.6),
                            ofFloatColor(1,1,0));
        frameLeft.push_back( lineLeft1 );
        
        
        LaserLine lineRight1(ofVec2f(0,0.525),
                             ofVec2f(0,0.6),
                             ofFloatColor(1,1,0)); //0.523438
        frameRight.push_back( lineRight1 );
        
        
        LaserLine lineCentre1(ofVec2f(0.267188,0.47),
                              ofVec2f(0.267188,0.57), ofFloatColor(1,1,0));
        frameCentre.push_back( lineCentre1 );
         */
    }
}
