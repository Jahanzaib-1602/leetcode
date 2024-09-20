#include <iostream>
using namespace std;

int firstOccUtil(int arr[], int s, int e, int key) {
    if (s > e) return -1; // Base case: not found

    int mid = s + (e - s) / 2;

    if (arr[mid] == key) {
        // Check if it's the first occurrence
        if (mid == 0 || arr[mid - 1] < key) {
            return mid;
        } else {
            return firstOccUtil(arr, s, mid - 1, key); // Search in the left half
        }
    } else if (key < arr[mid]) {
        return firstOccUtil(arr, s, mid - 1, key); // Search in the left half
    } else {
        return firstOccUtil(arr, mid + 1, e, key); // Search in the right half
    }
}

int lastOccUtil(int arr[], int s, int e, int key) {
    if (s > e) return -1; // Base case: not found

    int mid = s + (e - s) / 2;

    if (arr[mid] == key) {
        // Check if it's the last occurrence
        if (mid == e || arr[mid + 1] > key) {
            return mid;
        } else {
            return lastOccUtil(arr, mid + 1, e, key); // Search in the right half
        }
    } else if (key < arr[mid]) {
        return lastOccUtil(arr, s, mid - 1, key); // Search in the left half
    } else {
        return lastOccUtil(arr, mid + 1, e, key); // Search in the right half
    }
}

void firstAndLastPosition(int arr[], int n, int k, int& first, int& last) {
    first = firstOccUtil(arr, 0, n - 1, k);
    last = lastOccUtil(arr, 0, n - 1, k);
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int first = -1, last = -1;

    firstAndLastPosition(arr, n, key, first, last);

    cout << "First occurrence of " << key << " is at index: " << first << endl;
    cout << "Last occurrence of " << key << " is at index: " << last << endl;

    return 0;
}
