#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n) { // Pass by reference
    for (int i = 1; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // It means already sorted
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
