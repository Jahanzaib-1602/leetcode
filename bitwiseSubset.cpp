#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int nums[], int n) {
    int totalSubsets = 1 << n; // Total subsets is 2^n

    cout << "Subsets:" << endl;

    // Iterate through all possible subsets
    for (int mask = 0; mask < totalSubsets; ++mask) {
        cout << "{ ";
        for (int i = 0; i < n; ++i) {
            // Check if the i-th bit in mask is set
            if (mask & (1 << i)) {
                cout << nums[i] << " "; // Include nums[i] in the current subset
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    // Example input
    int nums[] = {5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    // Generate and print all subsets
    generateSubsets(nums, n);

    return 0;
}
