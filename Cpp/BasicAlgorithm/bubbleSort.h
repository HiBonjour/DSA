#pragma once
#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int j = n - 1; j > 0; j--) {
        bool flag = true;
        for (int i = 0; i < j; i++) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = false;
            }
        }
        if (flag)
            break;
    }
}
