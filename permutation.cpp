

// leetcode problem no # 567. Permutation in String


#include <iostream>
#include <string>
using namespace std;

// Helper function to check if two frequency arrays are equal
bool checkEqual(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Function to check if a permutation of s1 is a substring of s2
bool checkInclusion(const string& s1, const string& s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2) return false;
    
    int count[26] = {0};
    for (int i = 0; i < len1; i++) {
        count[s1[i] - 'a']++;
    }
    
    int windowSize = len1;
    int currentCount[26] = {0};
    for (int i = 0; i < windowSize; i++) {
        currentCount[s2[i] - 'a']++;
    }
    
    if (checkEqual(count, currentCount)) return true;
    
    for (int i = windowSize; i < len2; i++) {
        currentCount[s2[i] - 'a']++;  // Add new character to the window
        currentCount[s2[i - windowSize] - 'a']--;  // Remove old character from the window
        
        if (checkEqual(count, currentCount)) return true;
    }
    
    return false;
}

int main() {
    string s1, s2;

    // Read input strings
    cout << "Enter the first string (s1): ";
    getline(cin, s1);
    cout << "Enter the second string (s2): ";
    getline(cin, s2);

    // Check for permutation and display result
    bool result = checkInclusion(s1, s2);
    cout << (result ? "True" : "False") << endl;
    
    return 0;
}
