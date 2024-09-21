#include <iostream>
#include <algorithm>
using namespace std;

bool checkPalindrome(string str, int i){
    int n = str.length();
    
    // Base case
    if(i >= n - i - 1){
        return true;
    }

    // Compare characters
    if(str[i] != str[n - i - 1]){
        return false;
    }

    // Recursive call
    return checkPalindrome(str, i + 1);
}

int main(){
    string name = "BookkOob";
    cout << endl;

    // Transform the string to lowercase for case insensitivity
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    
    // Check if the string is a palindrome using a single pointer
    bool isPalindrome = checkPalindrome(name, 0);
    
    if(isPalindrome){
        cout << "palindrome" << endl;
    } else {
        cout << "not a palindrome" << endl;
    }
}
