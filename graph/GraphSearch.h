//
// Created by sangbong on 7/30/18.
//

#ifndef SORTING_IMPLEMENTATION_GRAPHSEARCH_H
#define SORTING_IMPLEMENTATION_GRAPHSEARCH_H


#include "Graph.h"

class GraphSearch {
public:
    static void bfs(Graph *graph, int start);
    static void dfs(Graph *graph, int start);

private:
    static void dfsUtil(int v, bool visited[], list<int>* adj);

};


#endif //SORTING_IMPLEMENTATION_GRAPHSEARCH_H
