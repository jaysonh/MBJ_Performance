//
//  GlitchEffect.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/02/2018.
//

#ifndef GlitchEffect_h
#define GlitchEffect_h


#include "ofxIldaFrame.h"
#include "EffectTime.h"

class GlitchEffect
{
public:
    
    GlitchEffect( float startTime, float endTime, float maxSz, float minSz,ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        mEffectTime = EffectTime(startTime,endTime);
        mMaxSz = maxSz;
        mMinSz = minSz;
        numDrawPoints =1;
        mCol =col;
    }
    
    bool isGlitchStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            float timeSinceStart = timelinePos - mStart;
            float timeDiff = mEnd - mStart;
            
            numDrawPoints  = 0;
            if(numDrawPoints > 4)
                numDrawPoints = 4;
            frame->setColMode(mCol);
            float lineSize = 0.001;
            if(timeSinceStart < timeDiff/2)
            {
                lineSize = ofMap(timeSinceStart, 0, timeDiff/2, 0.001,0.2 );
                numDrawPoints = ofMap(timeSinceStart, 0, timeDiff/2,1,4);
            }else
            {
                lineSize = ofMap(timeSinceStart, timeDiff/2,timeDiff, 0.2,0.001 );
                numDrawPoints = ofMap(timeSinceStart, timeDiff/2,timeDiff,4,1);
            }
            
            // Draw 5 random lines
            for(int i = 0; i < numDrawPoints; i++)
            {
                ofVec2f randPos = ofVec2f(ofRandom(0.05,0.95), ofRandom(0.05,0.95)-lineSize);
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                frame->getLastPoly().lineTo( randPos.x,            randPos.y );
                frame->getLastPoly().lineTo( randPos.x + lineSize, randPos.y );
            }
            
        }
        
       
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("Glitch", mEffectTime);
    }
    EffectTime mEffectTime;
    int numDrawPoints;
    ColourMode mCol;
    float mStart, mEnd;
    float mMinSz,mMaxSz;
};
#endif /* GlitchEffect_h */
