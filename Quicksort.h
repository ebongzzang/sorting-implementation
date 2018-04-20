//
// Created by sangbong on 4/19/18.
//

#ifndef SORTING_IMPLEMENTATION_QUICKSORT_H
#define SORTING_IMPLEMENTATION_QUICKSORT_H


class Quicksort {

private:
    int randomPivot(int start, int end);
    int partition(int arr[], int start, int end);
public:
    void quickSort(int arr[], int start, int end);

    void swap(int *a, int *b);
};


#endif //SORTING_IMPLEMENTATION_QUICKSORT_H
