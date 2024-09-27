
// leetcode problem no # 50. Pow(x, n)
#include <iostream>
using namespace std;

double myPow(double x, long n) {
    if (n < 0) {
        return 1.0 / myPow(x, -n);
    }

    // Base cases
    if (n == 0) { 
        return 1;
    }
    if (n == 1) {
        return x;
    }

    // Recursive call
    double ans = myPow(x, n / 2);

    // If n is even
    if (n % 2 == 0) {
        return ans * ans;
    } else {
        // If n is odd
        return x * ans * ans;
    }
}

int main() {
    double x;
    long n;

    // Example input
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
