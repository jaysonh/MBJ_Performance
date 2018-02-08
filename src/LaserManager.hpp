//
//  LaserManager.hpp
//  StarOfBethlehem
//
//  Created by Jayson Haebich on 27/09/2016.
//
//

#ifndef LaserManager_hpp
#define LaserManager_hpp

#include <stdio.h>
#include "ofxEtherDream.h"
#include "LaserEffect.hpp"
#include "WipeEffect.hpp"
#include "FrameEffect.hpp"
#include "NodeJoinEffect.hpp"
#include "MicrophoneEffect.hpp"
#include "AudioFileEffect.hpp"
#include "Wipe.h"
#include "NoEffect.hpp"
#include "Frame.h"
#include "NodeJoin.h"

#define ETHER_DREAM_PPS  50000

#define CHECK_TIME 25.0

enum LaserEffecType { NONE, VOICE, AUDIOFILE1, WIPE, FRAME, NODEJOIN };

#define KEYSTONE_FILE "keystone.txt"

class LaserManager
{
public:
    
    LaserManager();
    
    void init();
    
    void update( float timelinePos, float audioFileDamp, float audioFileMult );
    
    ofxIlda::Frame sendFrames(ofxIlda::Frame frame);
    
    void setEffect( LaserEffecType type );
    void draw( ofTrueTypeFont * font);
    
    void reset( );
    void blank();
    
    void toggleBlank();
    
    void setPPS(int pps);
    
    void mousePressed(  ofVec2f mouse );
    void mouseDragged(  ofVec2f mouse );
    void mouseReleased( ofVec2f mouse );
    
    void toggleTestPattern();
    void resetKeystone( );
    
    void saveKeystone();
    void loadKeystone();
    ofxIlda::Frame applyHomography(ofxIlda::Frame frame);
    
    LaserEffecType mEffectType;
    
    void gaussian_elimination(float *input, int n);
    
    LaserEffect * getCurrEffect();
    
private:
    void findHomography(ofPoint src[4], ofPoint dst[4], float homography[16]);
    void checkWipeList(  float timelinePos );
    void checkFrameList( float timelinePos );
    void checkNodeList(  float timelinePos );
    
    void clearForTimelineEffects(float timelinePos);
    
    vector <Wipe>     mWipeList;
    vector <Frame>    mFrameList;
    vector <NodeJoin> mJoinList;
    
    LaserEffect *mEffect;
    bool mShowTestPattern;
    ofPoint mCorners[4];
    int mSelectedCorner;
    bool mBlank;
    
    ofxIlda::Frame mTestPattern;
    ofxIlda::Frame mBlankFrame;
    
    float         lastCheckLaserTime;
    ofxEtherdream mEtherDream;
    
    ofRectangle mBoundingRect;
    ofxIlda::Frame mDrawFrame;
};

#endif /* LaserManager_hpp */

