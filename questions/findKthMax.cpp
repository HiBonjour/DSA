#include <iostream>
using namespace std;
void kmax(int arr[], int left, int right, int k);
int main() {
    int n, k;
    int* arr;
    cout << "How many numbers do you have:" << endl;
    cin >> n;
    arr = new int[n];
    cout << "Please type your numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Please type k-th:" << endl;
    cin >> k;
    kmax(arr, 0, n - 1, k);
    cout << arr[n - k];
    delete[] arr;
    return 0;
}

void kmax(int arr[], int left, int right, int k) {
    int i = left;
    int j = right;
    int partition = arr[i];
    while (i != j) {
        while (i < j && arr[j] >= partition) {
            j--;
        }
        swap(arr[i], arr[j]);
        while (i < j && arr[i] < partition) {
            i++;
        }
        swap(arr[i], arr[j]);
    }
    if (right - i + 1 == k)
        return;
    else if (right - i + 1 > k)
        kmax(arr, i + 1, right, k);
    else if (left - i + 1 < k)
        kmax(arr, left, i - 1, k-(right - i + 1));
}
