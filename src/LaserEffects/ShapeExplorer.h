//
//  GridHorAndVer.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 26/01/2019.
//

#ifndef ShapeExplorer_h
#define ShapeExplorer_h


#include "ofxIldaFrame.h"
#include "EffectTime.h"

class ShapeExplorer
{
public:
    
    ShapeExplorer( float startTime, float endTime, ColourMode col )
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
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            
            frame->setColMode(mCol);
            float open = 1.0;
            float timeRunning = timelinePos - mStart;
            if(timeRunning < 4.0)
            {
                
            }
            
            // line from middle
            if(timeRunning < 4.0)
            {
                float openMiddle = ofMap(timeRunning, 0, 4,0,0.5);
                frame->addPoly();
                frame->getLastPoly().lineTo( 0.5 - openMiddle, 0.5 );
                frame->getLastPoly().lineTo( 0.5 + openMiddle, 0.5 );
            }else if(timeRunning>=4.0 && timeRunning < 10.0)
            {
                float openUp = ofMap(timeRunning, 4, 10,0,0.5);
                frame->addPoly();
                frame->getLastPoly().lineTo( 0.0, 0.5-openUp );
                frame->getLastPoly().lineTo( 0.0, 0.5+openUp );
                frame->getLastPoly().lineTo( 1.0, 0.5+openUp );
                frame->getLastPoly().lineTo( 1.0, 0.5-openUp );
                frame->getLastPoly().lineTo( 0.0, 0.5-openUp );
            }else if(timeRunning >=10.0 && timeRunning < 15.0)
            {
                float closeSide = 0.5;//ofMap(timeRunning, 10, 15,0.5,0.0);
                frame->addPoly();
                frame->getLastPoly().lineTo( 0.5 - closeSide, 0.0);
                frame->getLastPoly().lineTo( 0.5 + closeSide, 0.0);
                frame->getLastPoly().lineTo( 0.5 + closeSide, 1.0);
                frame->getLastPoly().lineTo( 0.5 - closeSide, 1.0);
                frame->getLastPoly().lineTo( 0.5 - closeSide, 0.0);
                
            }else if(timeRunning >=20.0 && timeRunning < 25.0)
            {
                float closeSide = ofMap(timeRunning, 10, 15,0.5,0.0);
                frame->addPoly();
                frame->getLastPoly().lineTo( 0.5 - closeSide, 0.0);
                frame->getLastPoly().lineTo( 0.5 + closeSide, 0.0);
                frame->getLastPoly().lineTo( 0.5 + closeSide, 1.0);
                frame->getLastPoly().lineTo( 0.5 - closeSide, 1.0);
                frame->getLastPoly().lineTo( 0.5 - closeSide, 0.0);
                
            }else if(timeRunning >= 25.0 && timeRunning < 30.0)
            {
                float closeTop = ofMap(timeRunning,15.0, 20.0,0.5,0.0);
                frame->addPoly();
                frame->getLastPoly().lineTo(0.5, 0.5-closeTop);
                frame->getLastPoly().lineTo(0.5, 0.5+closeTop);
            }
            
        }
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("ShapeExplorer", mEffectTime);
    }
    EffectTime mEffectTime;
    ColourMode mCol;
    float mStart, mEnd;
};
#endif /* Wipe_h */


