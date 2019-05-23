//
//  LaserLine.h
//  ShanghaiGrandTheatre
//
//  Created by Jayson Haebich on 10/02/2019.
//

#ifndef LaserLine_h
#define LaserLine_h

struct LaserLine
{
    LaserLine()
    {
        begin= ofVec2f(0,0);
        end  = ofVec2f(0,0);
        col  = ofColor::red;
    }
    
    LaserLine( ofVec2f _begin, ofVec2f _end, ofColor _col)
    {
        begin = _begin;
        end   = _end;
        col   = _col;
    }
    bool continous = false;
    ofVec2f begin, end;
    ofFloatColor col;
};

#endif /* LaserLine_h */
