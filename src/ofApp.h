#pragma once

#include "ofMain.h"
#include "LaserManager.hpp"
#include "Timeline.hpp"
#include "ofxGui.h"
#include "OscManager.hpp"
#include "DEFINITIONS.h"
#include "SyphonManager.h"
#include "DualLaserManager.h"
#include "DMXHandler.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 640


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void laserResetBtnPressed();
    
        void testPatternBtnPressed();
        void startPerformanceBtnPressed();
        void loadKeystone();
        void saveKeystone();
        void resetKeystone();
        void timeSourceAbletonPressed();
        void timeSourceStartPressed();
        void timeSourceSelectionPressed();
    
        void audioIn(float * input, int bufferSize, int nChannels);
    
        SyphonManager syphonManager;
    
        ofTrueTypeFont font;
        ofTrueTypeFont fontBig;
        //LaserManager laserManager;
        DualLaserManager dualLaserManager;
    
        ofxIlda::Frame warpedFrame;
        Timeline timeline;
    
        ofxPanel       gui;
        ofxPanel       guiKeystone;
    
        ofxFloatSlider microphoneDamp;
        ofxFloatSlider microphoneMult;
    
        ofxButton      testPatternCentreBtn;
        ofxButton      laserResetCentreBtn;
        ofxButton      laserResetLeftBtn;
        ofxButton      testPatternLeftBtn;
        ofxButton      laserResetRightBtn;
        ofxButton      testPatternRightBtn;
        ofxButton      blankLaserBtn;
        ofxButton      noEffectBtn;
        ofxButton      startPerformanceBtn;
        ofxButton      timeSourceAbleton;
        ofxButton      timeSourceStart;
        ofxButton      startFromSelectedBtn;
        ofxButton      loadKeystoneBtn;
        ofxButton      saveKeystoneBtn;
        ofxButton      resetKeystoneBtn;
        ofxButton      revertStartBtn;
        ofxButton      clearOffsetBtn;
    
        ofxButton      skipBackBtn;
        ofxButton      skipForwardBtn;
    
    
        ofxIntSlider  startTimeMinSlider;
        ofxIntSlider  startTimeSecSlider;
        ofSoundStream soundStream;
    
        OscManager      oscManager;
        DMXHandler      dmxHandler;
        shared_ptr<vector <float>>audioVals;
        float curVol = 0.0;
};
