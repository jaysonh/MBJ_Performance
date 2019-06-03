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

float OscManager::getTotalOffset()
{
    return totalOffset;
}
float OscManager::getTimelinePos()
{
    if( mStartTime <= -10000.0 )
        return 0.0;
    else
        return ofGetElapsedTimef() - mStartTime;
}

float OscManager::getTime()
{
    /*if(useAbletonTime == 1)
        return getAbletonPos();
    else if(useAbletonTime == 0)
        return getTimelinePos();
    else if(useAbletonTime == 2)
        return mManualTime;*/
    
    return ofGetElapsedTimef() + (60.0 * 14.0 + 51.0);
    //return mVDMXTime;
    //return ofGetElapsedTimef();
}

void  OscManager::setUseAbletonTime(int status)
{
    useAbletonTime = status;
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
        
        if(m.getAddress() == "/FromVDMX/timeline")
        {
            mVDMXTime = m.getArgAsFloat(0);
            
        }
        
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

void OscManager::startManual()
{
    //mManualTime
}

void OscManager::setStartTime(int min, int sec)
{
    startMin=min;
    startSec=sec;
}
void OscManager::revertSavedStartTime()
{
    if( mSavedStartTime > -10000.0 )
        mStartTime = mSavedStartTime;
}

void OscManager::startPerformanceFrom()
{
    int secOffset = startMin * 60 + startSec;
 
    mStartTime = ofGetElapsedTimef() - secOffset;
    
    useAbletonTime = 0;
}
void OscManager::startPerformance()
{
    mSavedStartTime = mStartTime;
    
    mStartTime = ofGetElapsedTimef();
}


void OscManager::skipForward()
{
    if(useAbletonTime == 1)
    {
        mStartTime += 0.3;
        totalOffset +=0.3;
    }
    else if(useAbletonTime == 0)
    {
        mStartTime += 0.3;
        totalOffset +=0.3;
    }
    else if(useAbletonTime == 2)
    {
        mStartTime += 0.3;
        totalOffset +=0.3;
    }
}

void OscManager::skipBackward()
{
    if(useAbletonTime == 1)
    {
        mStartTime -= 0.3;
        totalOffset -=0.3;
    }
    else if(useAbletonTime == 0)
    {
        mStartTime -= 0.3;
        totalOffset -=0.3;
    }
    else if(useAbletonTime == 2)
    {
        mStartTime -= 0.3;
        totalOffset -=0.3;
    }
}
