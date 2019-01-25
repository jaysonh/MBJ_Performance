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
#define TIMELINE_OSC_ADDR "/FromVDMX/timelinePos"
#define PERFORMANCE_START "/FromAbleton/start"

class OscManager
{
public:
    
    OscManager();
    void init();
    void update();
    
    float getTimelinePos();
    void  startPerformance();
    
private:
    float mStartTime = -1.0;
    
    ofxOscReceiver mReceiver;
    float mTimelinePos;
    float mLastTime;
};

#endif /* OscManager_hpp */
