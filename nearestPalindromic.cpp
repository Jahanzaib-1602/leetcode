
// leetcode problem no # 564. Find the Closest Palindrome

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    long halfToPalindrome(long left, bool even) {
        long resultNum = left;
        if (!even) {
            left = left / 10;
        }

        while (left > 0) {
            int digit = left % 10;
            resultNum = (resultNum * 10) + digit;
            left /= 10;
        }
        return resultNum;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        int mid = len / 2;
        long firstHalf = stol(n.substr(0, len % 2 == 0 ? mid : mid + 1));
      
        vector<long> possibleResults;
        possibleResults.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibleResults.push_back((long)pow(10, len - 1) - 1);
        possibleResults.push_back((long)pow(10, len) + 1);

        long diff         = LONG_MAX;
        long result       = 0;
        long originalNum  = stol(n);

        for (long &num : possibleResults) {
            if (num == originalNum) continue;
            if (abs(num - originalNum) < diff) {
                diff = abs(num - originalNum);
                result = num;
            } else if (abs(num - originalNum) == diff) {
                result = min(result, num);
            }
        }

        return to_string(result);
    }
};

int main() {
    Solution solution;
    string n;
    cout << "Enter a number: ";
    cin >> n;
    string result = solution.nearestPalindromic(n);
    cout << "The nearest palindromic number is: " << result << endl;
    return 0;
}
