//
//  DualLaserManager.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/05/2019.
//

#include "DualLaserManager.h"


void DualLaserManager::init()
{
    if(!font.load("fonts/Helvetica.ttf",24))
    {
        cout << "Couldn't load font"<<endl;
    }
    
    for(int i = 0; i < NUM_LASERS;i++)
    {
        if(laser[i].setup(true, i))
        {
            laser[i].setPPS( ETHER_DREAM_PPS );
            cout << ofToString(i) + " Init laser " << laser[i].getUniqueID() <<endl;
        }else
        {
            cout << "Could not connect to laser: " << ofToString(i)<<endl;
        }
    }
   
    
    if(laser[0].getUniqueID() == 14433133)
        leftIndx  = 0;
    if(laser[0].getUniqueID() == 14449524)
        rightIndx = 0;
    if(laser[0].getUniqueID() == 14418711)
        centreIndx = 0;
    
    if(laser[1].getUniqueID() == 14433133)
        leftIndx  = 1;
    if(laser[1].getUniqueID() == 14449524)
        rightIndx  = 1;
    if(laser[1].getUniqueID() == 14418711)
        centreIndx = 1;
    
    if(laser[2].getUniqueID() == 14433133)
        leftIndx  = 2;
    if(laser[2].getUniqueID() == 14449524)
        rightIndx  = 2;
    if(laser[2].getUniqueID() == 14418711)
        centreIndx = 2;
    
    
    
    setupTimeline();
    loadTestPattern( &testPatternFrameLeft,  "leftKeystone.xml"  );
    loadTestPattern( &testPatternFrameRight, "rightKeystone.xml" );
    
    timelineDrawSz  = ofVec2f( ofGetWidth()/2, (ofGetHeight()/6));
    timelineDrawPos = ofVec2f(ofGetWidth()/2,
                              ofGetHeight()/2 + (ofGetHeight()/6));
    
}

void DualLaserManager::loadTestPattern( ofxIlda::Frame * frame, string keystoneFile)
{}

void DualLaserManager::resetKeystone( ofxIlda::Frame * frame )
{
    frame->clear();
    frame->addPoly();
    frame->getLastPoly().lineTo(0.01,0.01);
    frame->getLastPoly().lineTo(0.99,0.01);
    
    frame->addPoly();
    frame->getLastPoly().lineTo(0.99,0.01);
    frame->getLastPoly().lineTo(0.99,0.99);
    
    frame->addPoly();
    frame->getLastPoly().lineTo(0.99,0.99);
    frame->getLastPoly().lineTo(0.01,0.99);
    
    frame->addPoly();
    frame->getLastPoly().lineTo(0.01,0.99);
    frame->getLastPoly().lineTo(0.01,0.01);
    
    frame->update();
}
void DualLaserManager::loadKeystoneLeft(  )
{
    keystoneLeft.loadJSON( "keystoneLeft.json" );
}

void DualLaserManager::loadKeystoneRight(  )
{
    keystoneRight.loadJSON( "keystoneRight.json" );
    
}

void DualLaserManager::setupTimeline()
{
    effectList.push_back( make_shared<DualLaserTunnel>(EffectTime(0, 600.0)));
}

void DualLaserManager::initLaser(int laserIndx)
{
    
    laser[laserIndx].stop();
    laser[laserIndx].kill();
    
    cout << "CONNECTING TO ETHERDREAM: " << ofToString(laser[laserIndx].getUniqueID()) << endl;
    
    laser[laserIndx].setup(true, laserIndx);
    laser[laserIndx].setPPS( ETHER_DREAM_PPS );
    
}

void DualLaserManager::draw()
{
    ofSetColor(255);
    ofDrawBitmapString("Laser Left:   " + ofToString(leftIndx) + " " + ofToString(laser[leftIndx].getUniqueID()) + " "                  +laser[leftIndx].getStateLabel(), 20,240);
    
    ofDrawBitmapString("Laser Right:  " + ofToString(rightIndx) + " " + ofToString(laser[rightIndx].getUniqueID()) + " "                  +laser[rightIndx].getStateLabel(), 20,260);
    
    ofDrawBitmapString("Laser Centre: " + ofToString(centreIndx) + " " + ofToString(laser[centreIndx].getUniqueID()) + " "                  +laser[centreIndx].getStateLabel(), 20,280);
    float w = (ofGetWidth()/2)/3;
    
    // draw empty frame
    ofPushStyle();
    ofSetColor(125);
    ofDrawRectangle(ofGetWidth()/2,10, w*3,w);
    ofNoFill();
    ofSetColor(255);
    ofDrawRectangle(ofGetWidth()/2,10, w,w);
    ofDrawRectangle(ofGetWidth()/2+w,10, w,w);
    ofDrawRectangle(ofGetWidth()/2+w*2,10, w,w);
    ofDrawBitmapString("LEFT",   ofGetWidth()/2+10,     30 );
    ofDrawBitmapString("RIGHT",  ofGetWidth()/2+w+10,   30 );
    ofDrawBitmapString("CENTRE", ofGetWidth()/2+w*2+10, 30 );
    ofPopStyle();
    ofSetColor(255);
    frameLeft.draw(ofGetWidth()/2, 10,w,w);
    frameRight.draw(ofGetWidth()/2+w, 10,w,w);
    frameCentre.draw(ofGetWidth()/2+w*2, 10,w,w);
    
    if(blank)
    {
        ofSetColor(ofColor::red);
        font.drawString("BLANKED", ofGetWidth()/2-100, ofGetHeight()/2 - 10);
    }
    
    drawTimeline();
}

