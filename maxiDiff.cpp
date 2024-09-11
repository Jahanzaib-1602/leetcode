#include <iostream>
#include <limits.h>
using namespace std;

void maxiDiff(int arr[], int n) {
    int minElement = arr[0];
    int maxDiff = INT_MIN;

    for (int i = 1; i < n; i++) {
        int diff = arr[i] - minElement;
        if (diff > maxDiff) {
            maxDiff = diff;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    cout << "maxDiff : " << maxDiff << endl;
}

int main() {
    int arr[5] = {2, 5, 6, 7, 9};
    maxiDiff(arr, 5);
}
