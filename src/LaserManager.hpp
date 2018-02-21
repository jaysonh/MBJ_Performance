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
#include "Grid.h"
#include "GridVanishing.h"
#include "ConnectedGraph.h"
#include "VoiceWave.hpp"
#include "GreenScanLine.hpp"
#include "laserGui.hpp"
#include "LoadingCircle.h"
#include "MicroWaveTime.h"
#include "VoiceWaveTime.h"
#include "ScanLineTime.h"
#include "GlitchEffect.h"

#define ETHER_DREAM_PPS  40000

#define CHECK_TIME 10.0

enum LaserEffecType { NONE, VOICE_SKIN, VOICE_GREENBLUE, AUDIOFILE1, WIPE, FRAME, NODEJOIN, VOICEWAVE_YELLOW, VOICEWAVE_BLUE, BLUE_SCAN_LINE, YELLOW_SCAN_LINE, LOADING_CIRCLE };

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
    void sendAudio(float *input, int bufferSize, float microphoneDamp, float microphoneMult, float timelinePos);
private:
    void findHomography(ofPoint src[4], ofPoint dst[4], float homography[16]);
    void checkWipeList(  float timelinePos );
    void checkFrameList( float timelinePos );
    void checkNodeList(  float timelinePos );
    void checkGridList(  float timelinePos );
    void checkConnGraphList( float timelinePos);
    void checkLaserGuiList( float timelinePos);
    void checkLoadingCirclesList(float timelinePos);
    void checkGridVanishList(  float timelinePos );
    void checkMicroWaveList( float timelinePos);
    void checkVoiceWaveList( float timelinePos);
    void checkScanLineList(float timelinePos);
    void checkGlitchList(float timelinePos);
    
    void clearForTimelineEffects(float timelinePos);
    
    vector <Wipe>     mWipeList;
    vector <Frame>    mFrameList;
    vector <NodeJoin> mJoinList;
    vector <Grid> mGridList;
    vector <GridVanishing> mGridVanishList;
    vector <ConnectedGraph> mConnGraphList;
    vector <LaserGui>  mLaserGuiList;
    vector <LoadingCircle> mLoadingCirclesList;
    vector <MicroWaveTime> mMicroWaveList;
    vector <VoiceWaveTime> mVoiceWaveList;
    vector <ScanLineTime>  mScanLineList;
    vector <GlitchEffect>  mGlitchList;
    
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
    
    
    AudioFileEffect * audioFileEffect1;
};

#endif /* LaserManager_hpp */