void DualLaserManager::drawTimeline()
{
    // Now draw timeline (bottom third)
    ofPushStyle();
    ofNoFill();
    ofSetColor(ofColor::white);
    ofDrawBitmapString("Laser Effects", timelineDrawPos.x, timelineDrawPos.y);
    ofDrawRectangle( timelineDrawPos.x, timelineDrawPos.y, timelineDrawSz.x,timelineDrawSz.y);
    ofPushMatrix();
    
    float currOff = ofMap( lastSavedTime,
                          0,
                          PERFORMANCE_LENGTH,
                          timelineDrawPos.x,
                          timelineDrawPos.x+ timelineDrawSz.x );
    ofFill();
    ofSetColor(0,255,0);
    ofDrawLine( currOff, timelineDrawPos.y,
               currOff, timelineDrawPos.y+timelineDrawSz.y);
    
    for( auto effect : effectList )
    {
        float offset = ofMap( effect->getTime()->start,
                             0,
                             PERFORMANCE_LENGTH,
                             timelineDrawPos.x,
                             timelineDrawPos.x+ timelineDrawSz.x );
        float timeLength = ( effect->getTime()->getLength()/PERFORMANCE_LENGTH ) * timelineDrawSz.x;
        ofRectangle bar = ofRectangle(offset,timelineDrawPos.y,
                                      timeLength, timelineDrawSz.y);
        ofSetColor(effect->getColor());
        ofDrawRectangle(bar);
        
        if( bar.inside(ofGetMouseX(),ofGetMouseY()))
        {
            ofSetColor(ofColor::white);
            ofDrawBitmapString( effect->getName(), bar.x, bar.y+10);
        }
    }
    ofPopMatrix();
    ofPopStyle();
}
void DualLaserManager::resetLeft()
{
    initLaser( leftIndx  );
}
void DualLaserManager::resetRight()
{
    initLaser( rightIndx  );
    
}

void DualLaserManager::resetCentre()
{
    initLaser( centreIndx  );
    
}
void DualLaserManager::testPatternLeftToggle()
{
    testPatternLeft = !testPatternLeft;
}
void DualLaserManager::testPatternRightToggle()
{
    testPatternRight = !testPatternRight;
}
void DualLaserManager::testPatternCentreToggle()
{
    testPatternCentre = !testPatternCentre;
}


void DualLaserManager::toggleBlankPressed()
{
    blank = !blank;
}

void DualLaserManager::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    lastSavedTime = timelinePos;
    
    for( auto effect : effectList )
    {
        if( effect->isDisplay(timelinePos) &&
            ofGetElapsedTimef()> 5.0 &&
            !blank
          )
        {
            effect->update(timelinePos,audioLevel, audioVals);
            vector <LaserLine> rightLines   = effect->getFrameLeft();
            vector <LaserLine> leftLines    = effect->getFrameRight();
            vector <LaserLine> centreLines  = effect->getFrameCentre();
            
            frameLeft.clear();
            frameRight.clear();
            frameCentre.clear();
            
            for( auto line : leftLines )
            {
                if(!line.continous)
                {
                    frameLeft.addPoly();
                    frameLeft.getLastPoly().color = line.col;
                    frameLeft.getLastPoly().lineTo( line.begin.x, line.begin.y);
                    frameLeft.getLastPoly().lineTo( line.end.x,   line.end.y);
                }else
                    frameLeft.getLastPoly().lineTo( line.end.x,   line.end.y);
            }
            
            for( auto line : rightLines )
            {
                if(!line.continous)
                {
                    frameRight.addPoly();
                    frameRight.getLastPoly().color = line.col;
                    frameRight.getLastPoly().lineTo( line.begin.x, line.begin.y);
                    frameRight.getLastPoly().lineTo( line.end.x,   line.end.y);
                }else
                    frameRight.getLastPoly().lineTo( line.end.x,   line.end.y);
            }
            
            for( auto line : centreLines )
            {
                if(!line.continous)
                {
                    frameCentre.addPoly();
                    frameCentre.getLastPoly().color = line.col;
                    frameCentre.getLastPoly().lineTo( line.begin.x, line.begin.y);
                    frameCentre.getLastPoly().lineTo( line.end.x,   line.end.y);
                }else
                    frameCentre.getLastPoly().lineTo( line.end.x,   line.end.y);
            }
            
            frameLeft.update();
            frameRight.update();
            frameCentre.update();
            
            if(leftIndx  > -1/* && !testPatternLeft*/)
            {
                laser[leftIndx ].setPoints(frameLeft);
                
            }
            if(rightIndx > -1/* && !testPatternRight*/) laser[rightIndx].setPoints(frameRight);
            
            if(centreIndx > -1/* && !testPatternRight*/) laser[centreIndx].setPoints(frameCentre);
        }
    }
    
    if(testPatternRight)
    {
        
    }
    if(testPatternLeft)
    {
        
    }
}
