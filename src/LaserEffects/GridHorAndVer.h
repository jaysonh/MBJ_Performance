//
//  GridHorAndVer.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef GridHorAndVer_h
#define GridHorAndVer_h


#include "ofxIldaFrame.h"
#include "EffectTime.h"

class GridHorAndVer
{
public:
    
    GridHorAndVer( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        mCol = col;
    }
    
    bool isStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    float getClampedVal(float in)
    {
        return  ofClamp(in,0,1);
        
    }
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            frame->setColMode(mCol);
            float open = 0.0;
            float timeRunning = timelinePos - mStart;
            float timeFromEnd = mEnd - timelinePos;
            if(timeRunning < 4.0)
            {
                open = ofMap(timeRunning, 0,4,1,0);
            }
            if(timeFromEnd < 4.0)
            {
                open = ofMap(timeFromEnd, 4,0,0,1);
            }
            
            if(timeRunning < 4.0)
            {
                open = ofMap(timeRunning, 0,4,1,0);
            }
            
            //float fadeIn = 1.0;
            //if(timeRunning < 10.0)
             //   fadeIn = ofMap(timeRunning,0,10,0,1);
            
            //horizontal lines
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(0.0, 1.0-getClampedVal(0.6+open) );
            frame->getLastPoly().lineTo(1.0, 1.0-getClampedVal(0.6+open) );

            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(0.0, 1.0-getClampedVal(0.7+open)  );
            frame->getLastPoly().lineTo(1.0, 1.0-getClampedVal(0.7+open)  );
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(0.0, 1.0-getClampedVal(0.9+open) );
            frame->getLastPoly().lineTo(1.0, 1.0-getClampedVal(0.9+open) );
            
            //vertical lines
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(0.0, 1.0-getClampedVal(0.8+open));
            frame->getLastPoly().lineTo(0.2, 1.0-getClampedVal(0.6+open));
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(0.20, 1.0-getClampedVal( 1.0+open));
            frame->getLastPoly().lineTo(0.4 , 1.0-getClampedVal( 0.6+open));
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(0.6  ,1.0-getClampedVal( 0.6+open));
            frame->getLastPoly().lineTo(0.75 ,1.0-getClampedVal( 1.0+open));

            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo(1.0 , 1.0-getClampedVal(0.8+open));
            frame->getLastPoly().lineTo(0.8 , 1.0-getClampedVal(0.6+open));
            
        }
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("GridHorVer", mEffectTime);
    }
    
    EffectTime mEffectTime;
    
    ColourMode mCol;
    float mStart, mEnd;
};
#endif /* Wipe_h */


