#pragma once

#include "ofMain.h"
#include "LaserManager.hpp"
#include "Timeline.hpp"
#include "ofxGui.h"
#include "OscManager.hpp"
#include "DEFINITIONS.h"

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
        void blankLaserBtnPressed();
        void laserMicrophoneSkinBtnPressed();
        void laserMicrophoneBlueGreenBtnPressed();
        void laserVoice1BtnPressed();
        void testPatternBtnPressed();
        void noEffectBtnPressed();
        void voiceWaveYellowBtnPressed();
        void voiceWaveBlueBtnPressed();
        void blueScanLineBtnPressed();
        void yellowScanLineBtnPressed();
        void startPerformanceBtnPressed();
    
        void loadKeystone();
        void saveKeystone();
        void resetKeystone();
    
        void audioIn(float * input, int bufferSize, int nChannels);
    
        ofTrueTypeFont font;
        LaserManager laserManager;
		
        ofxIlda::Frame warpedFrame;
        Timeline timeline;
    
        ofxPanel       gui;
        ofxPanel       guiKeystone;
    
        ofxFloatSlider microphoneDamp;
        ofxFloatSlider microphoneMult;
        ofxFloatSlider audioFileDamp;
        ofxFloatSlider audioFileMult;
    
        ofxButton      laserResetBtn;
        ofxButton      blankLaserBtn;
        ofxButton      laserMicrophoneSkinBtn;
        ofxButton      laserMicrophoneBlueGreenBtn;
        ofxButton      laserVoice1Btn;
        ofxButton      testPatternBtn;
        ofxButton      noEffectBtn;
        ofxButton      voiceWaveYellowEffectBtn;
        ofxButton      voiceWaveBlueEffectBtn;
        ofxButton      blueScanEffectBtn;
        ofxButton      yellowScanEffectBtn;
        ofxButton      startPerformanceBtn;
    
        ofxButton      loadKeystoneBtn;
        ofxButton      saveKeystoneBtn;
        ofxButton      resetKeystoneBtn;
    
        ofSoundStream soundStream;
    
        OscManager      oscManager;
};
