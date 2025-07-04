#include <stdio.h>

void Insertion(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; ++i) {
        temp = arr[i];
        for (j = i-1; j >= 0 && arr[j] > temp; --j) {
            arr[j+1] = arr[j];
        }
        arr[j] = temp;
    }
}

void Insertion_improve(int arr[], int n) {
    int temp, low, high, mid;
    for (int i = 1; i < n; ++i) {
        temp = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] < temp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        for (int j = i; j > low; --j) {
            arr[j] = arr[j - 1];
        }
        arr[low] = temp;
    }
}

void Print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {5, 4, 2, 9, 10, 33, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insertion_improve(arr, n);
    Print(arr, n);
    return 0;
}