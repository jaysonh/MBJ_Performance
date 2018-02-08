//
//  OscManager.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 05/02/2018.
//

#include "OscManager.hpp"

OscManager::OscManager()
{
}

void OscManager::init()
{
    mReceiver.setup(PORT);
}

float OscManager::getTimelinePos()
{
    return mTimelinePos;
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
        }
    }
}
