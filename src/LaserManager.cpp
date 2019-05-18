//
//  LaserManager.cpp
//  StarOfBethlehem
//
//  Created by Jayson Haebich on 27/09/2016.
//
//

#include "LaserManager.hpp"


bool compareEffectTime(std::pair<string,EffectTime> t1, std::pair<string,EffectTime> t2)
{
    return (t1.second.start < t2.second.start);
}

LaserManager::LaserManager()
{
    
    mSelectedCorner = -1;
    
    lastCheckLaserTime=0;
    
    mCorners[0] = ofVec2f( 0.0, 0.0 );
    mCorners[1] = ofVec2f( 1.0, 0.0 );
    mCorners[2] = ofVec2f( 1.0, 1.0 );
    mCorners[3] = ofVec2f( 0.0, 1.0 );
    
    mTestPattern.clear();
    mTestPattern.addPoly();
    mTestPattern.getLastPoly().lineTo(0.01,0.01);//, ofFloatColor(1,1,1));
    mTestPattern.getLastPoly().lineTo(0.99,0.01);//, ofFloatColor(1,1,1));
    
    mTestPattern.addPoly();
    mTestPattern.getLastPoly().lineTo(0.99,0.01);//, ofFloatColor(1,1,1));
    mTestPattern.getLastPoly().lineTo(0.99,0.99);//, ofFloatColor(1,1,1));
    
    mTestPattern.addPoly();
    mTestPattern.getLastPoly().lineTo(0.99,0.99);//, ofFloatColor(1,1,1));
    mTestPattern.getLastPoly().lineTo(0.01,0.99);//, ofFloatColor(1,1,1));
    
    mTestPattern.addPoly();
    mTestPattern.getLastPoly().lineTo(0.01,0.99);//, ofFloatColor(1,1,1));
    mTestPattern.getLastPoly().lineTo(0.01,0.01);//, ofFloatColor(1,1,1));
    
    mTestPattern.update();
    
    mBlankFrame.clear();
    mBlankFrame.update();
    
    mShowTestPattern=false;
    
    loadKeystone();
    
    ////////////////////////////////////////////////////////////////////////////////////////
    // 2019 - transmediale
    ////////////////////////////////////////////////////////////////////////////////////////
    
    // Testing
    //mGridHorVerList.push_back( GridHorAndVer( toTotalSeconds(0,0),toTotalSeconds(10,14), FADE_TOP_TO_MIDDLE ) );
    //mMorphShapeList.push_back( MorphShape(toTotalSeconds(0,0),toTotalSeconds(10,14),PLAIN));
    //mShapeExplorerList.push_back( ShapeExplorer(toTotalSeconds(0,0),toTotalSeconds(10,14),PLAIN));
    //mGui2List.push_back( LaserGui2(toTotalSeconds(0,0),toTotalSeconds(10,14),PLAIN));
    //mLaserGuiList.push_back( LaserGui(0,162.0) );
    //mLiquidVoiceList.push_back( LiquidVoice(0,1000,PLAIN));
    //mCircleGuiList.push_back( LaserGuiCircle( toTotalSeconds(0, 03),toTotalSeconds(10, 14), PLAIN ) );
    //mLoadingCirclesList.push_back(LoadingCircle(toTotalSeconds(0, 0),toTotalSeconds(10, 14), PLAIN ) );
    //mTerrainList.push_back(TerrainContours(toTotalSeconds(0, 0),toTotalSeconds(10, 15), GREEN_BLUE_HOR));
    //mGui2List.push_back( LaserGui2(toTotalSeconds(0,0),toTotalSeconds(0,20),PLAIN));
    //mMicroWaveList.push_back( MicroWaveTime(toTotalSeconds(0, 0),toTotalSeconds(2, 56), GREEN_BLUE_HOR));
    //mTerrainList.push_back(    TerrainContours( toTotalSeconds(15, 53), toTotalSeconds(16, 26), GREEN_BLUE_HOR));
    //mMorphShapeList.push_back( MorphShape(      toTotalSeconds(22, 00), toTotalSeconds(23, 0),  GREEN_BLUE_HOR));
    
    // Intro
    // micro voice wave turning on off between sections in the video
    // No laser
    
    // 5_Intelligent personal assistant
    // micro voice wave turning on/off between sections
    mMicroWaveList.push_back( MicroWaveTime(toTotalSeconds(2, 27),toTotalSeconds(3, 2),  WHITE_PINK ,  0.5));
    mMicroWaveList.push_back( MicroWaveTime(toTotalSeconds(3, 9), toTotalSeconds(3, 42), RED_PINK , 0.5)); // too much yellow
   
    // 4_Self hood
    mLaserGuiList.push_back(LaserGui(toTotalSeconds(4, 6),toTotalSeconds(4,49),PLAIN)); // white
    mLaserGuiList.push_back(LaserGui(toTotalSeconds(4, 59),toTotalSeconds(5,38),PLAIN)); //white
    mVoiceWaveList.push_back( VoiceWaveTime(toTotalSeconds(6, 9), toTotalSeconds(6, 38), WHITE_YELLOW)); // whiteandyellow
    mLiquidVoiceList.push_back( LiquidVoice(toTotalSeconds(7,55),
                                            toTotalSeconds(8,36),
                                            PLAIN,
                                            ofFloatColor(0.3,0.5,1),
                                            ofFloatColor(0.3,0.5,1))); //cyan
    mVoiceWaveList.push_back(   VoiceWaveTime(toTotalSeconds(8, 45), toTotalSeconds(8, 59), WHITE_YELLOW)); // whiteandyellow
    mVoiceSpikesList.push_back( VoiceSpikes(toTotalSeconds(9, 23),toTotalSeconds(10,14),    PLAIN)); 
    
    
    // 3_Multitude
                                  
    // 2_SELF REGULATION
    mLoadingCirclesList.push_back(LoadingCircle(toTotalSeconds(15, 16),toTotalSeconds(15, 38),  PLAIN ) ); 
    mVoiceWaveList.push_back( VoiceWaveTime(toTotalSeconds(15, 44), toTotalSeconds(15, 56), WHITE_YELLOW)); // whiteandyellow
    
    mGridHorVerList.push_back( GridHorAndVer(   toTotalSeconds(16, 27), toTotalSeconds(17, 29), FADE_TOP_TO_MIDDLE ) );
    mMicroWaveList.push_back(  MicroWaveTime(   toTotalSeconds(17, 50), toTotalSeconds(18, 16), YELLOW_GREEN, 0.4));
    mMicroWaveList.push_back(  MicroWaveTime(   toTotalSeconds(18, 22), toTotalSeconds(18, 47), GREEN_BLUE_HOR, 0.75)); // on lower part of screen
    
    // 1
    mVoiceWaveList.push_back( VoiceWaveTime(   toTotalSeconds(19, 44), toTotalSeconds(20, 31), YELLOW_BLUE));
    mVoiceWaveList.push_back( VoiceWaveTime(   toTotalSeconds(21, 0), toTotalSeconds(21, 17),  YELLOW_BLUE));
    mScanLineList.push_back( ScanLineTime(toTotalSeconds(23,28), toTotalSeconds(23,56),        WHITE_YELLOW2));  // white/yellow
    mGlitchList.push_back( GlitchEffect(toTotalSeconds(24, 22), toTotalSeconds(25, 10), 0.01,0.02,PLAIN));
    
    // 0 Self care
    // cursor effect
    mCursorEffectList.push_back( CursorEffect(toTotalSeconds(25,18),toTotalSeconds(25,55),5.0, PLAIN)); 
    
    // end section
    mLiquidVoiceList.push_back( LiquidVoice( toTotalSeconds(27,37),
                                             toTotalSeconds(29,5),
                                             GREEN_BLUE_HOR,
                                             ofFloatColor(0,1,0),
                                             ofFloatColor(0,1,1)
                                            )); //one line green, the other blue
    
    ////////////////////////////////////////////////////////////////////////////////////////
    // 2018
    ////////////////////////////////////////////////////////////////////////////////////////
    /*
    // 2_Fascia
    mMicroWaveList.push_back( MicroWaveTime(85.00, 111.00,PLAIN));//, RED_WHITE_VER));
    
    
    // 3_Selfhood
    mLaserGuiList.push_back( LaserGui(124.0,162.0) );
    mLaserGuiList.push_back( LaserGui(173.0,209.0) );
    mLaserGuiList.push_back( LaserGui(217.0,241.0) );
    
    mVoiceWaveList.push_back( VoiceWaveTime(243,272,PLAIN));//, YELLOW_BLUE));
    
    mVoiceWaveList.push_back( VoiceWaveTime(286,312,PLAIN));//, BLUE_VERTICAL));
    //mVoiceWaveList.push_back( VoiceWaveTime(286,312, YELLOW_BLUE));
    
    // 4_AUTOREGULATION
    mGridVanishList.push_back (GridVanishing(317.0, 336.0) );
    
    mVoiceWaveList.push_back( VoiceWaveTime(339,376,PLAIN));//, YELLOW_BLUE));
    
    mGridVanishList.push_back (GridVanishing(385.0, 420) );
    
    mVoiceWaveList.push_back( VoiceWaveTime(434,458,PLAIN));//, YELLOW_BLUE));
 
    // 5_QuantifiedSelf
    mVoiceWaveList.push_back( VoiceWaveTime(496,446,PLAIN));//, YELLOW_BLUE));
    
    
    mVoiceWaveList.push_back( VoiceWaveTime(511,556,PLAIN));//, YELLOW_BLUE));
    
    mGlitchList.push_back(GlitchEffect(757, 786.5,0.02,0.001));
        // Missing stuff here
    
    mScanLineList.push_back( ScanLineTime(679,699.0,PLAIN));//,SCANLINE_ICE_BLUE));
    mScanLineList.push_back( ScanLineTime(710.0,736,PLAIN));//SCANLINE_ICE_YELLOW));
    
    mMicroWaveList.push_back( MicroWaveTime(791.0, 809.0,PLAIN));//, RED_WHITE_VER));
    
    //0.782825
    // 0.206063
    // 6_Anandamide
   
    
    mWipeList.push_back( Wipe(859.395, 864.659, 0.206063,  0.782825)); // 5.264
    mWipeList.push_back( Wipe(865.509, 870.63,  0.206063,  0.782825)); // 5.121
    mWipeList.push_back( Wipe(871.583, 876.673, 0.206063,  0.782825)); // 5.09
    mWipeList.push_back( Wipe(877.633, 882.661, 0.206063,  0.782825)); // 5.02
    mWipeList.push_back( Wipe(883.703, 888.800, 0.206063,  0.782825)); // 5.097
    mWipeList.push_back( Wipe(889.773, 894.833, 0.206063,  0.782825)); // 5.06
    mWipeList.push_back( Wipe(895.833, 900.886, 0.206063,  0.782825)); // 5.053
    mWipeList.push_back( Wipe(902.083, 906.996, 0.206063,  0.782825)); // 4.913	
    
    
    mMicroWaveList.push_back( MicroWaveTime(908.0,1052.0,PLAIN));//, GREEN_BLUE_HOR));
     */
    vector<std::pair< string, EffectTime >> unsortedDisplayList;
    for( auto &cursor : mCursorEffectList )
    {
        unsortedDisplayList.push_back( cursor.getInfo() );
    }
    for( auto &terrain : mTerrainList )
    {
        unsortedDisplayList.push_back( terrain.getInfo() );
    }
    for( auto &wave : mMicroWaveList )
    {
        unsortedDisplayList.push_back( wave.getInfo() );
    }
    for(auto spike : mVoiceSpikesList)
    {
        unsortedDisplayList.push_back( spike.getInfo() );
    }
    for(auto shape : mShapeExplorerList)
    {
        unsortedDisplayList.push_back( shape.getInfo() );
    }
    for(auto gui : mGui2List)
    {
        unsortedDisplayList.push_back( gui.getInfo() );
    }
    for( auto &glitch : mGlitchList )
    {
        unsortedDisplayList.push_back( glitch.getInfo() );
    }
    for( auto &scan : mScanLineList )
    {
        unsortedDisplayList.push_back( scan.getInfo() );
    }
    for( auto shape : mMorphShapeList )
    {
        unsortedDisplayList.push_back( shape.getInfo() );
    }
    for( auto &voice : mVoiceWaveList )
    {
        unsortedDisplayList.push_back( voice.getInfo() );
    }
    for( auto &circle : mLoadingCirclesList )
    {
        unsortedDisplayList.push_back( circle.getInfo() );
    }
    for( auto &liquid : mLiquidVoiceList )
    {
        unsortedDisplayList.push_back( liquid.getInfo() );
    }
    for( auto &loadingBar : mLoadingBarList )
    {
        unsortedDisplayList.push_back( loadingBar.getInfo() );
    }
    for( auto &connGraph : mConnGraphList )
    {
        unsortedDisplayList.push_back( connGraph.getInfo() );
    }
    for( auto &nodeJoin : mJoinList )
    {
        unsortedDisplayList.push_back( nodeJoin.getInfo() );
    }
    for( auto &grid : mGridList )
    {
        unsortedDisplayList.push_back( grid.getInfo() );
    }
    for( auto &grid : mGridVanishList )
    {
        unsortedDisplayList.push_back( grid.getInfo() );
    }
    for( auto &grid : mGridHorVerList )
    {
        unsortedDisplayList.push_back( grid.getInfo() );
    }
    for( auto &frame : mFrameList )
    {
        unsortedDisplayList.push_back( frame.getInfo() );
    }
    for( auto &wipe : mWipeList )
    {
        unsortedDisplayList.push_back( wipe.getInfo() );
    }
    for( auto &laserGui : mLaserGuiList )
    {
        unsortedDisplayList.push_back(laserGui.getInfo() );
    }
    
    // Sort
    sort(unsortedDisplayList.begin(), unsortedDisplayList.end(), compareEffectTime);
    for(int i = 0; i < unsortedDisplayList.size();i++)
    {
        effectDisplayList.push_back(unsortedDisplayList[i]);
    }
}

