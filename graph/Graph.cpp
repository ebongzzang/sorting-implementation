//
// Created by sangbong on 7/30/18.
//

#include "Graph.h"

Graph::Graph(int numOfVertex) {
    this-> V = numOfVertex;
    adj = new list<int>[numOfVertex];
}


void Graph::addEdge(int v, int w) {
    // v 간선에 w 간선을 추가
    adj[v].push_back(w);
}
