#include <iostream>
#include "tree/RbTree.h"
#include "tree/Heap.h"
#include "sorting/Quicksort.h"
#include "graph/Graph.h"
#include "graph/GraphSearch.h"
#include "graph/undirectional/UndirectedGraph.h"

using namespace std;


void rbTree(int * data) {
    RbTree rbTree1;

    auto quicksort = new Quicksort();

    quicksort->quickSort(data,0, sizeof(data)/sizeof(data[0]) -1);

    std::cout << "\n\n\n" << std::endl;

    rbTree1.deleteValue(7);

    rbTree1.inorder();

    rbTree1.printTree();
}

void minHeap() {
    Heap h(11);
    h.insertKey(3);
    h.insertKey(2);
    // 3이 제거됨
    h.deleteKey(1);
    cout << h.getMin() << " ";
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

}

void bfs(Graph &g) {

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    GraphSearch::bfs(&g, 2);

}

void dfs(Graph &g) {


    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";

    GraphSearch::dfs(&g, 2);
}

void isCyclitic(Graph &g) {

    GraphSearch::isCyclic(&g);
}

void isCyclitic(UndirectedGraph *graph) {

    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;

    // add edge 1-2
    graph->edges[1].src = 1;
    graph->edges[1].dest = 2;

    // add edge 0-2
    graph->edges[2].src = 0;
    graph->edges[2].dest = 2;

    std::cout << graph->isCycle();
}


int main(void) {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0,2);
    g.addEdge(1,2);

    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    bfs(g);
    dfs(g);
    std::cout << "\n";
    isCyclitic(g);

    isCyclitic(new UndirectedGraph(3,3));

    return 0;


}


