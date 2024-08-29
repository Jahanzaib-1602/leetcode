
// leet code problem no # 1905. Count Sub Islands

#include <iostream>
#include <vector>

using namespace std;

bool checkSubIsland(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    // Check if out of bounds
    if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
        return true;
    }
    // We are in search of only land, not water
    if (grid2[i][j] != 1) {
        return true;
    }
    // Mark as visited
    grid2[i][j] = -1;

    bool result = (grid1[i][j] == 1);
    result = result && checkSubIsland(grid1, grid2, i + 1, j); // Down
    result = result && checkSubIsland(grid1, grid2, i - 1, j); // Up
    result = result && checkSubIsland(grid1, grid2, i, j + 1); // Right
    result = result && checkSubIsland(grid1, grid2, i, j - 1); // Left

    return result;
}

int countSubIslands(const vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int subIslands = 0;
    int m = grid2.size();
    int n = grid2[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                subIslands++;
            }
        }
    }
    return subIslands;
}

int main() {
    // Define grid1 and grid2
    vector<vector<int>> grid1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    };

    vector<vector<int>> grid2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Call countSubIslands and print the result
    int result = countSubIslands(grid1, grid2);
    cout << "Number of sub-islands: " << result << endl;

    return 0;
}
