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
#include "EffectTime.h"

#define ETHER_DREAM_PPS  40000
#define STARTUP_DELAY  3.0
#define CHECK_TIME 10000.0//10.0

enum LaserEffecType { NONE, VOICE_SKIN, VOICE_GREENBLUE, AUDIOFILE1, WIPE, FRAME, NODEJOIN, VOICEWAVE_YELLOW, VOICEWAVE_BLUE, BLUE_SCAN_LINE, YELLOW_SCAN_LINE, LOADING_CIRCLE };

#define KEYSTONE_FILE "keystone.txt"

bool compareEffectTime(std::pair<string,EffectTime> t1, std::pair<string,EffectTime> t2);

class LaserManager
{
public:
    
    LaserManager();
    
    void init();
    
    void update( float timelinePos );
    
    ofxIlda::Frame sendFrames(ofxIlda::Frame frame);
    
    void draw( ofTrueTypeFont * font,float timelinePos );
    
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
    string getTimeString( float time );
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
    void checkCircleGuiList(float timelinePos);
    void checkLoadingBarList(float timelinePos);
    void checkLiquidVoiceList(float timelinePos);
    void checkLineHighlightList(float timelinePos);
    void checkGui2List(float timelinePos);
    void checkTerrainList(float timelinePos);
    void checkMorphShapeList(float timelinePos);
    void checkGridHorVerShapeList(float timelinePos);
    void checkShapeExplorerList(float timelinePos);
    void checkLoadingLinesList(float timelinePos);
    void checkSpikeList(float timelinePos);
    void checkCursorEffectList(float timelinePos);
    
    void clearForTimelineEffects(float timelinePos);
    
    float toTotalSeconds(int min, int sec);
    
    vector <LaserEffect*> mEffectList;
    
    vector <VoiceSpikes>     mVoiceSpikesList;
    vector <LoadingLines>    mLoadingLinesList;
    vector <GridHorAndVer>   mGridHorVerList;
    vector <MorphShape>      mMorphShapeList;
    vector <LaserGuiCircle>  mCircleGuiList;
    vector <Wipe>            mWipeList;
    vector <Frame>           mFrameList;
    vector <NodeJoin>        mJoinList;
    vector <Grid>            mGridList;
    vector <GridVanishing>   mGridVanishList;
    vector <ConnectedGraph>  mConnGraphList;
    vector <LaserGui>        mLaserGuiList;
    vector <LoadingCircle>   mLoadingCirclesList;
    vector <MicroWaveTime>   mMicroWaveList;
    vector <VoiceWaveTime>   mVoiceWaveList;
    vector <ScanLineTime>    mScanLineList;
    vector <GlitchEffect>    mGlitchList;
    vector <LoadingBar>      mLoadingBarList;
    vector <LiquidVoice>     mLiquidVoiceList;
    vector <LineHighlight>   mLineHighlightList;
    vector <LaserGui2>       mGui2List;
    vector <TerrainContours> mTerrainList;
    vector <ShapeExplorer>   mShapeExplorerList;
    vector <CursorEffect>    mCursorEffectList;
   
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
    
    bool flipY = true;
    
    AudioFileEffect * audioFileEffect1;
    
    
    vector<std::pair<string,EffectTime>> effectDisplayList;
};

#endif /* LaserManager_hpp */

