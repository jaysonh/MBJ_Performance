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

void DualLaserManager::update()
{
    
}
