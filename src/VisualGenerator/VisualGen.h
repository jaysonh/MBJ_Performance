//
//  VisualGen.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 18/05/2019.
//

#ifndef VisualGen_h
#define VisualGen_h

#include "EffectTime.h"

class VisualGen
{
public:
    
    virtual void update( float timelinePos ) = 0; // will draw directly into whatever open fbo 
    
protected:
    EffectTime mEffectTime;
    
    
    
};
#endif /* VisualGen_h */
