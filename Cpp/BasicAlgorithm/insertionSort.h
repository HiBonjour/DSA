#pragma once
#include <iostream>

void insertionSort(int arr[], int n) {
    int i, j, temp;
    for (j = 1; j < n; j++) {
        temp = arr[j];
        for (i = j - 1; i >= 0 && arr[i] > temp; i--) {
            arr[i + 1] = arr[i];
        }
        arr[i+1] = temp;
    }
}
