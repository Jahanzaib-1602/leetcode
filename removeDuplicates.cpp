
// leetcode problem no # 1047. Remove All Adjacent Duplicates In String

#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    int i = 0;
    while (i < s.length()) { 
        if (i < s.length() - 1 && s[i] == s[i + 1]) { 
            s.erase(i, 2); 
            if (i > 0) i--; 
        } else {
            i++; 
        }
    }
    return s;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;  
    string result = removeDuplicates(input);
    cout << "Result after removing duplicates: " << result << endl;
    return 0;
}
