//
//  DualLaserVoiceWave.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 27/05/2019.
//

#include "DualLaserVoiceWave.h"

DualLaserVoiceWave::DualLaserVoiceWave( EffectTime t )
{
    time = t;
    
}

void DualLaserVoiceWave::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        float mult = 3.0;
        
        vector < float > tmpList;
        for(auto val : *audioVals)
        {
            tmpList.push_back(val);
        }
        
        for(int i = 0; i < tmpList.size();i++)
        {
            ofVec2f p1 = ofVec2f( ofMap(i, 0,tmpList.size(), 0.25,0.75),
                                  ofClamp(tmpList[i]*mult + 0.5,0,1));
            ofVec2f p2 = ofVec2f( ofMap(i+1, 0,tmpList.size(), 0,1),
                                 ofClamp(tmpList[i+1]*mult + 0.5,0.25,0.75));
           
            //cout << p1.y << endl;
            LaserLine line(p1,p2, ofFloatColor(0,1,0));
            if(i > 0)
                line.continous = true;
            frameLeft.push_back( line );
            frameRight.push_back( line );
            frameCentre.push_back( line );
            i++;
        }
        
    }
}
