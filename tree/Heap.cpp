//
// Created by sangbong on 4/30/18.
//

#include "Heap.h"
#include <iostream>
#include <utility>
#include <climits>


using namespace std;

Heap::Heap(int _capacity) {
    heap_size = 0;
    capacity = _capacity;
    harr = new int[_capacity];
}

void Heap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // 자기 부모와 비교하여 부모가 더 작으면 위치를 바꾼 후 부모를 모두 순회하며 끝까지 비교
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void Heap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void Heap::deleteKey(int i)
{
    // 가장 작은값으로 바꾼 후 제거
    decreaseKey(i, INT_MIN);
    extractMin();
}


int Heap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    // 루트에 제일 작은값을 끌어올린다
    MinHeapify(0);

    return root;
}

void Heap::MinHeapify(int i) {
    // 제일 작은값을 i 위치로 끌어올리는 작업
    int l = left(i);
    int r = right(i);
    int smallest = i;
    /* 자식 노드중 제일 작은거를 골라 재귀 */
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}