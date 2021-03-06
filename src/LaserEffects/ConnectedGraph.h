//
//  NodeJoin.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef ConnectedGraph_H
#define ConnectedGraph_H

#include "ofxIldaFrame.h"
#include "EffectTime.h"
struct Connection {
    
    Connection(int i1, int i2)
    {
        indx1 = i1;
        indx2 = i2;
    }
    int indx1;
    int indx2;
};

class ConnectedGraph
{
public:
    ConnectedGraph( float timelineStart, float timelineEnd, vector <ofVec2f> points, vector <Connection> connections )
    {
        mTimelineStart = timelineStart;
        mTimelineEnd   = timelineEnd;
        
        mEffectTime = EffectTime(mTimelineStart,mTimelineEnd);
        mPoints = points;
        mConnections = connections;
        
    }
    
    bool isJoinStart( float timelinePos )
    {
        return( timelinePos >= mTimelineStart && timelinePos < mTimelineEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mTimelineStart && timelinePos < mTimelineEnd)
        {
            for( auto &conn : mConnections )
            {
                ofVec2f p1 = mPoints[ conn.indx1 ];
                ofVec2f p2 = mPoints[ conn.indx2 ];
                
                frame->addPoly();
                frame->getLastPoly().color = ofFloatColor(1,1,1);
                frame->getLastPoly().lineTo( p1.x, p1.y );
                frame->getLastPoly().lineTo( p2.x, p2.y );
            }
        }
        
        return *frame;
    }
    std::pair <string, EffectTime> getInfo()
    {
        return std::make_pair("ConnectedGraph", mEffectTime);
    }
    EffectTime mEffectTime;
    vector <ofVec2f>    mPoints;
    vector <Connection> mConnections;
    
    float mTimelineStart, mTimelineEnd;
};

#endif /* NodeJoin_h */

