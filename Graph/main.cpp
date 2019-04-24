#include "graph.cpp"
int main()
{
    graph G;
    G = createGraph();
    adrVertex V = firstSource(G);
    cout<<"Simpul asal: ";
    while (V!=NULL){
        cout<<numVertex(V)<<", ";
        V = nextVertex(V);
    }
    cout<<endl;cout<<endl;
    cout<<"Simpul tujuan: ";
    adrVertex E = firstDest(G);
    while (E!=NULL){
        cout<<numVertex(E)<<", ";
        E = nextVertex(E);
    }
    cout<<endl;cout<<endl;

    addEdge(17, 21, G);
    addEdge(17, 1, G);
    addEdge(10, 17, G);
    addEdge(10, 1, G);
    addEdge(1, 21, G);
    addEdge(1, 10, G);

    adrVertex P = firstSource(G);
    while (P != NULL){
        cout << "Source Vertex : " << numVertex(P);
        adrEdge E = firstEdge(P);
        while (E != NULL){
            cout <<" => "<< dest(E) <<" ";
            E = sNextEdge(E);
        }
        P = nextVertex(P);
        cout << endl;
    }
    return 0;
}
