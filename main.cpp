#include <iostream>
#include "tree/RbTree.h"

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;
    std::cout << "n" << std::endl;
}

void insertionSort(int *arr) {


    for (int i = 1; i <= 9; i++) {
        int temp = arr[i];
        int aux = i - 1;

        while (aux >= 0 && arr[aux] > temp) {
            arr[aux + 1] = arr[aux];
            aux--;
        }
        arr[aux +1] = temp;
    }

    printArray(arr, 10);
}

int main(void) {
    int data[10] = {1, 2, 3, 4, 5, 7, 6, 8, 10, 9};
    insertionSort(data);

}