float LaserManager:: toTotalSeconds(int min, int sec)
{
    return (float)(min * 60 + sec);
}

void LaserManager::checkCursorEffectList(float timelinePos)
{
    for( auto &cursor : mCursorEffectList )
    {
        if( cursor.isStart( timelinePos ) )
        {
            cursor.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkTerrainList(float timelinePos)
{
    for( auto &terrain : mTerrainList )
    {
        if( terrain.isStart( timelinePos ) )
        {
            terrain.getFrame( timelinePos, &mDrawFrame );
        }
    }
}
void LaserManager::checkMicroWaveList( float timelinePos)
{
    for( auto &wave : mMicroWaveList )
    {
        if( wave.isWaveStart( timelinePos ) )
        {
            wave.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkSpikeList(float timelinePos)
{
    for(auto spike : mVoiceSpikesList)
    {
        if(spike.isStart(timelinePos))
        {
            spike.getFrame(timelinePos, &mDrawFrame);
        }
    }
}
void LaserManager::checkShapeExplorerList(float timelinePos)
{
    for(auto shape : mShapeExplorerList)
    {
        if(shape.isStart(timelinePos))
        {
            shape.getFrame(timelinePos, &mDrawFrame);
        }
    }
}

void LaserManager::checkGui2List(float timelinePos)
{
    for(auto gui : mGui2List)
    {
        if(gui.isGuiStart(timelinePos))
        {
            gui.getFrame(timelinePos, &mDrawFrame);
        }
    }
}

void LaserManager::checkGlitchList( float timelinePos)
{
    for( auto &glitch : mGlitchList )
    {
        if( glitch.isGlitchStart( timelinePos ) )
        {
            glitch.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkScanLineList( float timelinePos)
{
    for( auto &scan : mScanLineList )
    {
        if( scan.isScanStart( timelinePos ) )
        {
            scan.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkMorphShapeList(float timelinePos)
{
    for( auto shape : mMorphShapeList )
    {
        if( shape.isStart( timelinePos ) )
        {
            shape.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkVoiceWaveList( float timelinePos)
{
    for( auto &voice : mVoiceWaveList )
    {
        if( voice.isVoiceStart( timelinePos ) )
        {
            voice.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkLoadingCirclesList( float timelinePos)
{
    for( auto &circle : mLoadingCirclesList )
    {
        if( circle.isCircleStart( timelinePos ) )
        {
            circle.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkLaserGuiList( float timelinePos)
{
    for( auto &laserGui : mLaserGuiList )
    {
        if( laserGui.isGuiStart( timelinePos ) )
        {
            laserGui.getFrame( timelinePos, &mDrawFrame );
        }
    }
}
void LaserManager::checkLineHighlightList(float timelinePos)
{
    for( auto &line : mLineHighlightList )
    {
        if( line.isGuiStart( timelinePos ) )
        {
            line.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkCircleGuiList(float timelinePos)
{
    for( auto &circleGui : mCircleGuiList )
    {
        if( circleGui.isGuiStart( timelinePos ) )
        {
            circleGui.getFrame( timelinePos, &mDrawFrame );
        }
    }
}
void LaserManager::checkLiquidVoiceList(float timelinePos)
{
    for( auto &liquid : mLiquidVoiceList )
    {
        if( liquid.isGuiStart( timelinePos ) )
        {
            liquid.getFrame( timelinePos, &mDrawFrame );
        }
    }
}


void LaserManager::checkLoadingBarList(float timelinePos)
{
    for( auto &loadingBar : mLoadingBarList )
    {
        if( loadingBar.isGuiStart( timelinePos ) )
        {
            loadingBar.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkConnGraphList( float timelinePos)
{
    for( auto &connGraph : mConnGraphList )
    {
        if( connGraph.isJoinStart( timelinePos ) )
        {
            connGraph.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkNodeList( float timelinePos )
{
    for( auto &nodeJoin : mJoinList )
    {
        if( nodeJoin.isJoinStart( timelinePos ) )
        {
            nodeJoin.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkGridList( float timelinePos )
{
    for( auto &grid : mGridList )
    {
        if( grid.isGridStart( timelinePos ) )
        {
            grid.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkGridVanishList(  float timelinePos )
{
    for( auto &grid : mGridVanishList )
    {
        if( grid.isGridStart( timelinePos ) )
        {
            grid.getFrame( timelinePos, &mDrawFrame );
        }
    }
    
}

void LaserManager::checkGridHorVerShapeList(float timelinePos)
{
    for( auto &grid : mGridHorVerList )
    {
        if( grid.isStart( timelinePos ) )
        {
            grid.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkFrameList( float timelinePos )
{
    for( auto &frame : mFrameList )
    {
        if( frame.isFrameStart( timelinePos ) )
        {
             frame.getFrame( timelinePos, &mDrawFrame );
        }
    }
}

void LaserManager::checkWipeList( float timelinePos )
{
    for( auto &wipe : mWipeList )
    {
        if( wipe.isWipeStart( timelinePos ) )
        {
            float wipePos = wipe.getWipePos( timelinePos );
            
            mDrawFrame.addPoly();
            mDrawFrame.getLastPoly().lineTo( wipePos, 0 );
            mDrawFrame.getLastPoly().lineTo( wipePos, 1 );
            mDrawFrame.colMode = PLAIN;//ICE;
        }
    }
}

void LaserManager::resetKeystone()
{
    mCorners[0] = ofVec2f( 0.0, 0.0 );
    mCorners[1] = ofVec2f( 1.0, 0.0 );
    mCorners[2] = ofVec2f( 1.0, 1.0 );
    mCorners[3] = ofVec2f( 0.0, 1.0 );
}

void LaserManager::saveKeystone()
{
    ofstream outFile;
    outFile.open (ofToDataPath(KEYSTONE_FILE));
    for(int j = 0; j < 4; j++)
    {
            outFile << mCorners[j].x << " " << mCorners[j].y <<endl;
    }
    outFile.close();
}

void LaserManager::loadKeystone()
{
    string line;
    ifstream inFile (ofToDataPath(KEYSTONE_FILE));
    if (inFile.is_open())
    {
        
        for (int j = 0; getline (inFile,line); j++ )
        {
            istringstream iss(line, istringstream::in);
            
            string word;
            for(int i = 0; iss >> word; i++ )
            {
                int indx = j %4;
                
                if(i==0)
                    mCorners[indx].x = ofToFloat(word);
                if(i==1)
                    mCorners[indx].y = ofToFloat(word);
                
                
            }
        }
        inFile.close();
    }
}

void LaserManager::init()
{
        mBlank=false;
    
        mEtherDream.stop();
        mEtherDream.kill();
        
        cout << "CONNECTING TO ETHERDREAM: " << endl;
        mEtherDream.setup(true, 0);
        mEtherDream.setPPS( ETHER_DREAM_PPS );
    
    
        audioFileEffect1 = new AudioFileEffect( "audio/wetware_test_44100.wav" );
}

void LaserManager::draw( ofTrueTypeFont * font,float timelinePos )
{
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(ofColor::green);
    
    ofDrawRectangle(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetWidth()/2);
    
    mDrawFrame.draw(ofGetWidth()/2, 0,ofGetWidth()/2, ofGetWidth()/2);
    
    float w = ofGetWidth() / 2;
    ofSetColor(ofColor::white);
    font->drawString("Laser Status " + mEtherDream.getStateLabel(), w+ 10, 20);
    
    if(ofGetElapsedTimef() < 5.0)
    {
        font->drawString("startup delay: " + ofToString(5.0-ofGetElapsedTimef()),w+ 10, 40);
    }
    ofSetColor(255,0,255);
    ofBeginShape();
    ofVertex( w + mCorners[0].x * w, mCorners[0].y * w );
    ofVertex( w + mCorners[1].x * w, mCorners[1].y * w );
    ofVertex( w + mCorners[2].x * w, mCorners[2].y * w );
    ofVertex( w + mCorners[3].x * w, mCorners[3].y * w );
    ofEndShape(true);
    
    ofEndShape();
    ofPopStyle();
    
    if(mBlank)
    {
        ofSetColor(ofColor::white);
        font->drawString("BLANK",ofGetWidth()/2 + ofGetWidth()/4, ofGetHeight()/4);
    }
    ofPushMatrix();
    ofTranslate(230, 20);
    for( auto info : effectDisplayList)
    {
        if(info.second.isStart(timelinePos))
            ofSetColor(ofColor::green);
        else
            ofSetColor(ofColor::black);
        
        ofDrawBitmapString(info.first + ": " + getTimeString(info.second.start) + "-" +getTimeString(info.second.end), 0,0);
        ofTranslate(0,20);
    }
    ofPopMatrix();
}

string LaserManager::getTimeString( float time )
{
    return ofToString( (int)( time / 60 ) ) + "." + ofToString( ((int)time)%60 );
}

void LaserManager::setPPS(int pps)
{
    mEtherDream.setPPS(pps);
    
}

void LaserManager::toggleTestPattern()
{
    mShowTestPattern = !mShowTestPattern;
}

void LaserManager::toggleBlank()
{
    mBlank = !mBlank;
}

void LaserManager::blank()
{
    mShowTestPattern=false;
    mBlank = !mBlank;
}


LaserEffect * LaserManager::getCurrEffect()
{
    return mEffect;
}

void LaserManager::update( float timelinePos )
{
    // wait 10 seconds to start running these checks
    if((ofGetElapsedTimef()-lastCheckLaserTime) > CHECK_TIME ) // every one minute make sure it is connected ok
    {
        //printf("Checking lasers: %i %i %i\n",mEtherDream.getState(),ST_SHUTDOWN,ST_DISCONNECTED);
        lastCheckLaserTime=ofGetElapsedTimef();
        
        if( mEtherDream.getState() == ST_SHUTDOWN || mEtherDream.getState() == ST_DISCONNECTED )
        {
            cout << "Reconnecting to laser" << endl;
            init();
        }
    }
    
    if(ofGetElapsedTimef() > STARTUP_DELAY)
    {
        if(mShowTestPattern)
        {
            mDrawFrame=mTestPattern;
            mDrawFrame.update();
            
            sendFrames(mTestPattern);
        }else if(mBlank)
        {
            sendFrames(mBlankFrame);
            
            mDrawFrame = mBlankFrame;
            mDrawFrame.update();
        }else
        {
            mDrawFrame.clear();
            mDrawFrame.colMode = PLAIN;//DEFAULT;
            //mEffect->getFrame( &mDrawFrame );
            
            clearForTimelineEffects(timelinePos);
            
            checkTerrainList(timelinePos);
            checkScanLineList(timelinePos);
            checkVoiceWaveList(timelinePos);
            checkMicroWaveList(timelinePos);
            checkWipeList(  timelinePos );
            checkFrameList( timelinePos );
            checkNodeList(  timelinePos );
            checkGridList ( timelinePos );
            checkGridVanishList(timelinePos);
            checkConnGraphList(timelinePos);
            checkLaserGuiList(timelinePos);
            checkLoadingCirclesList(timelinePos);
            checkGlitchList(timelinePos);
            checkCircleGuiList(timelinePos);
            checkLoadingBarList(timelinePos);
            checkLiquidVoiceList(timelinePos);
            checkLineHighlightList(timelinePos);
            checkGui2List(timelinePos);
            checkMorphShapeList(timelinePos);
            checkGridHorVerShapeList(timelinePos);
            checkShapeExplorerList(timelinePos);
            checkSpikeList(timelinePos);
            checkCursorEffectList(timelinePos);
            mDrawFrame.update();
            
            sendFrames(mDrawFrame);
        }
    }
}

void LaserManager::clearForTimelineEffects(float timelinePos)
{
    for( auto &join : mJoinList )
    {
        if( join.isJoinStart( timelinePos ) )
        {
            mDrawFrame.clear();
        }
    }
    
    for( auto &circles : mLoadingCirclesList )
    {
        if( circles.isCircleStart( timelinePos ) )
        {
            mDrawFrame.clear();
        }
    }
    
    for( auto &laserGui : mLaserGuiList )
    {
        if( laserGui.isGuiStart( timelinePos ) )
        {
            mDrawFrame.clear();
        }
    }
    
    for( auto &wipe : mWipeList )
    {
        if( wipe.isWipeStart( timelinePos ) )
        {
            mDrawFrame.clear();
        }
    }
    
    for( auto &frame : mFrameList )
    {
        if( frame.isFrameStart( timelinePos ) )
        {
            mDrawFrame.clear();
        }
    }
}

void LaserManager::reset()
{
    init();
   
}

ofxIlda::Frame LaserManager::applyHomography( ofxIlda::Frame inputFrame)
{
    ofVec2f dst[4];
    dst[0] = ofVec2f(0,0);
    dst[1] = ofVec2f(1,0);
    dst[2] = ofVec2f(1,1);
    dst[3] = ofVec2f(0,1);
    
    ofPoint src[]={ofPoint( 0, 0 ),ofPoint(1.0,0),ofPoint(1.0, 1.0),ofPoint(0, 1.0)};
    GLfloat matrix[16];
    findHomography(src,mCorners,matrix);
    ofMatrix4x4 H = ofMatrix4x4(matrix);
    
    ofxIlda::Frame warpedFrame;
    warpedFrame.clear();
    
    for(int i =0; i < inputFrame.getPolys().size();i++)
    {
        warpedFrame.addPoly();
        ofPolyline p = inputFrame.getPoly(i);
        for(int j = 0; j < p.getVertices().size();j++)
        {
            ofPoint vert =p.getVertices()[j];
            if(flipY)
            {
                vert.y = 1.0-vert.y;
            }
            ofVec3f warpedPoint = vert * H;
            
            warpedFrame.getLastPoly().lineTo(warpedPoint.x, warpedPoint.y);
            warpedFrame.getLastPoly().color = inputFrame.getLastPoly().color;
        }
    }
    
    warpedFrame.colMode = inputFrame.colMode;
    
    warpedFrame.update();
    
    return warpedFrame;
    
}

void LaserManager::findHomography(ofPoint src[4], ofPoint dst[4], float homography[16]){
    // arturo castro - 08/01/2010
    //
    // create the equation system to be solved
    //
    // from: Multiple View Geometry in Computer Vision 2ed
    //       Hartley R. and Zisserman A.
    //
    // x' = xH
    // where H is the homography: a 3 by 3 matrix
    // that transformed to inhomogeneous coordinates for each point
    // gives the following equations for each point:
    //
    // x' * (h31*x + h32*y + h33) = h11*x + h12*y + h13
    // y' * (h31*x + h32*y + h33) = h21*x + h22*y + h23
    //
    // as the homography is scale independent we can let h33 be 1 (indeed any of the terms)
    // so for 4 points we have 8 equations for 8 terms to solve: h11 - h32
    // after ordering the terms it gives the following matrix
    // that can be solved with gaussian elimination:
    
    float P[8][9]={
        {-src[0].x, -src[0].y, -1,   0,   0,  0, src[0].x*dst[0].x, src[0].y*dst[0].x, -dst[0].x }, // h11
        {  0,   0,  0, -src[0].x, -src[0].y, -1, src[0].x*dst[0].y, src[0].y*dst[0].y, -dst[0].y }, // h12
        
        {-src[1].x, -src[1].y, -1,   0,   0,  0, src[1].x*dst[1].x, src[1].y*dst[1].x, -dst[1].x }, // h13
        {  0,   0,  0, -src[1].x, -src[1].y, -1, src[1].x*dst[1].y, src[1].y*dst[1].y, -dst[1].y }, // h21
        
        {-src[2].x, -src[2].y, -1,   0,   0,  0, src[2].x*dst[2].x, src[2].y*dst[2].x, -dst[2].x }, // h22
        {  0,   0,  0, -src[2].x, -src[2].y, -1, src[2].x*dst[2].y, src[2].y*dst[2].y, -dst[2].y }, // h23
        
        {-src[3].x, -src[3].y, -1,   0,   0,  0, src[3].x*dst[3].x, src[3].y*dst[3].x, -dst[3].x }, // h31
        {  0,   0,  0, -src[3].x, -src[3].y, -1, src[3].x*dst[3].y, src[3].y*dst[3].y, -dst[3].y }, // h32
    };
    
    gaussian_elimination(&P[0][0],9);
    
    // gaussian elimination gives the results of the equation system
    // in the last column of the original matrix.
    // opengl needs the transposed 4x4 matrix:
    float aux_H[]={ P[0][8],P[3][8],0,P[6][8], // h11  h21 0 h31
        P[1][8],P[4][8],0,P[7][8], // h12  h22 0 h32
        0      ,      0,0,0,       // 0    0   0 0
        P[2][8],P[5][8],0,1};      // h13  h23 0 h33
    
    for(int i=0;i<16;i++) homography[i] = aux_H[i];
}

void LaserManager::gaussian_elimination(float *input, int n)
{
    // arturo castro - 08/01/2010
    //
    // ported to c from pseudocode in
    // [http://en.wikipedia.org/wiki/Gaussian-elimination](http://en.wikipedia.org/wiki/Gaussian-elimination)
    
    float * A = input;
    int i = 0;
    int j = 0;
    int m = n-1;
    while (i < m && j < n){
        // Find pivot in column j, starting in row i:
        int maxi = i;
        for(int k = i+1; k<m; k++){
            if(fabs(A[k*n+j]) > fabs(A[maxi*n+j])){
                maxi = k;
            }
        }
        if (A[maxi*n+j] != 0){
            //swap rows i and maxi, but do not change the value of i
            if(i!=maxi)
                for(int k=0;k<n;k++){
                    float aux = A[i*n+k];
                    A[i*n+k]=A[maxi*n+k];
                    A[maxi*n+k]=aux;
                }
            //Now A[i,j] will contain the old value of A[maxi,j].
            //divide each entry in row i by A[i,j]
            float A_ij=A[i*n+j];
            for(int k=0;k<n;k++){
                A[i*n+k]/=A_ij;
            }
            //Now A[i,j] will have the value 1.
            for(int u = i+1; u< m; u++){
                //subtract A[u,j] * row i from row u
                float A_uj = A[u*n+j];
                for(int k=0;k<n;k++){
                    A[u*n+k]-=A_uj*A[i*n+k];
                }
                //Now A[u,j] will be 0, since A[u,j] - A[i,j] * A[u,j] = A[u,j] - 1 * A[u,j] = 0.
            }
            
            i++;
        }
        j++;
    }
    
    //back substitution
    for(int i=m-2;i>=0;i--){
        for(int j=i+1;j<n-1;j++){
            A[i*n+m]-=A[i*n+j]*A[j*n+m];
            //A[i*n+j]=0;
        }
    }
}


ofxIlda::Frame LaserManager::sendFrames( ofxIlda::Frame  frame )
{
    
        ofxIlda::Frame warpedFrame = applyHomography(frame);
    
        if(!mBlank)
        {
            mEtherDream.setPoints( warpedFrame );
        }
        
        mDrawFrame = warpedFrame;
    mDrawFrame.update();
    return mDrawFrame;
}


void LaserManager::mousePressed( ofVec2f mouse )
{
    
    float w = ofGetWidth()/2;
    if( ofRectangle(ofGetWidth()/2 , 0, w, w ).inside(mouse ) )
    {
        // scale position
        ofVec2f scaledPos = ofVec2f((mouse.x - w)/w, mouse.y/w);
        
        printf("Scaled pos: %f %f\n", scaledPos.x, scaledPos.y);
        mSelectedCorner = -1;
        
        for(int i = 0; i < 4; i++)
        {
            
            if( ofDist(scaledPos.x, scaledPos.y, mCorners[i].x, mCorners[i].y) < 0.05 )
            {
                mSelectedCorner = i;
                mCorners[i]  = scaledPos;
            }
        }
    }
    
}

void LaserManager::mouseReleased( ofVec2f mouse )
{
    mSelectedCorner = -1;
}

void LaserManager::mouseDragged( ofVec2f mouse )
{
    float w = ofGetWidth()/2;
    if( ofRectangle(ofGetWidth()/2 , 0, w, w ).inside(mouse ) )
    {
        // scale position
        ofVec2f scaledPos = ofVec2f((mouse.x - w)/w, mouse.y/w);
        
        if(mSelectedCorner >=0 )
        {
            mCorners[mSelectedCorner]  = scaledPos;
        }
    }
    
  
    
}

void LaserManager::sendAudio(float *input, int bufferSize, float microphoneDamp, float microphoneMult, float timelinePos)
{
    for( auto &wave : mMicroWaveList )
    {
            wave.sendAudio(input, bufferSize,microphoneDamp,microphoneMult, timelinePos);
        
    }
    for( auto &voiceSpike : mVoiceSpikesList )
    {
        voiceSpike.sendAudio(input, bufferSize,microphoneDamp,microphoneMult);
        
    }
    
    for( auto &blob : mTerrainList )
    {
        blob.sendAudio(input, bufferSize,microphoneDamp,microphoneMult, timelinePos);
        
       
    }
    
    for( auto &voice : mVoiceWaveList )
    {
        voice.sendAudio(input, bufferSize,microphoneDamp,microphoneMult, timelinePos);
        
    }
    for( auto &voice : mLiquidVoiceList )
    {
        voice.sendAudio(input, bufferSize,microphoneDamp,microphoneMult);
        
    }
}



