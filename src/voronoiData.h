//
//  voronoiData.h
//  voronoi_test
//
//  Created by Christian Gwiozda on 08.08.14.
//
//

#ifndef __voronoi_test__voronoiData__
#define __voronoi_test__voronoiData__


#include "ofMain.h"


class VertexPoint;
class VoroEdge;

class CellPoint {
public:
    CellPoint(ofVec2f,int);
    ofVec2f point;
    ofVec2f centroid;
    int iD;
    ofMesh cellMesh;
    vector<VertexPoint*> ownVertex;
    vector<VoroEdge*> ownEdges;
    
    void drawCellPoint();
    void drawOwnVertex();
    void drawNeighbours();
    
    void makeCellMesh();
    void drawCellMesh();
    void setCellColor(ofColor);
    
    //terrainstuff
    
    bool water;
    bool hasHeight;
    float elevation;
    bool isCoast;
    bool riverStart;
   };

//---------------------------------------------------------------------
class VertexPoint {
    
public:
    VertexPoint(ofVec2f);
    ofVec2f point;
    vector<CellPoint*> ownCells;
    
    void drawVertex();
    void drawOwnCells();
};

//---------------------------------------------------------------------

class VoroEdge {
    
public:
    VoroEdge();
    VoroEdge(VertexPoint*, VertexPoint*, CellPoint*, CellPoint*);
    VertexPoint  *ptA, *ptB;
    CellPoint *cellA, *cellB;
    
    void drawEdge();
};

#endif /* defined(__voronoi_test__voronoiData__) */
