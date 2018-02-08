//
//  Timeline.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "Timeline.hpp"

void Timeline::init()
{
    oscRecv.setup(OSC_RECV_PORT);
}

float Timeline::getPos()
{
    return mTimelinePos;
}

void Timeline::draw( ofTrueTypeFont * font)
{
    font->drawString("Timeline: " + ofToString(mTimelinePos), TIMELINE_DRAW_POS.x,TIMELINE_DRAW_POS.y);
    
    // Draw timeline bar
    ofSetColor(125);
    ofDrawRectangle( TIMELINE_BAR.x, TIMELINE_BAR.y, TIMELINE_BAR.width, TIMELINE_BAR.height   );
    
    
    
    ofSetColor( ofColor::white );
    float timelinePerc = mTimelinePos / PERFORMANCE_LENGTH;
    
    ofDrawRectangle( TIMELINE_BAR.x, TIMELINE_BAR.y, timelinePerc * TIMELINE_BAR.width, TIMELINE_BAR.height   );
    
    float xOff = timelinePerc * TIMELINE_BAR.width;
    ofSetColor( ofColor::gray );
    ofDrawLine( TIMELINE_BAR.x + xOff, TIMELINE_BAR.y, TIMELINE_BAR.x + xOff, TIMELINE_BAR.y + TIMELINE_BAR.height);
    
}

void Timeline::update( float timelinePos )
{
    mTimelinePos = timelinePos;
}
