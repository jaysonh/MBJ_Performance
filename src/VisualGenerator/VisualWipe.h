//
//  VisualWipe.h
//  MarijaSonicActs
//
//  Created by Jayson Haebich on 18/05/2019.
//

#ifndef VisualWipe_h
#define VisualWipe_h

#include "VisualGen.h"

class VisualWipe : public VisualGen
{
public:
    void update( float timelinePos ); // will draw directly into whatever open fbo
    
private:
    
};

#endif /* VisualWipe_h */
