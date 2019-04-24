#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#define numVertex(V) V->numVertex
#define firstEdge(V) V->firstEdge
#define nextVertex(V) V->nextVertex
#define source(E) E->source
#define dest(E) E->dest
#define sNextEdge(E) E->sNextEdge
#define dNextEdge(E) E->dNextEdge
#define firstSource(G) G.firstSource
#define firstDest(G) G.firstDest

using namespace std;

typedef struct elmtVertex *adrVertex;
typedef struct elmtEdge *adrEdge;

struct elmtVertex{
    int numVertex;
    adrEdge firstEdge;
    adrVertex nextVertex;
};

struct elmtEdge{
    int source;
    int dest;
    adrEdge sNextEdge;
    adrEdge dNextEdge;
};

struct graph{
    adrVertex firstSource;
    adrVertex firstDest;
};


#endif // GRAPH_H_INCLUDED
