#pragma once
#include <iostream>

int binarySearch(int a[], int size, int p) {
    int left = 0;
    int right = size - 1;
    int mid;
    int flag = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] > p) {
            right = mid - 1;
        } else if (a[mid] < p) {
            left = mid + 1;
        } else {
            flag = mid;
            break;
        }
    }
    return flag;
}
