#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {}; // Return an empty array if reshaping is not possible
        }

        vector<vector<int>> result(m, vector<int>(n)); // Create a 2D array with m rows and n columns
        for (int i = 0; i < original.size(); ++i) {
            result[i / n][i % n] = original[i]; // Map 1D index to 2D index
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> original = {1, 2, 3, 4, 5, 6};
    int m = 2;
    int n = 3;

    vector<vector<int>> result = solution.construct2DArray(original, m, n);

    // Print the 2D array
    if (result.empty()) {
        cout << "Cannot reshape the array into the given dimensions." << endl;
    } else {
        for (const auto& row : result) {
            for (int elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
