//
// Created by sangbong on 7/30/18.
//

#ifndef SORTING_IMPLEMENTATION_GRAPH_H
#define SORTING_IMPLEMENTATION_GRAPH_H

#include <iostream>
#include <list>

using namespace std;

class Graph {

public:
    int V;

    list<int> *adj;

    Graph(int numOfVertex);

    void addEdge(int v, int w);


};


#endif //SORTING_IMPLEMENTATION_GRAPH_H
