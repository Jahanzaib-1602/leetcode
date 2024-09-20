#include <iostream>
using namespace std;

void reverseRecursion(string& str , int left , int right){
    //base condition
    if(left>right){
        return ;
    }

    swap(str[left],str[right]);
    left++;
    right--;

    reverseRecursion(str, left, right);

}
int main(){
    //two pointer approach
    string st="zabbe";
    reverseRecursion(st,0,st.size()-1);
    cout<<st<<endl;

}

// 1 pointer approach
/*void reverse(string& str, int i) {
    if (i == str.length()) return;

    reverse(str, i + 1);
    cout << str[i]; 
}*/
