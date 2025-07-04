#include <stdio.h>

void Shell(int arr[], int n) {
    int i, j, d, temp;
    for (d = n/2; d >= 1; d = d/2) {
        for (i = d; i < n; ++i) {
            temp = arr[i];
            for (j = i; j >= d && arr[j-d] > temp; j = j-d) {
                arr[j] = arr[j-d];
            }
            arr[j] = temp;
        }
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
    Shell(arr, n);
    Print(arr, n);
    return 0;
}