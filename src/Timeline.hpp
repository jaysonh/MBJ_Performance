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

#define TIMELINE_DRAW_POS ofVec2f( 10, 240)
#define TIMELINE_BAR ofRectangle(10, 255, 400, 15)

class Timeline
{
public:
    
    void init();
    void draw( ofTrueTypeFont * font);
    void update( float timelinePos );
    
    float getPos();
    
private:
    
    float mTimelinePos;
    
    ofxOscReceiver oscRecv;
    
};
#endif /* Timeline_hpp */
