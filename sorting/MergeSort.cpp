//
// Created by sangbong on 6/18/18.
//

#include <iostream>
#include "MergeSort.h"

void MergeSort::mergeSort(int *arr, int l, int r) {

    if(l < r) {
        int m = (l +r) / 2;
        // 왼쪽
        mergeSort(arr, l, m);
        // 오른쪽
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);

    }

}

void MergeSort::merge(int *arr, int l, int m, int r) {

    int left, right, k;
    int n1 = m - l + 1;
    // 왼쪽 어레이 크기
    int n2 =  r - m;
    // 오른쪽 어레이 크기


    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (left = 0; left < n1; left++)
        L[left] = arr[l + left];
    for (right = 0; right < n2; right++)
        R[right] = arr[m + 1+ right];


    /* Merge the temp arrays back into arr[l..r]*/
    left = 0; // 왼쪽 어레이 인덱스
    right = 0; // 오른쪽 어레이 인덱스
    k = l; // Initial index of merged subarray

    //왼쪽, 오른쪽 어레이 다 순환할때 까지
    while (left < n1 && right < n2)
    {
        if (L[left] <= R[right])
        {
            arr[k] = L[left];
            left++;
        }
        else
        {
            arr[k] = R[right];
            right++;
        }
        k++;
    }

    // 한쪽이 남아서 둘이 서로 비교할 수 없을때
    /* Copy the remaining elements of L[], if there
       are any */
    while (left < n1)
    {
        arr[k] = L[left];
        left++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (right < n2)
    {
        arr[k] = R[right];
        right++;
        k++;
    }


}

void MergeSort::printArray(int A[], int size)
{
    int i;

    for (i=0; i < size; i++)
        std::cout << A[i];

    std::cout << std::endl;
}