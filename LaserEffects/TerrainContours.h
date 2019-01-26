//
//  TerrainContours.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef TerrainContours_h
#define TerrainContours_h

#include "ofxIldaFrame.h"

class TerrainContours
{
public:
    
    TerrainContours( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
    }
    
    bool isStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            
            float timeRunning = timelinePos - mStart;
            float timeFromEnd = mEnd - timelinePos;
            
            float opening = 1.0;
            
            if(timeRunning < OPEN_TIME)
            {
                opening = ofMap(timeRunning, 0, OPEN_TIME, 0, 1);
                
            }
            
            if(timeFromEnd < OPEN_TIME)
            {
                opening = ofMap(timeFromEnd, 0, OPEN_TIME, 0, 1);
                
            }
            
            
            float radius = 0.25;
            
            float startX = 0.0;
            float startY = 0.0;
            
            for(int i = 0; i < 2; i++)
            {
                float xoff = 0;
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(0,1,0);
                for( float a = 0.0; a < TWO_PI; a+= 0.1)
                {
                    
                    float offset = ofMap(ofNoise(xoff, yOff), 0, 1, -0.02, 0.02);
                    
                    float x = 0.5 + (radius*0.8 + offset) * cos(a);
                    float y = 0.5 + (radius     + offset) * sin(a);
                    
                    if(a==0.0)
                    {
                        startX = x;
                        startY = y;
                    }
                    
                    frame->getLastPoly().lineTo(x,y);
                    
                    xoff += 0.1;
                }
                frame->getLastPoly().lineTo(startX, startY);
                radius += 0.1;
            }
        }
        yOff += 0.01;
        
        return *frame;
    }
    const float OPEN_TIME = 4.0;
    float yOff=0.0;
    
    float mStart, mEnd;
};
#endif
