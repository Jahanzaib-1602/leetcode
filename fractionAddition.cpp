
// leetcode problem no # 592. Fraction Addition and Subtraction

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string fractionAddition(string expr) {
        int nume = 0; 
        int deno = 1; 

        int i = 0;
        int n = expr.length();
        while (i < n) {
            int currNume = 0; // Current fraction numerator
            int currDeno = 0; // Current fraction denominator

            bool isNeg = (expr[i] == '-');

            // Skip '+' or '-'
            if (expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            // Build the current numerator
            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            i++; // for skiping the / operation because after building the every numerator / operation must be present.

            if (isNeg) {
                currNume *= -1; 
            }

            // Build the current denumerator

            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            // final numerator and denumerator

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        //  abs is written because wihout it let suppose if we are doing gcd of (-4 , 2) than it take the gcd -4 so i write abs so that it take only absoloute value means without zer0/
        
        int GCD = abs(__gcd(nume, deno));

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};

int main() {
    Solution solution;
    
    // Test case
    string expr = "-1/2+1/3";
    
    string result = solution.fractionAddition(expr);
    cout << "Result of fraction addition: " << result << endl;

    return 0;
}
