
// leetcode problem no #204. Count Primes

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n + 1, true); 

        if (n <= 2) {
            return 0; 
        }

        prime[0] = prime[1] = false; 

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = false; 
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    cout<<"enter the number"<<endl;
    int n;
    cin>>n;
    int primeCount = solution.countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << primeCount << endl;
    return 0;
}
