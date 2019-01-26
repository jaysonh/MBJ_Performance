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

float OscManager::getAbletonPos()
{
    if(mAbletonTime >= 0.0)
        return mAbletonTime + ofClamp(ofGetElapsedTimef() - lastBeatTime, 0.0, (60.0 /BPM ));
    else
        return 0.0;
}

void OscManager::update()
{
    while(mReceiver.hasWaitingMessages())
    {
        // get the next message
        ofxOscMessage m;
        mReceiver.getNextMessage(m);
        cout << m.getAddress() <<endl;
        if(m.getAddress() == TIMELINE_OSC_ADDR )
        {
            int beatNum = m.getArgAsInt(0);
            mAbletonTime = (60.0 /BPM ) * beatNum;
            lastBeatTime = ofGetElapsedTimef();
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
