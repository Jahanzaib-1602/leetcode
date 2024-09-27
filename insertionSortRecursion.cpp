#include <stdio.h>

void recursiveInsertionSort(int arr[], int n) {
    // Base case: If the array has one or zero elements, it's already sorted
    if (n <= 1) {
        return;
    }

    // Sort the first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element at the correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Move elements of arr[0..n-2], that are greater than last, to one position ahead of their current position
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;  // Place last in the correct position
}

// Function to print the array (for testing)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    recursiveInsertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
