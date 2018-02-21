#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    font.load("verdana.ttf", 12);
    
    // Load gui
    gui.setup();
    gui.add(microphoneDamp.setup("microphoneDamp", 0.95, 0, 1));
    gui.add(microphoneMult.setup("microphoneMult", 19.0, 0, 50.0));
    gui.add(audioFileDamp.setup("audioFileDamp",   0.95, 0, 1));
    gui.add(audioFileMult.setup("audioFileMult",   19.0, 0, 50.0));
    
    
    testPatternBtn.addListener(this, &ofApp::testPatternBtnPressed);
    laserResetBtn.addListener(this, &ofApp::laserResetBtnPressed);
    blankLaserBtn.addListener(this, &ofApp::blankLaserBtnPressed);
    noEffectBtn.addListener(this, &ofApp::noEffectBtnPressed);
    laserMicrophoneSkinBtn.addListener(this, &ofApp::laserMicrophoneSkinBtnPressed);
    laserMicrophoneBlueGreenBtn.addListener(this, &ofApp::laserMicrophoneBlueGreenBtnPressed);
    laserVoice1Btn.addListener(this, &ofApp::laserVoice1BtnPressed);
    voiceWaveYellowEffectBtn.addListener(this,&ofApp::voiceWaveYellowBtnPressed);
    voiceWaveBlueEffectBtn.addListener(this,&ofApp::voiceWaveBlueBtnPressed);
    yellowScanEffectBtn.addListener(this,&ofApp::yellowScanLineBtnPressed);
    blueScanEffectBtn.addListener(this,&ofApp::blueScanLineBtnPressed);
    
    gui.add(testPatternBtn.setup("test pattern"));
    gui.add(laserResetBtn.setup("reset laser"));
    //gui.add(blankLaserBtn.setup("blank laser"));
    //gui.add(laserMicrophoneSkinBtn.setup("laser microphone skin"));
    //gui.add(laserMicrophoneBlueGreenBtn.setup("laser microphone bluegreen"));
    //gui.add(laserVoice1Btn.setup("laser voice 1"));
    //gui.add(voiceWaveYellowEffectBtn.setup("voicewaveYellow"));
    //gui.add(voiceWaveBlueEffectBtn.setup("voicewaveBlue"));
    //gui.add(blueScanEffectBtn.setup("blue scan line"));
    //gui.add(yellowScanEffectBtn.setup("yellow scan line"));
    gui.add(noEffectBtn.setup("no effect"));
    
    gui.setPosition(10,10);
    
    guiKeystone.setup();
    guiKeystone.add(loadKeystoneBtn.setup("load keystone"));
    guiKeystone.add(saveKeystoneBtn.setup("save keystone"));
    guiKeystone.add(resetKeystoneBtn.setup("reset keystone"));
    guiKeystone.setPosition(410,10);
    
    loadKeystoneBtn.addListener(this,  &ofApp::loadKeystone);
    saveKeystoneBtn.addListener(this,  &ofApp::saveKeystone);
    resetKeystoneBtn.addListener(this, &ofApp::resetKeystone);
    
    //if you want to set the device id to be different than the default
    //soundStream.setDeviceID(2);     //note some devices are input only and some are output only
    
    //beats.load("wetware_test.mp3");
    //beats.play();
    
    float sampleRate = 22050;
    int bufferSize = 256;
    
    ofSoundStreamSetup(1, 1, this, sampleRate, bufferSize, 4);
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    ofSetFrameRate(60);
    oscManager.init();
    
    laserManager.init();
}

void ofApp::resetKeystone()
{
    laserManager.resetKeystone();
}

void ofApp::saveKeystone()
{
    laserManager.saveKeystone();
}

void ofApp::loadKeystone()
{
    laserManager.loadKeystone();
}

void ofApp::noEffectBtnPressed()
{
    laserManager.setEffect( NONE );
}

void ofApp::laserResetBtnPressed()
{
    laserManager.reset();
    
}

void ofApp::voiceWaveYellowBtnPressed()
{
    laserManager.setEffect( VOICEWAVE_YELLOW );
}
void ofApp::voiceWaveBlueBtnPressed()
{
    laserManager.setEffect( VOICEWAVE_BLUE );
}

void ofApp::blankLaserBtnPressed()
{
    
    laserManager.blank();
    
}

void ofApp::laserMicrophoneBlueGreenBtnPressed()
{
    laserManager.setEffect( VOICE_GREENBLUE );
}
void ofApp::laserMicrophoneSkinBtnPressed()
{
    laserManager.setEffect( VOICE_SKIN );
}

void ofApp::laserVoice1BtnPressed()
{
    laserManager.setEffect( AUDIOFILE1 );
}

void ofApp::blueScanLineBtnPressed()
{
    laserManager.setEffect( BLUE_SCAN_LINE );
}
void ofApp::yellowScanLineBtnPressed()
{
    laserManager.setEffect( YELLOW_SCAN_LINE );
}

void ofApp::testPatternBtnPressed()
{
    laserManager.toggleTestPattern();
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle( ofToString(ofGetFrameRate()) );
    oscManager.update();
    timeline.update( oscManager.getTimelinePos() );
    
    laserManager.update( oscManager.getTimelinePos(), audioFileDamp, audioFileMult );
    
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    if(w != WINDOW_WIDTH || h != WINDOW_HEIGHT) ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(125), ofColor(60));
    laserManager.draw( &font );
    timeline.draw( &font );
    
    gui.draw();
    guiKeystone.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    laserManager.mouseDragged(ofVec2f(x,y) );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    laserManager.mousePressed(ofVec2f(x,y) );
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    laserManager.mousePressed( ofVec2f(x,y) );
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
    laserManager.sendAudio(input,bufferSize, microphoneDamp, microphoneMult, oscManager.getTimelinePos());
    LaserEffect * laserEffect = laserManager.getCurrEffect();
    laserEffect->sendAudio(input,bufferSize, microphoneDamp, microphoneMult);
}
