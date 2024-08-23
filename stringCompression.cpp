#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int index = 0;
    int i = 0;
    int n = chars.size();
    
    while(i < n) {
        int count = 0;
        char currentChar = chars[i];
        
        while(i < n && chars[i] == currentChar) {
            i++;
            count++;
        }
        
        chars[index] = currentChar;
        index++;
        
        if(count > 1) {
            string count_str = to_string(count);
            for(char &ch : count_str) {
                chars[index] = ch;
                index++;
            }
        }
    }
    
    return index;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    int compressedLength = compress(chars);
    
    cout << "Compressed String: ";
    for(int i = 0; i < compressedLength; i++) {
        cout << chars[i];
    }
    cout << endl;
    
    cout << "Compressed Length: " << compressedLength << endl;
    
    return 0;
}
