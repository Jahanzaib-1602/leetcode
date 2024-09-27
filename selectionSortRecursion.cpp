#include <iostream>
using namespace std;

void selectionSort(int *arr, int beginIndex, int n) {
    // Base case
    if (beginIndex >= n - 1) {
        return;
    }

    int min_index = beginIndex;
    for (int i = beginIndex + 1; i < n; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    // Swap the found minimum element with the first element
    swap(arr[beginIndex], arr[min_index]);

    // Recursive call for the next index
    selectionSort(arr, beginIndex + 1, n);
}

int main() {
    int arr[5] = {2, 5, 1, 6, 9};
    selectionSort(arr, 0, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
