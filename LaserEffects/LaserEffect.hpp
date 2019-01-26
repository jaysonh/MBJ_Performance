//
//  LaserEffect.hpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#ifndef LaserEffect_hpp
#define LaserEffect_hpp

#include <stdio.h>
#include "ofxIldaFrame.h"
#include "WipeEffect.hpp"
#include "FrameEffect.hpp"
#include "NodeJoinEffect.hpp"
#include "MicrophoneEffect.hpp"
#include "AudioFileEffect.hpp"
#include "Wipe.h"
#include "NoEffect.hpp"
#include "Frame.h"
#include "NodeJoin.h"
#include "Grid.h"
#include "GridVanishing.h"
#include "ConnectedGraph.h"
#include "VoiceWave.hpp"
#include "GreenScanLine.hpp"
#include "laserGui.hpp"
#include "LoadingCircle.h"
#include "MicroWaveTime.h"
#include "VoiceWaveTime.h"
#include "ScanLineTime.h"
#include "GlitchEffect.h"
#include "LaserGuiCircle.hpp"
#include "LoadingBar.h"
#include "LiquidVoice.h"
#include "LaserGui2.h"
#include "LineHighlight.h"
#include "TerrainContours.h"

class LaserEffect
{
public:
    
    virtual void update( float timelinePos, float audioFileDamp, float audioFileMult ) = 0;
    virtual ofxIlda::Frame getFrame( ofxIlda::Frame * drawFrame) = 0;
    virtual void sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult) = 0;
    virtual void stopEffect() =0;
};

#endif /* LaserEffect_hpp */
