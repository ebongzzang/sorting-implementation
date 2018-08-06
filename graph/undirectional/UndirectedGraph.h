//
// Created by sangbong on 8/2/18.
//

#ifndef SORTING_IMPLEMENTATION_UNDIRECTEDGRAPH_H
#define SORTING_IMPLEMENTATION_UNDIRECTEDGRAPH_H

struct Edge {
    int src;
    int dest;
    int weight;

};

struct subset
{
    int parent;
    int rank;
};

class UndirectedGraph {

public:
    //TODO: varargs로 변경
    UndirectedGraph(int _vertex, int _edge);
    bool isCycle();
    Edge *edges;
    int vertex;
    int edge;

private:

    int find(int parent[], int i);

    void doUnion(int parent[], int x, int y);


};


#endif //SORTING_IMPLEMENTATION_UNDIRECTEDGRAPH_H
