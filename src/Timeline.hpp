//
//  Timeline.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef Timeline_hpp
#define Timeline_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"
#include "DEFINITIONS.h"

#define OSC_RECV_PORT 12345

#define TIMELINE_DRAW_POS ofVec2f( 10, 230)
#define TIMELINE_BAR ofRectangle(10, 275, 400, 25)

class Timeline
{
public:
    
    void init();
    void draw( ofTrueTypeFont * font, ofTrueTypeFont * fontBig);
    void update( float timelinePos, float abletonTime, float usedTime, float off );
    void clearOffset();
    
    float getPos();
    
private:
    float mTotalOffset;
    float mTimelinePos;
    float mAbletonTime;
    float mUsedTime;
    
};
#endif /* Timeline_hpp */
