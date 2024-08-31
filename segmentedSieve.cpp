// segmentedSieve countPrimes problem

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> seive(int n){
    bool ar[n+1];
    for(int i = 0; i<=n;i++) {
       ar[i]=true;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(ar[i]) {
            for(int j = i*i; j <= n; j += i) {
                ar[j] = false;
            }
        }
    }
    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        if(ar[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r;
    bool ar[r-l+1];
    for(int i = 0; i < (r-l+1); i++) {
        ar[i] = true;
    }
    vector<int> v = seive(sqrt(r));
    for(auto p : v) {
        int st = max(p*p, (l + p - 1) / p * p);  
    
       
        for(int j = st; j <= r; j += p) {
            ar[j-l] = false;
        }
    }
    for(int i = 0; i < (r-l+1); i++) {
        if(ar[i]) {
            cout << i + l << " ";
        }
    }
}
