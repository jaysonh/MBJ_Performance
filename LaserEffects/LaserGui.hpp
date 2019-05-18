//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LaserGui_h
#define LaserGui_h

#include "ofxIldaFrame.h"
#include "EffectTime.h"

class LaserGui
{
public:
    
    LaserGui( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        mCol = col;
        
    }
    
    bool isGuiStart( float timelinePos )
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
            float legOpen = 1.0;
            
            if(timeRunning < 4.0)
            {
                opening = ofMap(timeRunning, 0, 4, 0, 1);
                legOpen=0.0;
            }
            
            if(timeFromEnd < 4.0)
            {
                opening = ofMap(timeFromEnd, 0, 4, 0, 1);
                legOpen=0.0;
            }
            
            if(timeRunning > 4.0 && timeRunning < 6.0)
            {
                legOpen = ofMap(timeRunning, 4,6,0,1);
            }
            
            if(timeFromEnd > 4.0 && timeFromEnd < 6.0)
            {
                legOpen = ofMap(timeFromEnd, 4,6,0,1);
            }
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.05+0.025*legOpen,  0.5-0.4*opening );
            frame->getLastPoly().lineTo( 0.05,               0.5-0.4*opening );
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.05,  0.5-0.4*opening );
            frame->getLastPoly().lineTo( 0.05,  0.5+0.4*opening );
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.05,               0.5+0.4*opening );
            frame->getLastPoly().lineTo( 0.05+0.025*legOpen, 0.5+0.4*opening );
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.95-0.025*legOpen, 0.5+0.4*opening );
            frame->getLastPoly().lineTo( 0.95,               0.5+0.4*opening );
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.95,  0.5+0.4*opening );
            frame->getLastPoly().lineTo( 0.95,  0.5-0.4*opening );
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.95,               0.5-0.4*opening );
            frame->getLastPoly().lineTo( 0.95-0.025*legOpen, 0.5-0.4*opening );
            
            //frame->colMode = ICE;
        }
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Gui", mEffectTime);
    }
    EffectTime mEffectTime;
    
    ColourMode mCol;
    float mStart, mEnd;
};
#endif



