#include <stdio.h>

void Insertion(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i-1]) {
            for (int j = i - 1; arr[j+1] < arr[j]; --j) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
            
    }
}

void Print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 9, 10, 33, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insertion(arr, n);
    Print(arr, n);
    return 0;
}