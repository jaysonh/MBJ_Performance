//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef ScanLineTime_h
#define ScanLineTime_h

#include "ofxIldaFrame.h"
#include "EffectTime.h"

class ScanLineTime
{
public:
    
    ScanLineTime( float startTime, float endTime, ColourMode colMode )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        
        mCol  = colMode;
        mScan = 0.0;
       
    }
    
    bool isScanStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            float h = fabs( 0.05 + sin(mScan)*0.9 );
            float w = 0.45;
            
            float timeRunning = timelinePos-mStart;
            float totalTime   = mEnd-mStart;
            float timeFromEnd = mEnd - timelinePos;
            if(timeRunning < 4.0)
            {
                w = ofMap(timeRunning,0,4,0,0.45);
            }else if(timeFromEnd < 4.0)
            {
                w = ofMap(timeFromEnd,4,0,0.45,0);
            }else
            {
                mScan += 0.005;
                
                if(mScan > PI) mScan=0.0;
            }
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,1,0);
            frame->getLastPoly().lineTo(0.5-w,h);
            frame->getLastPoly().lineTo(0.5+w,h);
            frame->colMode = mCol;
            
        }
        
        frame->update();
        
        return *frame;
    }
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("ScanLine", mEffectTime);
    }
    EffectTime mEffectTime;
    
    float mScan;
    ColourMode mCol;
    float mStart, mEnd;
};
#endif /* Wipe_h */




