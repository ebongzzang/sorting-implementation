#include <iostream>
#include "tree/RbTree.h"

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;
    std::cout << "n" << std::endl;
}

void insertionSort(int *arr) {
    // 앞쪽부터 정렬됨

    for (int i = 1; i <= 9; i++) {
        int temp = arr[i];
        int aux = i - 1;

        while (aux >= 0 && arr[aux] > temp) {
            // 앞에 값들이 지금 값보다 클때까지 반복, 한칸씩 밀기
            // 즉, temp보다 작은 값의 위치가 나오면 정지
            arr[aux + 1] = arr[aux];
            aux--;
        }
        arr[aux +1] = temp; // 현재 값이 앞에값들보다 작으면 그 위치에서 멈추므로 temp 값을 +1 위치에 대입
    }

    printArray(arr, 10);
}

void selectionSort(int * arr) {
    int indexMin, temp;

    // 앞의 값들이 모두 정렬되면 뒤의 값도 정렬됐으므로 -1

    for (int i=0; i< 9; i++) {
        indexMin = i;
        for (int j= i+ 1; j< 10; j++) {
            // 앞의 값은 정렬됐으므로 제외, +1
            if(arr[j] < arr[indexMin]) {
                // 최소값을 찾음
                indexMin = j;
            }
        }

        // 최소값과 현재 위치 변경
        temp = arr[indexMin];
        arr[indexMin] = arr[i];
        arr[i] = temp;
    }
    printArray(arr, 10);
}

int main(void) {
    int data[10] = {1, 2, 3, 4, 5, 7, 6, 8, 10, 9};
    insertionSort(data);
    selectionSort(data);
}

