//
// Created by sangbong on 4/30/18.
//

#ifndef SORTING_IMPLEMENTATION_HEAP_H
#define SORTING_IMPLEMENTATION_HEAP_H


class Heap {

    int *harr;
    int capacity;
    int heap_size;

public:
    Heap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin() { return harr[0]; }

    void deleteKey(int i);

    void insertKey(int k);

};


#endif //SORTING_IMPLEMENTATION_HEAP_H
