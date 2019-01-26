//
//  Timeline.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "Timeline.hpp"

void Timeline::init()
{
    mTimelinePos = -1.0;
}

float Timeline::getPos()
{
    return mTimelinePos;
}

void Timeline::draw( ofTrueTypeFont * font)
{
    ofSetColor(ofColor::white);
    font->drawString("Timeline:       " + ofToString(mTimelinePos), TIMELINE_DRAW_POS.x,TIMELINE_DRAW_POS.y );
    font->drawString("AbletonTime: " + ofToString(mAbletonTime), TIMELINE_DRAW_POS.x,TIMELINE_DRAW_POS.y +20 );
    
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

void Timeline::update( float timelinePos, float abletonTime )
{
    mTimelinePos = timelinePos;
    mAbletonTime = abletonTime;
}
