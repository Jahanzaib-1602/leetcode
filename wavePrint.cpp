#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int nCols) {
    vector<int> ans;
    
    for(int col = 0; col < nCols; col++) {
        if(col & 1) { // odd index
            for(int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else { // even index
            for(int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main() {
    int nRows = 3;
    int nCols = 3;
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = wavePrint(arr, nRows, nCols);

    cout << "Wave print of the array is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
