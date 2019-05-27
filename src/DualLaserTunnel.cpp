
#include "DualLaserTunnel.h"

DualLaserTunnel::DualLaserTunnel( EffectTime t )
{
    time = t;
    
}

void DualLaserTunnel::update( float timelinePos, float audioLevel )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        LaserLine lineLeft1(ofVec2f(0.5,0), ofVec2f(0.5,1), ofFloatColor(1,1,0));
        frameLeft.push_back( lineLeft1 );
        
        LaserLine lineRight1(ofVec2f(0.5,0), ofVec2f(0.5,1), ofFloatColor(1,1,0));
        frameRight.push_back( lineRight1 );
        
        
        LaserLine lineCentre1(ofVec2f(0.275,0.5), ofVec2f(0.725,0.5), ofFloatColor(1,1,0));
        frameCentre.push_back( lineCentre1 );
    }
}
