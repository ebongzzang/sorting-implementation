#include <iostream>
#include "tree/RbTree.h"
#include "tree/Heap.h"
#include "sorting/Quicksort.h"
#include "graph/Graph.h"
#include "graph/GraphSearch.h"

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

void bfs() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0,2);
    g.addEdge(1,2);

    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    GraphSearch::bfs(&g, 2);



}
int main(void) {
    int data[10] = {1, 2, 5, 4, 3, 6, 9, 8, 7, 0};
    rbTree(data);

    minHeap();
    bfs();

    return 0;


}


