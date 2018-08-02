//
// Created by sangbong on 8/2/18.
//

#include "UndirectedGraph.h"
#include <iostream>
#include <cstring>

UndirectedGraph::UndirectedGraph(int _vertex, int _edge) {

    this->vertex = _vertex;
    this->edge = _edge;
    this->edges = (struct Edge *) malloc(this->edge * sizeof(struct Edge));

}


bool UndirectedGraph::isCycle() {
    int *parent = (int *) malloc(vertex * sizeof(int));

    // -1로 초기화
    memset(parent, -1, sizeof(int) * vertex);

    for (int i = 0; i < edge; ++i) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        // 둘이 같은 집합에 속해있으면 순환된것으로 판단한다

        if (x == y)
            return 1;

        doUnion(parent, x, y);
    }
    return false;
}

/**
 *
 * @param parent
 * @param i
 * @return
 */
int UndirectedGraph::find(int *parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);

}

/**
 * x set의 부모를 y로 가르켜 union 한것과 같은 효과를 낸다.
 * @param parent
 * @param x
 * @param y
 */
void UndirectedGraph::doUnion(int *parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}


