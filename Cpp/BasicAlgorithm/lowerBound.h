#pragma once
#include <iostream>

int lowerBound(int a[], int size, int p) {
    int left = 0;
    int right = size - 1;
    int mid;
    int last = -1;
    while (left <= right) {
        //mid = (left + right) / 2;
        mid = left + (right - left) / 2;    //防止 left + right 过大溢出
        if (a[mid] < p) {
            last = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}
