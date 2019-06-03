//
//  DualLaserEffect.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/05/2019.
//

#ifndef DualLaserEffect_h
#define DualLaserEffect_h

#include "ofxEtherDream.h"
#include "EffectTime.h"
#include "LaserLine.h"

class DualLaserEffect
{
public:
    DualLaserEffect()
    {
        effectCol = ofColor(ofRandom(255),0,ofRandom(255));
    }
    vector <LaserLine> getFrameLeft()  { return frameLeft;  }
    vector <LaserLine> getFrameRight() { return frameRight; }
    vector <LaserLine> getFrameCentre() { return frameCentre; }
    
    bool isDisplay( float timelinePos ) { return time.isStart( timelinePos ); }
    
    virtual void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals ) = 0;
    
    EffectTime * getTime()  { return &time;      }
    ofColor      getColor() { return effectCol;  }
    string       getName()  { return effectName; }
    
    ColourMode colMode;
protected:
    string effectName="";
    ofColor effectCol;
    vector<LaserLine> frameLeft;
    vector<LaserLine> frameRight;
    vector<LaserLine> frameCentre;
    
    EffectTime time;
    
};

#endif /* DualLaserEffect_h */
