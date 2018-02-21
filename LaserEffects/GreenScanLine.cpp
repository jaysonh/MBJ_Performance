//
//  VoiceEffect.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "GreenScanLine.hpp"

GreenScanLine::GreenScanLine(ColorMode colMode)
{
    mCol  = colMode;
    mScan = 0.0;
}

void GreenScanLine::update( float timelinePos, float audioFileDamp, float audioFileMult )
{
    
   
    
    
    
}
ofxIlda::Frame GreenScanLine::getFrame( ofxIlda::Frame * drawFrame )
{
    drawFrame->clear();
    
    
    //if(mScan < PI)
    //{
        float h = fabs( sin(mScan) );
        
        drawFrame->addPoly();
        drawFrame->getLastPoly().color = ofFloatColor(0,1,0);
        drawFrame->getLastPoly().lineTo(0,h);
        drawFrame->getLastPoly().lineTo(1,h);
        //drawFrame->colMode = SCANLINE_ICE_BLUE;
        drawFrame->colMode = mCol;
        
    //}
    drawFrame->update();
    
    mScan += 0.005;
    
    if(mScan > PI) mScan=0.0;
    
    return *drawFrame;
}

void GreenScanLine::sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult)
{
  
}


