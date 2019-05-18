//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef CursorEffect_h
#define CursorEffect_h

#include "ofxIldaFrame.h"
#include "EffectTime.h"
#include "EffectTime.h"

class CursorEffect
{
public:
    
    CursorEffect( float startTime, float endTime, float swipeTime,ColourMode col )
    {
        mStart     = startTime;
        mEnd       = endTime;
        mSwipeTime = swipeTime;
        mCol       = col;
        mEffectTime = EffectTime(startTime,endTime);
        
        wipeTimes.push_back(std::make_pair(toTotalSeconds(25,19),toTotalSeconds(24,24)));//859.395, 864.659)); // 25.19.01 ->25.24.17
        wipeTimes.push_back(std::make_pair(toTotalSeconds(25,24),toTotalSeconds(25,31)));//865.509, 870.63));  // 25.24.17 ->25.31.19
        wipeTimes.push_back(std::make_pair(toTotalSeconds(25,31),toTotalSeconds(25,37)));//871.583, 876.673)); // 25.31.19 -> 25.37.05
        wipeTimes.push_back(std::make_pair(toTotalSeconds(25,37),toTotalSeconds(25,42)));//877.633, 882.661)); // 25.37.05 -> 25.42.51
        wipeTimes.push_back(std::make_pair(toTotalSeconds(25,42),toTotalSeconds(25,49)));//883.703, 888.800)); // 25.42.51 -> 25.49.00
        //wipeTimes.push_back(std::make_pair(toTotalSeconds(25,49),toTotalSeconds(25,55)));//889.773, 894.833)); // 25.49.00 -> 25.55.09
        //wipeTimes.push_back(std::make_pair(895.833, 900.886)); //
        //wipeTimes.push_back(std::make_pair(902.083, 906.996)); //
        
    }
    
    float  toTotalSeconds(int min, int sec)
    {
        return (float)(min * 60 + sec);
    }
    bool isStart( float timelinePos )
    {
        return( timelinePos > 0.0 && timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            float timeRunning = timelinePos - mStart;
            float timeFromEnd = mEnd - timelinePos;
            float totalTime = mEnd - mStart;
            
            float opening=0.0;
            frame->setColMode(mCol);
            int numCursors = 0;//(int)(timeRunning / mSwipeTime);
            
            // go through wipelist and check if within that time
            for(int i = 0; i < wipeTimes.size();i++)
            {
                //cout << "checking: " << timelinePos << " against: " << wipeTimes[i].first << "," << wipeTimes[i].second <<endl;
                if( timelinePos >= wipeTimes[i].first && timelinePos < wipeTimes[i].second)
                {
                    numCursors=i;
                }else if(i == wipeTimes.size()-1 && timelinePos > wipeTimes[i].second)
                {
                    numCursors = wipeTimes.size();
                }
            }
            
            
            for(int i = 0; i <= numCursors; i++)
            {   
                float y = 0.1 + ((float)i * (0.8 / 6.0));
                
                if(i == numCursors)
                {
                    if( (ofGetFrameNum()/30) % 2==0)
                    {
                        frame->addPoly();
                        frame->getLastPoly().color = ofFloatColor(0,0.5,1);
                        frame->getLastPoly().lineTo(1.0-0.05, y);
                        frame->getLastPoly().lineTo(1.0-0.15, y);
                    }else
                    {
                        frame->addPoly();
                        frame->getLastPoly().color = ofFloatColor(1,1,1);
                        frame->getLastPoly().lineTo(1.0-0.05, y);
                        frame->getLastPoly().lineTo(1.0-0.15, y);
                    }
                }else
                {
                    frame->addPoly();
                    frame->getLastPoly().color = ofFloatColor(1,1,1);
                    frame->getLastPoly().lineTo(1.0-0.05, y);
                    frame->getLastPoly().lineTo(1.0-0.15, y);
                }
            }
        }
        
        return *frame;
    }
    
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("CursorEffect", mEffectTime);
    }
    EffectTime mEffectTime;
    
    vector<std::pair<float,float>> wipeTimes;
    
    const float OPEN_TIME = 4.0;
    float mSwipeTime;
    ColourMode mCol;
    float mStart, mEnd;
};
#endif



