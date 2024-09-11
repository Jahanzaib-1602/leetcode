#include <iostream>
using namespace std;

void insertElement(int arr[], int n, int element) {
    int i = n - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n + 1]; 

    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int element;
    cout << "Enter the element to insert: ";
    cin >> element;

    insertElement(arr, n, element);

    cout << "Array after insertion: ";
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
