
// leetcode problem no # 50. Pow(x, n)

#include <iostream>
using namespace std;

class Solution {
public:

    // time complexity is log(n)
    double solve(double x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return solve(1 / x, -n);
        }
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        }
        return x * solve(x * x, (n - 1) / 2);
    }

    double myPow(double x, int n) {
        return solve(x, long(n));
    }
};

int main() {
    Solution solution;

    double x = 2.0; 
    int n = 10;    

    double result = solution.myPow(x, n);

    cout << x << " raised to the power of " << n << " is: " << result << endl;

    return 0;
}
