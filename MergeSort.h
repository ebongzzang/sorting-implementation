//
// Created by sangbong on 6/18/18.
//

#ifndef SORTING_IMPLEMENTATION_MERGESORT_H
#define SORTING_IMPLEMENTATION_MERGESORT_H


class MergeSort {


public:
    static void mergeSort(int *arr, int l, int r);

    static void merge(int *arr, int l, int m, int r);

    static void printArray(int A[], int size);

};


#endif //SORTING_IMPLEMENTATION_MERGESORT_H
