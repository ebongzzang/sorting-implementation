//
// Created by sangbong on 8/3/18.
//

#include <algorithm>
#include <iostream>
#include "KruskalsMst.h"

/**
 *
 * @param subsets
 * @param i
 * @return
 */
int KruskalsMst::find(subset *subsets, int i) {

    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;

}

/**
 * union by rank
 * @param subsets
 * @param x 비교할 노드1
 * @param y 비교할 노드2
 */
void KruskalsMst::doUnion(subset *subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

/**
 * 최단 경로 서브셋 트리를 빌드
 * 순환 vertex는 제외
 * @param graph
 */
void KruskalsMst::buildMst(UndirectedGraph *graph) {
    int V = graph->edge;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    //sort edges by weight as asc order
    std::qsort(graph->edges, V, sizeof(graph->edges[0]), [](const void *a, const void *b) {

        Edge arg1 = *static_cast<const struct Edge *>(a);
        Edge arg2 = *static_cast<const struct Edge *>(b);

        if (arg1.weight > arg2.weight) return 1;
        else if (arg1.weight < arg2.weight) return -1;
        else return 0;
    });

    struct subset *subsets = (struct subset *) malloc(V * sizeof(struct subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // 처음 제외
    while (e < V - 1) {
        struct Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // 순환되는 vertex가 아니면 result에 삽입
        if (x != y) {
            result[e++] = next_edge;
            doUnion(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e - 1; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
               result[i].weight);
    return;
}

