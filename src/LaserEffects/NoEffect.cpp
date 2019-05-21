//
//  NoEffect.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#include "NoEffect.hpp"
void NoEffect::update( float timelinePos, float audioFileDamp, float audioFileMult )
{
    
}
ofxIlda::Frame NoEffect::getFrame( ofxIlda::Frame * drawFrame )
{
    ofxIlda::Frame frame;
    
    frame.clear();
    frame.update();
    
    return frame;
}


void NoEffect::sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult)
{
    
}
