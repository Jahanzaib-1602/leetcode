#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0;  // total chalks required in one iteration
        for(int &chalkReq : chalk){   // time complexity O(n)
            totalChalkSum += chalkReq; 
        }   
        // Number of full iterations possible = k / totalChalkSum

        int remainChalk = k % totalChalkSum;

        // Find the student who will replace the chalk
        for(int i = 0; i < n; i++) {
            if(remainChalk < chalk[i]) {
                return i;
            }
            remainChalk -= chalk[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> chalk = {5, 3, 4}; 
    int k = 20;                   

    int result = solution.chalkReplacer(chalk, k);

    cout << "The student who will replace the chalk is at index: " << result << endl;

    return 0;
}
