//
//  DMXHandler.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 23/05/2019.
//

#include "DMXHandler.h"

void DMXHandler::init()
{
    effectList.push_back( make_shared<DMXEffectIntroSection>(EffectTime(24.36, 106.0)));
    effectList.push_back( make_shared<DMXEffectIPA>(EffectTime(160.0, 222.0)));
    
effectList.push_back( make_shared<DMXEffectHeartBeat>(EffectTime(EffectTime::toSec(6,23), EffectTime::toSec(6,42))));
    
    effectList.push_back( make_shared<DMXEffectTunnel>(EffectTime(EffectTime::toSec(9,10), EffectTime::toSec(9,14))));
    
    effectList.push_back( make_shared<DMXEffectTunnel>(EffectTime(EffectTime::toSec(9,38), EffectTime::toSec(9,57))));
    effectList.push_back( make_shared<DMXEffectFinal>(EffectTime(EffectTime::toSec(15,30), EffectTime::toSec(16,8))));
    
    
    dmxOutput.connect("tty.usbserial-EN081467", DMXEffect::numChannels); // use the name
    timelineDrawSz  = ofVec2f( ofGetWidth()/2, (ofGetHeight()/6));
    timelineDrawPos = ofVec2f( ofGetWidth()/2,
                               ofGetHeight()/2 + (ofGetHeight()/6)*2);
}

void DMXHandler::update( float time, float voiceLevel )
{
    currTime = time;
    bool usedEffect=false;
    
    for( auto effect : effectList )
    {
        if(effect->isRunning(time))
        {
            effect->update( time,voiceLevel );
            //cout << "Setting channesl: " << effect->getName()<<endl;
            int * dmxChannels = effect->getChannels();
            usedEffect=true;
            for( int i = 0; i < DMXEffect::numChannels; i++)
                dmxOutput.setLevel(i+1, dmxChannels[i]);
        }
    }
    if(!usedEffect)
    {
        //cout << "Not using effect turning off"<<endl;
        for( int i = 0; i < DMXEffect::numChannels; i++)
            dmxOutput.setLevel(i+1, 0);
        dmxOutput.update();
    }
    dmxOutput.update();
}

void DMXHandler::exit()
{
    for( int i = 0; i < DMXEffect::numChannels; i++)
        dmxOutput.setLevel(i+1, 0);
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
    ofSetColor(0,255,0);
    ofDrawLine( currOff, timelineDrawPos.y,
               currOff, timelineDrawPos.y+timelineDrawSz.y);
    
    ofPopMatrix();
    ofPopStyle();
}
