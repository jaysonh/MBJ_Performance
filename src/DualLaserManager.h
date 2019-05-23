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
#include "DualLaserGrid.h"
#include "ofxEtherDream.h"
#include "KeystoneWarper.h"

#define ETHER_DREAM_PPS  40000

class DualLaserManager
{
public:
    
    void init();
    void draw();
    void update( float timelinePos );
    void resetLeft();
    void resetRight();
    void testPatternLeftToggle();
    void testPatternRightToggle();
    
    void loadKeystoneLeft();
    void loadKeystoneRight();
    
private:
    
    void setupTimeline();
    void initLaser(ofxEtherdream * laser);
    void loadTestPattern( ofxIlda::Frame * frame, string keystoneFile );
    void resetKeystone(   ofxIlda::Frame * frame );

    float lastSavedTime = 0.0;
    
    vector <shared_ptr<DualLaserEffect>> effectList;
    
    KeystoneWarper keystoneLeft;
    KeystoneWarper keystoneRight;
    
    ofxEtherdream laser[2];
    
    int leftIndx  = -1;
    int rightIndx = -1;
    
    const long LEFT_ID  = 23234234;
    const long RIGHT_ID = 21231232;
    
    ofxIlda::Frame frameLeft;
    ofxIlda::Frame frameRight;
    
    ofxIlda::Frame testPatternFrameLeft;
    ofxIlda::Frame testPatternFrameRight;
    
    bool testPatternRight = false;
    bool testPatternLeft  = false;
};

#endif /* DualLaserManager_h */
