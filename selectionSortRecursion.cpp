#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int index = 0) {
    if (index == n - 1) {
        return;
    }

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    swap(arr[index], arr[minIndex]);

    selectionSort(arr, n, index + 1);
}

int main() {
    int arr[5] = {8, 5, 6, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
