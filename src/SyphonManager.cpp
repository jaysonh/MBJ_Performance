//
//  SyphonManager.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 18/05/2019.
//

#include "SyphonManager.h"


void SyphonManager::init()
{
    syphonOutput.setName("visual output");
    
    outputFbo.allocate(400, 400);
    outputFbo.getTexture().getTextureData().bFlipTexture = true;
}

void SyphonManager::update()
{
    
    
    outputFbo.begin();
    ofClear(0);
    
    ofSetColor(0,255,0);
    ofDrawRectangle(0,0,150,200);
    outputFbo.end();
    
    syphonOutput.publishFBO(&outputFbo);
}
void SyphonManager::draw()
{
    
    
    
    ofSetColor(255);
    outputFbo.draw(200,-100,400,400);
    
}

