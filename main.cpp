#include <iostream>
#include "BasicSort.h"

using namespace std;


int main(void) {
    int data[10] = {1, 2, 3, 4, 5, 7, 6, 8, 10, 9};
    BasicSort::insertionSort(data);
    BasicSort::selectionSort(data);
}

