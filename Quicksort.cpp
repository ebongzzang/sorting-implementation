//
// Created by sangbong on 4/19/18.
//

#include "Quicksort.h"
#include <cstdlib>
#include <iostream>

//Lomuto partition

int Quicksort::partition(int *arr, int low, int high) {
    printArray(arr, 10);

    int pivot =arr[ high];
    int left = low-1;

    // 피봇 마지막 값 까지 회전
    for(int j = low; j <= high -1; j++) {
        // j가 만약 pivot보다 작다면 i를 한칸 늘리고 교환
        if(arr[j] <= pivot) {
            left++;
            swap(&arr[left], &arr[j]);
        }
    }
    // 루프가 끝난 뒤 i+1는 피봇보다 큰값중 하나이므로 교환
    swap(&arr[left +1], &arr[high]);
    return left+1;
}

void Quicksort::quickSort(int *arr, int low, int high) {

    if (low < high) {
        int pivot = partition(arr, low, high); // 정렬 완료됨

        quickSort(arr, low, pivot-1);
        // 처음부터 피봇 전까지 (피봇보다 작은 값들 정렬)
        quickSort(arr, pivot +1, high);
        // 피봇 다음부터 마지막까지 (피봇보다 큰 값들 정렬)

    }

}

void Quicksort::printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "\t";
    std::cout << "\n" << std::endl;
}


void Quicksort::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
