//
//  GlitchEffect.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 21/02/2018.
//

#ifndef GlitchEffect_h
#define GlitchEffect_h


class GlitchEffect
{
public:
    
    GlitchEffect( float startTime, float endTime, float maxSz, float minSz )
    {
        mStart = startTime;
        mEnd   = endTime;
        mMaxSz = maxSz;
        mMinSz = minSz;
        numDrawPoints =1;
       
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
            
            numDrawPoints  =(int)(timeSinceStart*0.1+1);
            if(numDrawPoints > 4)
                numDrawPoints = 4;
            
            float lineSize = ofMap(timeSinceStart, 0, timeDiff, mMaxSz,mMinSz );
            cout << lineSize << endl;
            frame->addPoly();
            
            
            // Draw 5 random lines
            for(int i = 0; i < numDrawPoints; i++)
            {
                ofVec2f randPos = ofVec2f(ofRandom(0.05,0.95), ofRandom(0.05,0.95)-lineSize);
                
                frame->addPoly();
                frame->getLastPoly().lineTo( randPos.x,            randPos.y );
                frame->getLastPoly().lineTo( randPos.x + lineSize, randPos.y );
            }
            
           // frame->colMode = ICE;
        }
        
       
        
        return *frame;
    }
    int numDrawPoints;
    
    float mStart, mEnd;
    float mMinSz,mMaxSz;
};
#endif /* GlitchEffect_h */
