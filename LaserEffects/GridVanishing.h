//
//  Wipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 07/02/2018.
//

#ifndef GridVanishing_h
#define GridVanishing_h

class GridVanishing
{
public:
    
    GridVanishing( float startTime, float endTime )
    {
        mStart = startTime;
        mEnd   = endTime;
        off1    =0;
        off2=0;
    }
    
    bool isGridStart( float timelinePos )
    {
        return( timelinePos >= mStart && timelinePos < mEnd );
    }
    
    ofxIlda::Frame getFrame( float timelinePos, ofxIlda::Frame *frame )
    {
        if( timelinePos >= mStart && timelinePos < mEnd)
        {
            
            /*
             bool left = true;
             for( float a = 0; a < PI/2; a+= 0.4)
             {
             float h = 1.0-0.5 * sin(a);
             frame->addPoly();
             frame->getLastPoly().color = ofFloatColor(1,1,1);
             
             if(left)
             {
             frame->getLastPoly().lineToCol( 1.0, h );
             frame->getLastPoly().lineToCol( 0.0, h);
             }else
             {
             frame->getLastPoly().lineToCol( 0.0, h );
             frame->getLastPoly().lineToCol( 1.0, h);
             
             }
             left = !left;
             
             }*/
            
            /*
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 1.0, 0.5 );
            frame->getLastPoly().lineToCol( 0.0, 0.5);
            
            
            
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 1.0, 1.0 );
            frame->getLastPoly().lineToCol( 0.65, 0.5);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.75, 1.0 );
            frame->getLastPoly().lineToCol( 0.575, 0.5);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 1.0,  0.75 );
            frame->getLastPoly().lineToCol( 0.775, 0.5);
            
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.5, 1.0 );
            frame->getLastPoly().lineToCol( 0.5, 0.5);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.0, 1.0 );
            frame->getLastPoly().lineToCol( 0.35, 0.5);
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.25, 1.0 );
            frame->getLastPoly().lineToCol( 0.425, 0.5);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.0,  0.75 );
            frame->getLastPoly().lineToCol( 0.25, 0.5);
            */
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.95, 0.75 );
            frame->getLastPoly().lineToCol( 0.05, 0.75);
            
            
            
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.95, 0.95 );
            frame->getLastPoly().lineToCol( 0.65, 0.75);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.75, 0.95 );
            frame->getLastPoly().lineToCol( 0.555, 0.75);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.95,  0.8 );
            frame->getLastPoly().lineToCol( 0.775, 0.75);
            
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.5, 0.95 );
            frame->getLastPoly().lineToCol( 0.5, 0.75);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.05, 0.95 );
            frame->getLastPoly().lineToCol( 0.35, 0.75);
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.25, 0.95 );
            frame->getLastPoly().lineToCol( 0.445, 0.75);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineToCol( 0.05,  0.8 );
            frame->getLastPoly().lineToCol( 0.25, 0.75);
            
            frame->colMode = YELLOW;//WHITE_FADE;
        }
        off1 += 0.01;
        off2 += 0.05;
        if(off1 > PI/2)
            off1=0;
        
        if(off2 > PI/2)
            off2=0;
        
        return *frame;
    }
    float off1,off2;
    float mStart, mEnd;
};
#endif /* Wipe_h */


