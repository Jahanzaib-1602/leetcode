#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        int ans = climbStairs(n - 2) + climbStairs(n - 1);
        return ans;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the number of stairs: ";
    cin >> n;

    int result = solution.climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << result << endl;

    return 0;
}
