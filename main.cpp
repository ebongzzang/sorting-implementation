#include <iostream>
#include "tree/RbTree.h"
#include "Quicksort.h"

using namespace std;

int main(void) {
    int data[10] = {10,4,2,1,7,3,5,2,1,1};
    RbTree rbTree1;

    Quicksort * quicksort = new Quicksort();

    quicksort->quickSort(data,0, sizeof(data)/sizeof(data[0]) -1);

    quicksort->printArray(data, 10);


    return 0;


}