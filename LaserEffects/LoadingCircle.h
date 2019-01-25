//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LoadingCircle_h
#define LoadingCircle_h

class LoadingCircle
{
public:
    
    LoadingCircle( float startTime, float endTime )
    {
        mStart = startTime;
        mEnd   = endTime;
        off    = 0;
    }
    
    bool isCircleStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            
            
            frame->addPoly();
            
           
            
            
            
            
         //   frame->colMode = YELLOW;//WHITE_FADE;
        }
        
        off += 0.0200;
        
        if(off > TWO_PI) off = 0.01;
        
        return *frame;
    }
    float off;
    float mStart, mEnd;
};
#endif /* Wipe_h */



