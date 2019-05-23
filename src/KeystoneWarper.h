//
//  KeystoneWarper.h
//  ShanghaiGrandTheatre
//
//  Created by Jayson Haebich on 10/02/2019.
//

#ifndef KeystoneWarper_h
#define KeystoneWarper_h

#include "ofMain.h"
#include "LaserLine.h"

#include "ofxJSON.h"
#define KEYSTONE_FILE "keystone.json"

class KeystoneWarper
{
public:
    
    void init();
    void update();
    void draw();
    
    void mousePressed( ofVec2f p );
    void mouseDragged( ofVec2f p );
    void mouseReleased( ofVec2f p );
    
    //void applyKeystone( vector<LaserLine> * applyToLines );
    //void applyKeystone (LaserLine * line);
    
    void saveJSON( string filename  );
    void loadJSON( string filename  );
    
    void reset();
    
private:
    void setupKeystone();
    
    void findHomography(ofPoint src[4], ofVec2f dst[4], float homography[16]);
    void gaussian_elimination(float *input, int n);
    
    ofVec2f corners[4];
    int     selectedCorner;
    ofMatrix4x4 H;
    vector <LaserLine> lines;
    vector <LaserLine> linesWarped;
};

#endif /* KeystoneWarper_h */
