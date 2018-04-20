//
// Created by sangbong on 4/19/18.
//

#include "Quicksort.h"
#include <cstdlib>

int Quicksort::randomPivot(int start, int end) {
    srand(time(NULL));
    return start + rand() % (end - start);

}

//Lomuto partition

int Quicksort::partition(int *arr, int low, int high) {
    int pivot = arr[high];// pivot
    int i = (low - 1);  // 작은 값 경계, 지금은 작은값을 발견 못했으므로 -1

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot) //작은 값을 발견하면
        {
            i++;    // 작은 값들의 공간 인덱스 + 1
            swap(&arr[i], &arr[j]); // 그 공간에 넣기
        }
        else {
            // 큰 값들의 경우 스왑할 필요 없음 (마지막에 피봇이 스왑되니까)
        }
    }
    swap(&arr[i + 1], &arr[high]); // 교환
    return (i + 1);
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

void Quicksort::swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}