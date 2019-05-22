//
//  DualLaserManager.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/05/2019.
//

#ifndef DualLaserManager_h
#define DualLaserManager_h

#include "ofMain.h"
#include "DualLaserEffect.h"
#include "ofxEtherDream.h"

#define ETHER_DREAM_PPS  40000

class DualLaserManager
{
public:
    
    void init();
    void update();
    
private:
    void initLaser(ofxEtherdream * laser);
 
    vector <DualLaserEffect> effectList;
    
    ofxEtherdream laser[2];
    
    int leftIndx  = -1;
    int rightIndx = -1;
    
    const long LEFT_ID  = 23234234;
    const long RIGHT_ID = 21231232;
};

#endif /* DualLaserManager_h */
