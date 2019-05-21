//
//  SyphonManager.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 18/05/2019.
//

#ifndef SyphonManager_h
#define SyphonManager_h

#include "VisualGen.h"

#include "ofxSyphon.h"

class SyphonManager
{
public:
    
    void init();
    void update();
    void draw();
    
private:
    
    vector <VisualGen> visualList;
    ofTexture outputTex;
    ofFbo     outputFbo;
    
    ofxSyphonServer syphonOutput;
};

#endif /* SyphonManager_h */
