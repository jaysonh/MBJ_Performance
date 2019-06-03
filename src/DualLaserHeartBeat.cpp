//
//  DualLaserHeartBeat.cpp
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 03/06/2019.
//

#include "DualLaserHeartBeat.h"

DualLaserHeartBeat::DualLaserHeartBeat( EffectTime t,ColourMode c )
{
    time = t;
    colMode = c;
    
    effectName="HeartBeat";
}

void DualLaserHeartBeat::update( float timelinePos, float audioLevel, shared_ptr<vector<float>>audioVals )
{
    if( time.isStart( timelinePos ))
    {
        
        frameRight.clear();
        frameLeft.clear();
        frameCentre.clear();
        
        //float t = (timelinePos - time.start)*0.025;
        
        float timeRunning = timelinePos - time.start;
        float open = 1.0;
        float totalTime = time.end-time.start;
        
        if(timeRunning < openTime)
        {
            open = ofMap(timeRunning,0,openTime,0,1.0);
        }
        
        if (timeRunning > totalTime-closeTime)
        {
            open =  ofMap(timeRunning, totalTime-closeTime,totalTime,1.0,0.0);
        }
        //cout << "time running: " << timeRunning << " OPEN: " << open << endl;
        
        float loudness=0.0;
        vector < float > tmpList;
        for(auto val : *audioVals)
        {
            tmpList.push_back(val);
        }
        
        for (unsigned int i = 0; i < tmpList.size(); i++)
        {
            loudness += abs(tmpList[i]);
            
        }
        
        if(loudness>1.0)loudness=1.0;
        
        float width = 600;
        float height =400;
        float mX = 30.0;
        float mY = 10.0;
        
        float maxHeight = 0.4 * loudness * 10.0 ;
        ofVec2f lastPos;
        float timeTillEnd = time.end-timelinePos;
        float timeSinceStart = timelinePos - time.start;
        
        float size= width * open;
       
        for(float x = 0; x < size; x += 5)
        {
            float y = ofMap(mY
                            *sin(v+(x/ofMap(mX,0,width,1,300)))
                            *tan(w+(x/ofMap(mY,0,width,50,200)))
                            *sin(v+(x/ofMap(mY,0,height,1,50))), 0,height, 0,0.5) ;
            if(y >  maxHeight) y =  maxHeight;
            if(y < -maxHeight) y = -maxHeight;
            
            ofVec2f p = ofVec2f( ofMap(x,0,width,0,1),
                                y + 0.5
                                );
            
            if(p.y < 0.0)p.y=0.0;
            if(p.y > 1.0)p.y=1.0;
            //colMode = inCol;
            
            if(x > 0)
            {
                LaserLine line( ofVec2f(lastPos.x,lastPos.y),
                                ofVec2f(p.x,p.y),ofFloatColor(1,1,1));
                line.continous=true;
                frameCentre.push_back(line);
            }
            lastPos = ofVec2f(p.x,p.y);
            
            //drawFrame->getLastPoly().lineTo(p.x,p.y);
            
        }
        
        v -= 0.02* loudness * 1.0;
        w += 0.04* loudness * 1.0;
        
        
            //LaserLine lineLeft( ofVec2f(0.0,0.5),
            //                   ofVec2f((2.0-v),0.5), ofFloatColor(1,1,1));
            //frameCentre.push_back(lineLeft);
            
    }
}
