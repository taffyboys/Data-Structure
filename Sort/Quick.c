#include <stdio.h>

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}


void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(arr, low, high);
        QuickSort(arr, low, pivotpos-1);
        QuickSort(arr, pivotpos+1, high);
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
    QuickSort(arr, 0, n-1);
    Print(arr, n);
    return 0;
}