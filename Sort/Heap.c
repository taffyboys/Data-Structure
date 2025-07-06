#include <stdio.h>

// arr[0]存储临时变量，数组从arr[1]开始计算

void HeadAdjust(int arr[], int k, int len) {
    arr[0] = arr[k];
    for (int i = 2*k; i <= len; i = i*2) {
        if (i < len && arr[i] < arr[i+1]) {
            ++i;
        }
        if (arr[0] > arr[i]) {
            break;
        } else {
            arr[k] = arr[i];
            k = i;
        }
        arr[k] = arr[0];
    }
}

void BuildMaxHeap(int arr[], int len) {
    for (int i = len/2; i > 0; --i) {
        HeadAdjust(arr, i, len);
    }
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapSort(int arr[], int len) {
    BuildMaxHeap(arr, len);
    for (int i = len; i > 1; --i) {
        Swap(&arr[i], &arr[1]);
        HeadAdjust(arr, 1, i-1); //最小元素下沉，最大元素上浮
    }
}

void Print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {0, 49, 38, 65, 97, 76, 13, 27};
    int len = sizeof(arr)/sizeof(arr[0])-1;
    HeapSort(arr, len);
    Print(arr+1, len);
    return 0;
}