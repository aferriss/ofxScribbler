//
//  scribble.cpp
//  scribble
//
//  Created by Adam Ferriss on 7/11/18.
//

#include "scribble.h"

Scribbler::Scribbler(){
    getNewPt = false;
    ptIndex = 0;
}

void Scribbler::setup(int w, int h, int z){
    bounds = ofVec3f(w, h, z);
    ofVec3f pt = ofVec3f(ofRandom(-w/4, w/4), ofRandom(-h/4, h/4), ofRandom(-z, z));
    ofVec3f pt2 = ofVec3f(ofRandom(-w/4, w/4), ofRandom(-h/4, h/4), ofRandom(-z, z));
    ofVec3f pt3 = ofVec3f(ofRandom(-w/4, w/4), ofRandom(-h/4, h/4), ofRandom(-z, z));
    ofVec3f pt4 = ofVec3f(ofRandom(-w/4, w/4), ofRandom(-h/4, h/4), ofRandom(-z, z));
    
    p.curveTo(pt);
    p.curveTo(pt2);
    p.curveTo(pt3);
    p.curveTo(pt4);
}

void Scribbler::draw(int strokeWeight, ofColor color){
    if( getNewPt ){
        
        ptIndex = pastP.getVertices().size()-1;
        ofVec3f pt = ofVec3f(ofRandom(-bounds.x/4, bounds.x/4), ofRandom(-bounds.y/4, bounds.y/4), ofRandom(-bounds.z, bounds.z));
        
        pastP.curveTo(pt);
        
        getNewPt = false;
    }
    
    if(ptIndex < pastP.getVertices().size()){
        p.addVertex(pastP.getVertices()[ptIndex]);
        ptIndex++;
    } else {
        getNewPt = true;
    }
    
    ofSetLineWidth(strokeWeight);
    ofSetColor(color);
    p.draw();
    ofSetColor(255);
}

void Scribbler::erase(int delay){
    vector<ofPoint> pts = p.getVertices();
    if(pts.size() > delay){
        p.getVertices().erase(p.getVertices().begin());
        p.flagHasChanged();
    }
}
