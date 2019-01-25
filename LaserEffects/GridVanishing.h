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
            float top = 0.75;
            float open = 1.0;
            float timeRunning = timelinePos - mStart;
            if(timeRunning < 4.0)
            {
                top = ofMap(timeRunning,0,4,0.95,0.75);
                open = ofMap(timeRunning,0,4,0.0,1.0);
            }
            frame->setColMode(ColourMode::WHITE_FADE);
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.05, top );
            frame->getLastPoly().lineTo( 0.95, top );
            
            
            
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.95, 0.95 );
            frame->getLastPoly().lineTo( 0.65, top);
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.555, top);
            frame->getLastPoly().lineTo( 0.75, 0.95 );
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.775, top);
            frame->getLastPoly().lineTo( 0.95,  0.95 - 0.1 * open );
            
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.5, top);
            frame->getLastPoly().lineTo( 0.5, 0.95 );
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.05, 0.95 );
            frame->getLastPoly().lineTo( 0.35, top);
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.445, top);
            frame->getLastPoly().lineTo( 0.25, 0.95 );
            
            
            frame->addPoly();
            frame->getLastPoly().color = ofFloatColor(1,1,1);
            frame->getLastPoly().lineTo( 0.25, top);
            frame->getLastPoly().lineTo( 0.05, 0.95 - 0.1 * open );
            
            //frame->colMode = YELLOW;//WHITE_FADE;
        }
        
        return *frame;
    }
    
    float mStart, mEnd;
};
#endif /* Wipe_h */


