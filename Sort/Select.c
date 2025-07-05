#include <stdio.h>

void SelectSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void Print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {49, 38, 65, 97, 76, 13, 27};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectSort(arr, n);
    Print(arr, n);
    return 0;
}
