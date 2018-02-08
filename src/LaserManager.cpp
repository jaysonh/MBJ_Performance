//
//  LaserManager.cpp
//  StarOfBethlehem
//
//  Created by Jayson Haebich on 27/09/2016.
//
//

#include "LaserManager.hpp"

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
    mTestPattern.getLastPoly().lineTo(0,0);
    mTestPattern.getLastPoly().lineTo(1,0);
    mTestPattern.getLastPoly().lineTo(1,1);
    mTestPattern.getLastPoly().lineTo(0,1);
    mTestPattern.getLastPoly().lineTo(0,0);
    mTestPattern.update();
    
    mBlankFrame.clear();
    mBlankFrame.update();
    
    mShowTestPattern=false;
    
    mEffect = new NoEffect();
    
    loadKeystone();
    
    /*mWipeList.push_back( Wipe(6.0, 7.5) );
    mWipeList.push_back( Wipe(10.0, 14.5) );
    
    
    mFrameList.push_back( Frame( 2.0, 5.0, ofRectangle(0.2, 0.2, 0.5, 0.5) ) );
    mFrameList.push_back( Frame( 3.0, 4.0, ofRectangle(0.0, 0.0, 0.25, 0.25) ) );
    */
    
    mJoinList.push_back( NodeJoin( 1.0, 4.0,  ofVec2f(0.2,0.2), ofVec2f( 0.75, 0.5) ));
    mJoinList.push_back( NodeJoin( 2.0, 5.0,  ofVec2f(0.8,0.8), ofVec2f( 0.75, 0.5) ));
    mJoinList.push_back( NodeJoin( 8.0, 14.0, ofVec2f(0.5,0.5), ofVec2f( 0.15, 0.95) ));
    
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
            mDrawFrame.getLastPoly().color = ofFloatColor(1,1,1);
            mDrawFrame.getLastPoly().lineTo( wipePos, 0 );
            mDrawFrame.getLastPoly().lineTo( wipePos, 1 );
        
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
}

void LaserManager::draw( ofTrueTypeFont * font )
{
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(ofColor::green);
    
    ofDrawRectangle(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetWidth()/2);
    
    mDrawFrame.draw(ofGetWidth()/2, 0,ofGetWidth()/2, ofGetWidth()/2);
    
    float w = ofGetWidth() / 2;
    ofSetColor(ofColor::white);
    font->drawString("Laser Output", w+ 10, 20);
    ofSetColor(255,0,255);
    ofBeginShape();
    ofVertex( w + mCorners[0].x * w, mCorners[0].y * w );
    ofVertex( w + mCorners[1].x * w, mCorners[1].y * w );
    ofVertex( w + mCorners[2].x * w, mCorners[2].y * w );
    ofVertex( w + mCorners[3].x * w, mCorners[3].y * w );
    ofEndShape(true);
    
    ofEndShape();
    ofPopStyle();
}

void LaserManager::setPPS(int pps)
{
    mEtherDream.setPPS(pps);
    
}

void LaserManager::toggleTestPattern()
{
    mShowTestPattern = true;
}

void LaserManager::toggleBlank()
{
    mBlank = !mBlank;
}

void LaserManager::blank()
{
    mShowTestPattern=false;
    mBlank = true;
}

void LaserManager::setEffect( LaserEffecType type )
{
    mEffectType = type;
    mShowTestPattern=false;
    mBlank=false;
    
    switch(mEffectType)
    {
        case NONE:
            mEffect = new NoEffect();
            break;
            
        case VOICE:
            mEffect = new MicrophoneEffect();
            break;
            
        case AUDIOFILE1:
            mEffect = new AudioFileEffect( "audio/wetware_test_44100.wav" );
            break;
    }
}

LaserEffect * LaserManager::getCurrEffect()
{
    return mEffect;
}

void LaserManager::update( float timelinePos , float audioFileDamp, float audioFileMult)
{
    // wait 10 seconds to start running these checks
    
    
    if((ofGetElapsedTimef()-lastCheckLaserTime) > CHECK_TIME ) // every one minute make sure it is connected ok
    {
        //printf("Checking lasers\n");
        lastCheckLaserTime=ofGetElapsedTimef();
        
        if( mEtherDream.getState() == ST_SHUTDOWN )
        {
            init();
        }
        
    }
    if(mShowTestPattern)
    {
        sendFrames(mTestPattern);
        mDrawFrame=mTestPattern;
    }else if(mBlank)
    {
        sendFrames(mBlankFrame);
        mDrawFrame = mBlankFrame;
    }else
    {
        mEffect->update( timelinePos,  audioFileDamp, audioFileMult);
        
        mDrawFrame.clear();
        
        mEffect->getFrame( &mDrawFrame );
        
        clearForTimelineEffects(timelinePos);
        
        checkWipeList(  timelinePos );
        checkFrameList( timelinePos );
        checkNodeList(  timelinePos );
        mDrawFrame.update();
        
        sendFrames(mDrawFrame);
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
            ofVec3f warpedPoint = p.getVertices()[j] * H;
            
            warpedFrame.getLastPoly().lineTo(warpedPoint.x, warpedPoint.y);
        }
    }
    
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
    
    return mDrawFrame;
}


void LaserManager::mousePressed( ofVec2f mouse )
{
    
    float w = ofGetWidth()/2;
    if( ofRectangle(ofGetWidth()/2 , 0, w, w ).inside(mouse ) )
    {
        // scale position
        ofVec2f scaledPos = ofVec2f((mouse.x - w)/w, mouse.y/w);
        
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




