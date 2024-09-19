

// leetcode problem no # 509. Fibonacci Number

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        int ans = fib(n-1) + fib(n-2);
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cin>>n;
    int result = solution.fib(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;
    return 0;
}
