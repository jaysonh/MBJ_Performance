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

#define PORT              12345
#define TIMELINE_OSC_ADDR "/live/beat"
#define PERFORMANCE_START "/Velocity1"
#define BPM               120.0

class OscManager
{
public:
    
    OscManager();
    void init();
    void update();
    
    float getTime();
    float getTimelinePos();
    float getAbletonPos();

    void setUseAbletonTime(int status);
    void startPerformance();
    void startPerformanceFrom();
    void setStartTime(int min, int sec);
    void startManual();
    void revertSavedStartTime();
    void skipForward();
    void skipBackward();
    float getTotalOffset();
    
private:
    float totalOffset = 0.0;
    
    int startMin, startSec;
    
    int useAbletonTime = 1;
    
    float mStartTime      = -10000.0;
    float mSavedStartTime = -10000.0;
    float mAbletonTime    = -10000.0;
    
    float mManualTime      = -10000.0;
    
    ofxOscReceiver mReceiver;
    float mTimelinePos;
    float mLastTime;
    float lastBeatTime = 0.0;
};

#endif /* OscManager_hpp */
