//
//  DualLaserManager.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/05/2019.
//

#include "DualLaserManager.h"


void DualLaserManager::init()
{
    
    for(int i = 0; i < NUM_LASERS;i++)
    {
        laser[i].setup(true, i);
        laser[i].setPPS( ETHER_DREAM_PPS );
        cout << "Init laser " << laser[i].getUniqueID() <<endl;
    }
   
    
    if(laser[0].getUniqueID() == 14433133)
        leftIndx  = 0;
    if(laser[0].getUniqueID() == 14449524)
        rightIndx = 0;
    if(laser[0].getUniqueID() == 14418711)
        centreIndx = 0;
    
    if(laser[1].getUniqueID() == 14433133)
        leftIndx  = 1;
    if(laser[1].getUniqueID() == 14449524)
        rightIndx  = 1;
    if(laser[1].getUniqueID() == 14418711)
        centreIndx = 1;
    
    if(laser[2].getUniqueID() == 14433133)
        leftIndx  = 2;
    if(laser[2].getUniqueID() == 14449524)
        rightIndx  = 2;
    if(laser[2].getUniqueID() == 14418711)
        centreIndx = 2;
    
    
    
    setupTimeline();
    loadTestPattern( &testPatternFrameLeft,  "leftKeystone.xml"  );
    loadTestPattern( &testPatternFrameRight, "rightKeystone.xml" );
}

void DualLaserManager::loadTestPattern( ofxIlda::Frame * frame, string keystoneFile)
{}

void DualLaserManager::resetKeystone( ofxIlda::Frame * frame )
{
    frame->clear();
    frame->addPoly();
    frame->getLastPoly().lineTo(0.01,0.01);
    frame->getLastPoly().lineTo(0.99,0.01);
    
    frame->addPoly();
    frame->getLastPoly().lineTo(0.99,0.01);
    frame->getLastPoly().lineTo(0.99,0.99);
    
    frame->addPoly();
    frame->getLastPoly().lineTo(0.99,0.99);
    frame->getLastPoly().lineTo(0.01,0.99);
    
    frame->addPoly();
    frame->getLastPoly().lineTo(0.01,0.99);
    frame->getLastPoly().lineTo(0.01,0.01);
    
    frame->update();
}
void DualLaserManager::loadKeystoneLeft(  )
{
    keystoneLeft.loadJSON( "keystoneLeft.json" );
}

void DualLaserManager::loadKeystoneRight(  )
{
    keystoneRight.loadJSON( "keystoneRight.json" );
    
}

void DualLaserManager::setupTimeline()
{
    effectList.push_back( make_shared<DualLaserTunnel>(EffectTime(0, 600.0)));
}

void DualLaserManager::initLaser(int laserIndx)
{
    
    laser[laserIndx].stop();
    laser[laserIndx].kill();
    
    cout << "CONNECTING TO ETHERDREAM: " << ofToString(laser->getUniqueID()) << endl;
    
    laser[laserIndx].setup(true, laserIndx);
    laser[laserIndx].setPPS( ETHER_DREAM_PPS );
    
}

void DualLaserManager::draw()
{
    ofSetColor(255);
    ofDrawBitmapString("Laser0: " + laser[0].getStateLabel() + " " + ofToString(leftIndx), 20,240);
    ofDrawBitmapString("Laser1: " + laser[1].getStateLabel() + " " + ofToString(rightIndx), 20,260);
    ofDrawBitmapString("Laser2: " + laser[2].getStateLabel() + " " + ofToString(centreIndx), 20,280);
}
void DualLaserManager::resetLeft()
{
    initLaser( leftIndx  );
}
void DualLaserManager::resetRight()
{
    initLaser( rightIndx  );
    
}
void DualLaserManager::testPatternLeftToggle()
{
    testPatternLeft = !testPatternLeft;
}
void DualLaserManager::testPatternRightToggle()
{
    testPatternRight = !testPatternRight;
}

void DualLaserManager::update( float timelinePos, float audioLevel )
{
    lastSavedTime = timelinePos;
    
    for( auto effect : effectList )
    {
        if(effect->isDisplay(timelinePos))
        {
            effect->update(timelinePos,audioLevel);
            vector <LaserLine> rightLines   = effect->getFrameLeft();
            vector <LaserLine> leftLines    = effect->getFrameRight();
            vector <LaserLine> centreLines  = effect->getFrameCentre();
            
            frameLeft.clear();
            frameRight.clear();
            frameCentre.clear();
            
            for( auto line : leftLines )
            {
                frameLeft.addPoly();
                frameLeft.getLastPoly().color = line.col;
                frameLeft.getLastPoly().lineTo( line.begin.x, line.begin.y);
                frameLeft.getLastPoly().lineTo( line.end.x,   line.end.y);
            }
            
            for( auto line : rightLines )
            {
                frameRight.addPoly();
                frameRight.getLastPoly().color = line.col;
                frameRight.getLastPoly().lineTo( line.begin.x, line.begin.y);
                frameRight.getLastPoly().lineTo( line.end.x,   line.end.y);
            }
            
            for( auto line : centreLines )
            {
                frameCentre.addPoly();
                frameCentre.getLastPoly().color = line.col;
                frameCentre.getLastPoly().lineTo( line.begin.x, line.begin.y);
                frameCentre.getLastPoly().lineTo( line.end.x,   line.end.y);
            }
            
            frameLeft.update();
            frameRight.update();
            frameCentre.update();
            
            if(leftIndx  > -1/* && !testPatternLeft*/)
            {
                laser[leftIndx ].setPoints(frameLeft);
                
            }
            if(rightIndx > -1/* && !testPatternRight*/) laser[rightIndx].setPoints(frameRight);
            
            if(centreIndx > -1/* && !testPatternRight*/) laser[centreIndx].setPoints(frameCentre);
        }
    }
    
    if(testPatternRight)
    {
        
    }
    if(testPatternLeft)
    {
        
    }
}
