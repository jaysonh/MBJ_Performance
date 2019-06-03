//
//  DMXEffect.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 02/06/2019.
//

#include "DMXEffect.h"

DMXEffect::DMXEffect()
{
    guiCol = ofColor( 0, ofRandom(0,255),ofRandom(0,255));
}

bool DMXEffect::isRunning( float timelinePos)
{
    return time->isStart(timelinePos);
}
