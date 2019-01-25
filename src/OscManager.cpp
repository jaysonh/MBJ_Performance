//
//  OscManager.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 05/02/2018.
//

#include "OscManager.hpp"

OscManager::OscManager()
{
    mTimelinePos=0.0;
    mLastTime=0;
}

void OscManager::init()
{
    mReceiver.setup(PORT);
}

float OscManager::getTimelinePos()
{
    if( mStartTime < 0.0 )
        return mTimelinePos;
    else
        return ofGetElapsedTimef() - mStartTime;
}

void OscManager::update()
{
    while(mReceiver.hasWaitingMessages())
    {
        // get the next message
        ofxOscMessage m;
        mReceiver.getNextMessage(m);
        
        if(m.getAddress() == TIMELINE_OSC_ADDR )
        {
            mTimelinePos = m.getArgAsFloat(0);
            
            mLastTime = mTimelinePos;
            
        }
        
        if(m.getAddress() == PERFORMANCE_START)
        {
            startPerformance();
        }
    }
}

void OscManager::startPerformance()
{
    mStartTime = ofGetElapsedTimef();
}
