//
//  KeystoneWarper.cpp
//  ShanghaiGrandTheatre
//
//  Created by Jayson Haebich on 10/02/2019.
//

#include "KeystoneWarper.h"

void KeystoneWarper::init()
{
    reset();
    loadJSON( "keystoneLeft.json" );
    loadJSON( "keystoneRight.json" );
    setupKeystone();
}


void KeystoneWarper::saveJSON( string filename )
{
    ofxJSONElement json;
    
    
    json["x0"] =  corners[0].x;
    json["y0"] =  corners[0].y;
    json["x1"] =  corners[1].x;
    json["y1"] =  corners[1].y;
    json["x2"] =  corners[2].x;
    json["y2"] =  corners[2].y;
    json["x3"] =  corners[3].x;
    json["y3"] =  corners[3].y;
    
    
    json.save(filename);
}
void KeystoneWarper::loadJSON( string filename )
{
    ofxJSONElement json;
    json.open(filename);
    
    corners[0].x= json["x0"].asFloat()  ;
    corners[0].y= json["y0"].asFloat() ;
    corners[1].x= json["x1"].asFloat() ;
    corners[1].y= json["y1"].asFloat() ;
    corners[2].x= json["x2"].asFloat() ;
    corners[2].y= json["y2"].asFloat() ;
    corners[3].x= json["x3"].asFloat();
    corners[3].y= json["y3"].asFloat() ;
}

void KeystoneWarper::reset()
{
    corners[0] = ofVec2f( 0.0, 0.0 );
    corners[1] = ofVec2f( 1.0, 0.0 );
    corners[2] = ofVec2f( 1.0, 1.0 );
    corners[3] = ofVec2f( 0.0, 1.0 );
}

void KeystoneWarper::update()
{
    
}
/*void KeystoneWarper::applyKeystone (LaserLine * line)
{
    ofVec3f v1 =ofVec3f(line->begin.x, line->begin.y,0) * H;
    ofVec3f v2 =ofVec3f(line->end.x,   line->end.y,0)   * H;
    line->begin = v1;
    line->end   = v2;
}

void KeystoneWarper::applyKeystone( vector<LaserLine> * applyToLines )
{
    for(auto line : *applyToLines)
    {
        ofVec3f v1 =ofVec3f(line.begin.x, line.begin.y,0) * H;
        ofVec3f v2 =ofVec3f(line.end.x,   line.end.y,0)   * H;
        line.begin = v1;
        line.end   = v2;
        
 
    }
}
*/
void KeystoneWarper::setupKeystone()
{
    
    
    ofPoint src[]={ofPoint( 0, 0 ),ofPoint(1.0,0),ofPoint(1.0, 1.0),ofPoint(0, 1.0)};
    GLfloat matrix[16];
    findHomography(src,corners,matrix);
    H = ofMatrix4x4(matrix);
}

void KeystoneWarper::draw()
{
    ofPushStyle();
    
    ofSetColor( ofColor::green );
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < 4; i++)
    {
        ofVertex(corners[i].x * (float)ofGetWidth(), corners[i].y * (float)ofGetHeight());
    }
    ofEndShape(true);
    
    ofPopStyle();
}

void KeystoneWarper::mousePressed( ofVec2f p )
{
    selectedCorner = -1;
    
    ofVec2f scaledPos = ofVec2f(p.x /(float)ofGetWidth(), p.y / (float)ofGetHeight());
    
    for(int i = 0; i < 4; i++)
    {
        
        if( ofDist(scaledPos.x, scaledPos.y, corners[i].x, corners[i].y) < 0.025 )
        {
            selectedCorner = i;
        }
    }
}

void KeystoneWarper::mouseReleased( ofVec2f p )
{
    selectedCorner = -1;
}


void KeystoneWarper::mouseDragged( ofVec2f p )
{
    ofVec2f scaledPos = ofVec2f( p.x / (float)ofGetWidth(), p.y / (float)ofGetHeight());
    
    if(selectedCorner >=0 )
    {
        corners[selectedCorner]  = scaledPos;
        
        setupKeystone();
    }
}

void KeystoneWarper::findHomography(ofPoint src[4], ofVec2f dst[4], float homography[16]){
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

void KeystoneWarper::gaussian_elimination(float *input, int n){
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
