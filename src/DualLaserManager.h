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
#include "DualLaserCross.h"
#include "DualLaserTunnel.h"
#include "DualLaserTest.h"
#include "DualLaserStars.h"
#include "DualLaserWipes.h"
#include "DualLaserStriped.h"
#include "DualLaserSnake.h"
#include "DualLaserVoiceWave.h"
#include "ofxEtherDream.h"
#include "KeystoneWarper.h"

#define ETHER_DREAM_PPS  40000

class DualLaserManager
{
public:
    
    void init();
    void draw();
    void update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals );
    
    void resetLeft();
    void resetRight();
    void resetCentre();
    
    void testPatternLeftToggle();
    void testPatternRightToggle();
    void testPatternCentreToggle();
    
    void loadKeystoneLeft();
    void loadKeystoneRight();
    
private:
    
    void setupTimeline();
    void initLaser( int laserIndx );
    void loadTestPattern( ofxIlda::Frame * frame, string keystoneFile );
    void resetKeystone(   ofxIlda::Frame * frame );

    float lastSavedTime = 0.0;
    
    vector <shared_ptr<DualLaserEffect>> effectList;
    
    KeystoneWarper keystoneLeft;
    KeystoneWarper keystoneRight;
    
    static const int NUM_LASERS = 3;
    
    ofxEtherdream laser[ NUM_LASERS ];
    
    int leftIndx  = -1;
    int rightIndx = -1;
    int centreIndx = -1;
    
    const long LEFT_ID  = 23234234;
    const long RIGHT_ID = 21231232;
    
    ofxIlda::Frame frameLeft;
    ofxIlda::Frame frameRight;
    ofxIlda::Frame frameCentre;
    
    ofxIlda::Frame testPatternFrameLeft;
    ofxIlda::Frame testPatternFrameRight;
    
    bool testPatternRight = false;
    bool testPatternLeft  = false;
    vector<float> audioVals;
    
};

#endif /* DualLaserManager_h */
