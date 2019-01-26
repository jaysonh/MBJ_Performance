//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef ScanLineTime_h
#define ScanLineTime_h

#include "ofxIldaFrame.h"

class ScanLineTime
{
public:
    
    ScanLineTime( float startTime, float endTime, ColourMode colMode )
    {
        mStart = startTime;
        mEnd   = endTime;
        
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
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(0,1,0);
            frame->getLastPoly().lineTo(0.05,h);
            frame->getLastPoly().lineTo(0.95,h);
            frame->colMode = mCol;
            
        }
        
        frame->update();
        
        mScan += 0.005;
        
        if(mScan > PI) mScan=0.0;
        
        return *frame;
    }
    
    float mScan;
    ColourMode mCol;
    float mStart, mEnd;
};
#endif /* Wipe_h */




