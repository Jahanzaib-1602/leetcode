#include <iostream>
#include <algorithm>
using namespace std;

bool checkPalindrome(string str , int i , int j){
    // base case
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return checkPalindrome(str, i+1, j-1);
    }
}
int main(){
    string name = "BookkOob";
    cout<<endl;
    transform(name.begin(),name.end(),name.begin(), ::tolower);// for case senstive words
    bool isPalindrome = checkPalindrome(name, 0 , name.length()-1);
    if(isPalindrome){
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not a palindrome"<<endl;
    }
}