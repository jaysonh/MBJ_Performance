//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef LaserGuiCircle_h
#define LaserGuiCircle_h

#include "ofxIldaFrame.h"

class LaserGuiCircle
{
public:
    
    LaserGuiCircle( float startTime, float endTime, ColourMode col )
    {
        mStart = startTime;
        mEnd   = endTime;
        
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
            
            if(timeRunning < OPEN_TIME)
            {
                opening = ofMap(timeRunning, 0, OPEN_TIME, 0, 1);
               
            }
            
            if(timeFromEnd < OPEN_TIME)
            {
                opening = ofMap(timeFromEnd, 0, OPEN_TIME, 0, 1);
                
            }
            
            ofVec2f middle = ofVec2f(0.5,0.5);
            float   radius = 0.25;
            
            if(opening < 1.0)
            {
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                
                for( float angle = -PI/2; angle < PI/2; angle += 0.1)
                {
                    float x = middle.x + radius * cos(angle);
                    float y = middle.y + radius * sin(angle);
                    if(y < opening)
                        frame->getLastPoly().lineTo(x,y);
                }
                
                frame->addPoly();
                
                for( float angle = PI/2; angle < PI/2 + PI; angle += 0.1)
                {
                    float x = middle.x + radius * cos(angle);
                    float y = middle.y + radius * sin(angle);
                    if(y < opening)
                        frame->getLastPoly().lineTo(x,y);
                }
            }else
            {
                float targetAngle = TWO_PI*(ofGetElapsedTimef()*0.1 - (float)((int)ofGetElapsedTimef()));
                
                frame->addPoly();
                ofVec2f leg1Start = ofVec2f( middle.x + radius * cos(targetAngle),
                                            middle.y + radius * sin(targetAngle)  );
                ofVec2f leg1End   = ofVec2f( middle.x + (radius+0.05) * cos(targetAngle),
                                            middle.y + (radius+0.05) * sin(targetAngle)  );
                frame->getLastPoly().lineTo(leg1Start.x, leg1Start.y);
                frame->getLastPoly().lineTo(leg1End.x,   leg1End.y);
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                
                for( float angle = targetAngle; angle <targetAngle + PI; angle += 0.1)
                {
                    float x = middle.x + radius * cos(angle);
                    float y = middle.y + radius * sin(angle);
                    
                    frame->getLastPoly().lineTo(x,y);
                }
                
                ofVec2f leg2Start = ofVec2f( middle.x + radius * cos(targetAngle+PI),
                                            middle.y + radius * sin(targetAngle+PI)  );
                ofVec2f leg2End   = ofVec2f( middle.x + (radius+0.05) * cos(targetAngle+PI),
                                            middle.y + (radius+0.05) * sin(targetAngle+PI)  );
                frame->getLastPoly().lineTo(leg2Start.x, leg2Start.y);
                frame->getLastPoly().lineTo(leg2End.x,   leg2End.y);
                
                 frame->addPoly();
                for( float angle = targetAngle +PI; angle <targetAngle + TWO_PI; angle += 0.1)
                {
                    float x = middle.x + radius * cos(angle);
                    float y = middle.y + radius * sin(angle);
                    
                    frame->getLastPoly().lineTo(x,y);
                }
            }
        }
        
        return *frame;
    }
    const float OPEN_TIME = 4.0;
    
    float mStart, mEnd;
};
#endif



