#include <iostream>
#include "tree/RbTree.h"
#include "tree/Heap.h"

using namespace std;

void rbTree(int * data) {
    RbTree rbTree1;

    for (int i = 0; i < (sizeof(data) / sizeof(int)); i++) {
        rbTree1.insertValue(data[i]);
    }

    rbTree1.inorder();

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

int main(void) {
//    int data[10] = {1, 2, 5, 4, 3, 6, 9, 8, 7, 0};
//    rbTree(data);

    minHeap();


    return 0;


}
