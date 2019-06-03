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
    
    effectName="voice wave";
}

void DualLaserVoiceWave::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        float t = timelinePos - time.start;
        float timeTillEnd = time.end- timelinePos;
        
        colMode = ColourMode::GREEN_BLUE_HOR;
        frameLeft.clear();
        frameRight.clear();
        frameCentre.clear();
        
        float mult = 1.0;
        
        vector < float > tmpList;
        for(auto val : *audioVals)
        {
            tmpList.push_back(val);
        }
        
        int numDraw = ofMap(t, 0,4,2, tmpList.size(),true);
        
        if(timeTillEnd < 4.0)
            numDraw = ofMap(timeTillEnd, 4,0, tmpList.size(),0,true);
        
        cout << timeTillEnd << " - " << numDraw << endl;
        for(int i = 0; i < numDraw;i++)
        {
            ofVec2f p1 = ofVec2f( ofMap(i, 0,tmpList.size()-1, 0,1),
                                  ofClamp(tmpList[i]*mult + 0.5,0,1));
            ofVec2f p2 = ofVec2f( ofMap(i+1, 0,tmpList.size()-1, 0,1),
                                 ofClamp(tmpList[i+1]*mult + 0.5,0,1));
           
            //cout << p1.y << endl;
            LaserLine line(p1,p2, ofFloatColor(0,1,0));
            
            if(i > 0)
                line.continous = true;
            //frameLeft.push_back( line );
            //frameRight.push_back( line );
            frameCentre.push_back( line );
            i++;
        }
        
    }
}
