#include "graph.h"

adrVertex createVertex(int nomor){
    adrVertex P;
    P = new elmtVertex;
    numVertex(P) = nomor;
    firstEdge(P) = NULL;
    nextVertex(P) = NULL;
    return P;
}
graph createGraph(){
    graph G;
    adrVertex P;
    //source
    P = createVertex(1);
    firstSource(G) = P;
    P = createVertex(10);
    nextVertex(firstSource(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstSource(G))) = P;
    //destination
    P = createVertex(1);
    firstDest(G) = P;
    P = createVertex(10);
    nextVertex(firstDest(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstDest(G))) = P;
    P = createVertex(21);
    nextVertex(nextVertex(nextVertex(firstDest(G)))) = P;

    return G;
}
adrEdge createEdge(int asal, int tujuan){
    adrEdge P = new elmtEdge;
    source(P) = asal;
    dest(P) = tujuan;
    sNextEdge(P) = NULL;
    dNextEdge(P) = NULL;
    return P;
}
adrVertex sourceVertex (int numVertex,graph G){
    adrVertex P = firstSource(G);
    while (P != NULL && numVertex(P) != numVertex){
        P = nextVertex(P);
    }
    return P;
}
adrVertex destinationVertex (int numVertex,graph G){
    adrVertex P = firstDest(G);
    while (P != NULL && numVertex(P) != numVertex){
        P = nextVertex(P);
    }
    return P;
}

void addEdge(int A,int B, graph G){
    adrVertex Source = sourceVertex(A,G);
    adrVertex Dest = destinationVertex(B,G);
    if (Source != NULL && Dest != NULL){
        adrEdge E = createEdge(A, B);

        sNextEdge(E) = firstEdge(Source);
        firstEdge(Source) = E;

        dNextEdge(E) = firstEdge(Dest);
        firstEdge(Dest) = E;
    }
}

