#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    syphonManager.init();
    font.load("verdana.ttf", 12);
    fontBig.load("verdana.ttf", 64);
    
    // Load gui
    gui.setup();
    gui.add(microphoneDamp.setup("microphoneDamp", 0.95, 0, 1));
    gui.add(microphoneMult.setup("microphoneMult", 5.0, 0, 20.0));
   
    testPatternLeftBtn.addListener(  &dualLaserManager,
                                     &DualLaserManager::testPatternLeftToggle);
    laserResetLeftBtn.addListener(   &dualLaserManager,
                                     &DualLaserManager::resetLeft);
    testPatternRightBtn.addListener( &dualLaserManager,
                                     &DualLaserManager::testPatternRightToggle);
    laserResetRightBtn.addListener(  &dualLaserManager,
                                     &DualLaserManager::resetRight);
    
    
    blankLaserBtn.addListener(this, &ofApp::blankLaserBtnPressed);
    startPerformanceBtn.addListener(&oscManager, &OscManager::startPerformance);
    startFromSelectedBtn.addListener(&oscManager,&OscManager::startPerformanceFrom);
    revertStartBtn.addListener(&oscManager, &OscManager::revertSavedStartTime);
    clearOffsetBtn.addListener(&timeline, &Timeline::clearOffset);
    
    gui.add(testPatternLeftBtn.setup("Left test pattern"));
    gui.add(testPatternRightBtn.setup("Right test pattern"));
    
    gui.add(laserResetLeftBtn.setup("Left reset laser"));
    gui.add(laserResetRightBtn.setup("Right reset laser"));
    
    gui.add(startPerformanceBtn.setup("start performance"));
    gui.add(noEffectBtn.setup("blank"));
    //gui.add(timeSourceAbleton.setup("TimeSourceAbleton"));
    //gui.add(timeSourceStart.setup("TimeSourceStart"));
    //gui.add(startFromSelectedBtn.setup("TimeStartSelection"));
    //gui.add(revertStartBtn.setup("Revert to prev start"));
    //gui.add(skipForwardBtn.setup("Skip Forward"));
    //gui.add(skipBackBtn.setup("Skip Back (if G comp pauses)"));
    //gui.add(startTimeMinSlider.setup("startMin",0,0,31));
    //gui.add(startTimeSecSlider.setup("startSec",0,0,59));
    //gui.add(clearOffsetBtn.setup("clear"));
    
    gui.setPosition(10,10);
    
    guiKeystone.setup();
    guiKeystone.add(loadKeystoneBtn.setup("load keystone"));
    guiKeystone.add(saveKeystoneBtn.setup("save keystone"));
    guiKeystone.add(resetKeystoneBtn.setup("reset keystone"));
    guiKeystone.setPosition(410,10);
    
    loadKeystoneBtn.addListener(this,  &ofApp::loadKeystone);
    saveKeystoneBtn.addListener(this,  &ofApp::saveKeystone);
    resetKeystoneBtn.addListener(this, &ofApp::resetKeystone);
    noEffectBtn.addListener(this,      &ofApp::blankLaserBtnPressed);
    
    skipForwardBtn.addListener( &oscManager, &OscManager::skipForward);
    skipBackBtn.addListener(    &oscManager, &OscManager::skipBackward);
    
    timeSourceAbleton.addListener(this, &ofApp::timeSourceAbletonPressed);
    timeSourceStart.addListener(this,   &ofApp::timeSourceStartPressed);
    
    float sampleRate = 22050;
    int bufferSize = 256;
    
    ofSoundStreamSetup(1, 1, this, sampleRate, bufferSize, 4);
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    ofSetFrameRate(60);
    oscManager.init();
    
    dualLaserManager.init();
    //laserManager.init();
    
    soundStream.setup(this, 0, 2, 44100, 256, 4);
}

void ofApp::timeSourceSelectionPressed()
{
    
    oscManager.setUseAbletonTime(2);
}

void ofApp::timeSourceAbletonPressed()
{
    oscManager.setUseAbletonTime(1);
}

void ofApp::timeSourceStartPressed()
{
    oscManager.setUseAbletonTime(0);
}

void ofApp::resetKeystone()
{
    
    //laserManager.resetKeystone();
}

void ofApp::saveKeystone()
{
    //laserManager.saveKeystone();
}

void ofApp::loadKeystone()
{
    //laserManager.loadKeystone();
}


void ofApp::laserResetBtnPressed()
{
    //laserManager.reset();
    
}

void ofApp::blankLaserBtnPressed()
{
    
    //laserManager.blank();
    
}

void ofApp::testPatternBtnPressed()
{
   // laserManager.toggleTestPattern();
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle( ofToString(ofGetFrameRate()) );
    
    oscManager.update();
    timeline.update( oscManager.getTimelinePos(),
                     oscManager.getAbletonPos(),
                     oscManager.getTime(),
                     oscManager.getTotalOffset()
                    );
    dualLaserManager.update(oscManager.getTime(), curVol);
    //laserManager.update( oscManager.getTime());
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    if(w != WINDOW_WIDTH || h != WINDOW_HEIGHT) ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    oscManager.setStartTime(startTimeMinSlider, startTimeSecSlider);
}

//--------------------------------------------------------------
void ofApp::draw(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /*ofPushMatrix();
    syphonManager.update();
    syphonManager.draw();
    ofPopMatrix();
    */
    //laserManager.draw( &font, oscManager.getTime() );
    dualLaserManager.draw( );
    timeline.draw( &font, &fontBig );
    
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
    //laserManager.mouseDragged(ofVec2f(x,y) );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //laserManager.mousePressed(ofVec2f(x,y) );
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //laserManager.mousePressed( ofVec2f(x,y) );
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
    int numCounted = 0;
    curVol=0;
    
    for (int i = 0; i < bufferSize; i++)
    {
        curVol += abs(input[i*2]*0.5); //left
        numCounted++;
    }
    
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    //smoothedVol *= 0.93;
    //smoothedVol += 0.07 * curVol;
    
    
    
}
