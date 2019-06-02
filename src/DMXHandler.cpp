//
//  DMXHandler.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#include "DMXHandler.h"

void DMXHandler::init()
{
    effectList.push_back( make_shared<DMXEffectPulse>(EffectTime(0, 600.0)));

    dmxOutput.connect("tty.usbserial-EN081467", DMXEffect::numChannels); // use the name
    
}

void DMXHandler::update( float time )
{
    currTime = time;
    
    for( auto effect : effectList )
    {
        effect->update( time );
        
        int * dmxChannels = effect->getChannels();
        
        for( int i = 1; i <= DMXEffect::numChannels; i++)
            dmxOutput.setLevel(i, dmxChannels[i]);
    }
    
    dmxOutput.update();
}

void DMXHandler::draw()
{
    
    if(dmxOutput.isConnected())
    {
        ofSetColor(ofColor::green);
        ofDrawBitmapString("DMX Connected",20,320 );
    }else
    {
        ofSetColor(ofColor::red);
        ofDrawBitmapString("DMX Disconnected",20,320 );
        
    }
}
