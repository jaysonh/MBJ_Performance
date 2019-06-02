//
//  DMXHandler.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#include "DMXHandler.h"

void DMXHandler::init()
{
    effectList.push_back( make_shared<DMXEffectPulse>(EffectTime(10, 100.0)));

    dmxOutput.connect("tty.usbserial-EN081467", DMXEffect::numChannels); // use the name
    timelineDrawSz  = ofVec2f( ofGetWidth()/2, (ofGetHeight()/6));
    timelineDrawPos = ofVec2f(ofGetWidth()/2,
                              ofGetHeight()/2 + (ofGetHeight()/6)*2);
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
    
    // Now draw timeline (bottom third)
    ofPushStyle();
    ofNoFill();
    ofSetColor(ofColor::white);
    ofDrawBitmapString("DMX Effects", timelineDrawPos.x, timelineDrawPos.y);
    
    ofDrawRectangle( timelineDrawPos.x, timelineDrawPos.y, timelineDrawSz.x,timelineDrawSz.y);
    ofPushMatrix();
    
    float currOff = ofMap( currTime,
                           0,
                           PERFORMANCE_LENGTH,
                           timelineDrawPos.x,
                           timelineDrawPos.x+ timelineDrawSz.x );
    ofFill();
    ofSetColor(0,255,0);
    ofDrawLine( currOff, timelineDrawPos.y,
                currOff, timelineDrawPos.y+timelineDrawSz.y);
    
    for( auto effect : effectList )
    {
        float offset = ofMap( effect->getTime()->start,
                              0,
                              PERFORMANCE_LENGTH,
                              timelineDrawPos.x,
                              timelineDrawPos.x+ timelineDrawSz.x );
        float timeLength = ( effect->getTime()->getLength()/PERFORMANCE_LENGTH ) * timelineDrawSz.x;
        ofRectangle bar = ofRectangle(offset,timelineDrawPos.y,
                                      timeLength, timelineDrawSz.y);
        ofSetColor(effect->getColor());
        ofDrawRectangle(bar);
        
        if( bar.inside(ofGetMouseX(),ofGetMouseY()))
        {
            ofSetColor(ofColor::white);
            ofDrawBitmapString( effect->getName(), bar.x, bar.y+10);
        }
    }
    ofPopMatrix();
    ofPopStyle();
}
