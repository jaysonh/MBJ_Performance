//
//  AudioFileEffect.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 31/01/2018.
//

#include "AudioFileEffect.hpp"

AudioFileEffect::AudioFileEffect(string audioFile)
{
    if(player.load( ofToDataPath(audioFile) ))
    {
        stream.setup(2, 2, player.getSoundFile().getSampleRate(), 256, 1);
        stream.setOutput(output);
        
        player.play();
        player.setLoop(true);
        
        
        wave.setup(0, 0, ofGetWidth()/2, ofGetHeight()/2);
        
        
        player.connectTo(wave).connectTo(output);
    }else
    {
        cout << "cannot load audio file"<<endl;
    }
    prevSamplesWav.resize(512);
    
}

void AudioFileEffect::update( float timelinePos, float audioFileDamp, float audioFileMult )
{
    mAudioMult = audioFileMult;
    
    vector <float> samples = wave.buffer.getBuffer();
    audioFileWave.clear();
    for(int i = 0; i < samples.size();i+=2)
    {
        float val;
        if(ofGetFrameNum()%3==0)
        {
            val = samples[i] * (1.0-audioFileDamp) + prevSamplesWav[i] * audioFileDamp;
            prevSamplesWav[i] = val;
        }else
        {
            prevSamplesWav[i] *= audioFileDamp;
            val = prevSamplesWav[i];
        }
        audioFileWave.push_back(val);
    }
    
    
    
}
ofxIlda::Frame AudioFileEffect::getFrame( ofxIlda::Frame * drawFrame )
{
    //drawFrame = &mIldaFrame;
    drawFrame->clear();
    drawFrame->addPoly();
    drawFrame->getLastPoly().color = ofFloatColor(1.0,0.0,1.0);
    for (unsigned int i = 0; i < audioFileWave.size(); i++)
    {
        float h = ofClamp(audioFileWave[i]* mAudioMult, -0.5, 0.5);
        
        drawFrame->getLastPoly().lineTo( ofMap(i, 0, audioFileWave.size(),0,1), h + 0.5);
    }
    
    drawFrame->update();
    
    return *drawFrame;
}


void AudioFileEffect::sendAudio( float *input, int bufferSize, float microphoneDamp, float microphoneMult)
{
    
}
