// leet code problem no #74. Search a 2D Matrix

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col;
        int start = 0;
        int end = n - 1;
        int mid = (start + end) / 2;

        while (start <= end) {
            int element = matrix[mid / col][mid % col];

            if (element == target) {
                return true;
            }
            if (element < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
