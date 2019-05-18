//
//  Timeline.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "Timeline.hpp"

void Timeline::init()
{
    mTotalOffset=0.0;
    mTimelinePos = -1.0;
}

float Timeline::getPos()
{
    return mTimelinePos;
}
void Timeline::clearOffset()
{
    mTotalOffset = 0.0;
}
void Timeline::draw( ofTrueTypeFont * font,ofTrueTypeFont * fontBig )
{
    ofPushMatrix();
    ofTranslate(0,140);
    ofSetColor(ofColor::white);
    font->drawString("Offset:       " + ofToString(mTotalOffset), TIMELINE_DRAW_POS.x,TIMELINE_DRAW_POS.y - 10 );
    font->drawString("Timeline:       " + ofToString(mTimelinePos), TIMELINE_DRAW_POS.x,TIMELINE_DRAW_POS.y + 10 );
    font->drawString("AbletonTime: " + ofToString(mAbletonTime), TIMELINE_DRAW_POS.x,TIMELINE_DRAW_POS.y    + 30 );
    
    // Draw timeline bar
    ofSetColor(125);
    ofDrawRectangle( TIMELINE_BAR.x, TIMELINE_BAR.y, TIMELINE_BAR.width, TIMELINE_BAR.height   );
    
    
    
    ofSetColor( ofColor::white );
    float timelinePerc = mTimelinePos / PERFORMANCE_LENGTH;
    
    ofDrawRectangle( TIMELINE_BAR.x, TIMELINE_BAR.y, timelinePerc * TIMELINE_BAR.width, TIMELINE_BAR.height   );
    
    float xOff = timelinePerc * TIMELINE_BAR.width;
    ofSetColor( ofColor::gray );
    ofDrawLine( TIMELINE_BAR.x + xOff, TIMELINE_BAR.y, TIMELINE_BAR.x + xOff, TIMELINE_BAR.y + TIMELINE_BAR.height);
    
    ofSetColor( ofColor::black);
    string displayTime =  ofToString((int)(mUsedTime / 60)) + "." + ofToString((int)mUsedTime % 60) + "/" + ofToString(mUsedTime);
    ofDrawBitmapString(displayTime, TIMELINE_BAR.x + 5, TIMELINE_BAR.y+17);
    ofPopMatrix();
    
    fontBig->drawString(displayTime, 20,550);
}

void Timeline::update( float timelinePos, float abletonTime, float usedTime, float off )
{
    mTotalOffset = off;
    mTimelinePos = timelinePos;
    mAbletonTime = abletonTime;
    mUsedTime    = usedTime;
}
