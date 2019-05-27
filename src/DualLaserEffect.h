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
    
    vector <LaserLine> getFrameLeft()  { return frameLeft;  }
    vector <LaserLine> getFrameRight() { return frameRight; }
    vector <LaserLine> getFrameCentre() { return frameCentre; }
    
    bool isDisplay( float timelinePos ) { return time.isStart( timelinePos ); }
    
    virtual void update( float timelinePos, float audioLevel ) = 0;
protected:
    
    vector<LaserLine> frameLeft;
    vector<LaserLine> frameRight;
    vector<LaserLine> frameCentre;
    
    EffectTime time;
    
};

#endif /* DualLaserEffect_h */
