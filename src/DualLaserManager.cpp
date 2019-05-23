//
//  DualLaserManager.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/05/2019.
//

#include "DualLaserManager.h"


void DualLaserManager::init()
{
    if(laser[0].getUniqueID() == 14433133)
        leftIndx  = 0;
    if(laser[0].getUniqueID() == 14449524)
        rightIndx = 0;
    
    if(laser[1].getUniqueID() == 14433133)
        leftIndx  = 1;
    if(laser[1].getUniqueID() == 14449524)
        rightIndx  = 1;
    
    if(leftIndx  > -1)
        initLaser( &laser[leftIndx]  );
    if(rightIndx > -1)
        initLaser( &laser[rightIndx] );
    
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
    effectList.push_back( make_shared<DualLaserGrid>(EffectTime(0, 100.0)));
}

void DualLaserManager::initLaser(ofxEtherdream * laser)
{
    laser->stop();
    laser->kill();
    
    cout << "CONNECTING TO ETHERDREAM: " << ofToString(laser->getUniqueID()) << endl;
    
    int laserID = 0;
    
    laser->setup(true, 0);
    laser->setPPS( ETHER_DREAM_PPS );
    
}

void DualLaserManager::draw()
{
    
}
void DualLaserManager::resetLeft()
{
    initLaser( &laser[leftIndx]  );
}
void DualLaserManager::resetRight()
{
    initLaser( &laser[rightIndx]  );
    
}
void DualLaserManager::testPatternLeftToggle()
{
    testPatternLeft = !testPatternLeft;
}
void DualLaserManager::testPatternRightToggle()
{
    testPatternRight = !testPatternRight;
}

void DualLaserManager::update( float timelinePos )
{
    lastSavedTime = timelinePos;
    
    for( auto effect : effectList )
    {
        if(effect->isDisplay(timelinePos))
        {
            frameLeft  = effect->getFrameLeft();
            frameRight = effect->getFrameRight();
            
            if(leftIndx  > -1 && !testPatternLeft)  laser[leftIndx ].setPoints(frameLeft);
            if(rightIndx > -1 && !testPatternRight) laser[rightIndx].setPoints(frameRight);
        }
    }
    
    if(testPatternRight)
    {
        
    }
    if(testPatternLeft)
    {
        
    }
}
