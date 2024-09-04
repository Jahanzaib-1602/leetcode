#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * res * x) % m;
        }
        x = (1LL * x * x) % m;
        n = n >> 1;
    }
    return res;
}

int main() {
    int x, n, m;
    
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;
    cout << "Enter the modulus (m): ";
    cin >> m;
    
    int result = modularExponentiation(x, n, m);
    cout << "Result: " << result << endl;

    return 0;
}
