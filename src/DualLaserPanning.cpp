
#include "DualLaserPanning.h"

DualLaserPanning::DualLaserPanning( EffectTime t )
{
    time = t;
    
    effectName="Panning";
}

void DualLaserPanning::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        colMode = ColourMode::PLAIN;
        frameRight.clear();
        frameLeft.clear();
        frameCentre.clear();
        
        float t = abs(sin(timelinePos));
        
        float timeSinceStart = timelinePos-time.start;
        float timeTillEnd = time.end-timelinePos;
        
        float h1 = abs(sin(ofGetElapsedTimef() * 0.2));
        float h2 = abs(sin(ofGetElapsedTimef() * 0.2))*0.5+0.5;
        
       /* LaserLine lineLeft1(ofVec2f(0,h1), ofVec2f(1,h1), ofFloatColor(0,1,0));
        frameLeft.push_back( lineLeft1 );
        
        LaserLine lineRight1(ofVec2f(0,h2), ofVec2f(1,h2), ofFloatColor(0,1,0));
        frameRight.push_back( lineRight1 );
        */
        
        
        // Draw centre laser
        if( timelinePos > EffectTime::toSec(4,13) )
        {
            
            float h3 = abs(sin(ofGetElapsedTimef() * 0.2));
            
            float sz = ofMap(timeSinceStart, 0,4,0,0.5,true);
            
            LaserLine lineCentre1( ofVec2f(0.5-sz,h3),
                                   ofVec2f(0.5+sz,h3),
                                   ofFloatColor(0,1,0) );
            frameCentre.push_back( lineCentre1 );
        }
        // Draw left and right lasers
        if(timelinePos > EffectTime::toSec(4,55))
        {
            float szLR = ofMap(timelinePos -EffectTime::toSec(4,57), 0,4,0,0.5,true);
            
            if(timeTillEnd < 10)
                szLR = ofMap(timeTillEnd, 10,0,0.5,0.0,true);
            
            LaserLine lineRight(ofVec2f(0.5 - szLR,h2), ofVec2f(0.5+szLR,h2), ofFloatColor(0,1,0));
            LaserLine lineLeft(ofVec2f(0,h2), ofVec2f(szLR,h2), ofFloatColor(0,1,0));
            frameRight.push_back( lineRight );
            frameLeft.push_back(  lineLeft );
        }
    }
}
