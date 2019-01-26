//
//  OscManager.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 05/02/2018.
//

#ifndef OscManager_hpp
#define OscManager_hpp

#include <stdio.h>
#include "ofxOsc.h"

#define PORT              9001
#define TIMELINE_OSC_ADDR "/live/beat"
#define PERFORMANCE_START "/Velocity1"
#define BPM               120.0

class OscManager
{
public:
    
    OscManager();
    void init();
    void update();
    
    float getTimelinePos();
    void  startPerformance();
    float getAbletonPos();
    
private:
    float mStartTime = -1.0;
    float mAbletonTime  = -1.0;
    
    ofxOscReceiver mReceiver;
    float mTimelinePos;
    float mLastTime;
    float lastBeatTime = 0.0;
};

#endif /* OscManager_hpp */
