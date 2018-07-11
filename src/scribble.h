//
//  scribble.h
//  scribble
//
//  Created by Adam Ferriss on 7/11/18.
//

#ifndef scribble_h
#define scribble_h

#include "ofMain.h"

class Scribbler {
    ofPolyline p, pastP;
    bool getNewPt;
    int ptIndex;
    ofVec3f bounds;
    
    
public:
    Scribbler();
    
    void setup(int xBound, int yBound, int zBound);
    void draw(int strokeWeight, ofColor color);
    void erase(int delay);
    
};


#endif /* scribble_h */
