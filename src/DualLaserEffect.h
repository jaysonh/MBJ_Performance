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

class DualLaserEffect
{
public:
    
    ofxIlda::Frame getFrameLeft()  { return frameLeft;  }
    ofxIlda::Frame getFrameRight() { return frameRight; }
    
    bool isDisplay( float timelinePos ) { return time.isStart( timelinePos ); }
    
    virtual void update( float timelinePos ) = 0;
protected:
    
    ofxIlda::Frame frameLeft;
    ofxIlda::Frame frameRight;
    
    EffectTime time;
    
};

#endif /* DualLaserEffect_h */
