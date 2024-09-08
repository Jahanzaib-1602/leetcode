#include <iostream>
using namespace std;
int main(){
    int arr[5]= {1,2,3,4,5};
    char ch[6]="abcde";

    // the difference is that the when u write the arr it prints the address of arr but when u print the ch it prints the whole char array not the address

    cout<<arr<<endl;
    cout<<ch<<endl;

    char *c = &ch[0];
    cout<<c<<endl;

    // random symbol untill it mets the null operator
    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;

}