#include <stdio.h>

void swap(int *a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        for (int j = n-1; j > i; --j) {
            if ( arr[j-1] > arr[j]) {
                swap(&arr[j-1], &arr[j]);
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
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
    BubbleSort(arr, n);
    Print(arr, n);
    return 0;
}