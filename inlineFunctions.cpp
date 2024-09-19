#include <iostream>
using namespace std;

// by making the function inline there is no extra memory usage and no function call overhead 
// inline functions are those in which the function call is replaced by the function body 
// and if the function body is 1 line than compiler obv. makes it inline and if the fucntion body is 2 to 3 lines than it is depend on the compiler it will may be make or not and if the function body is greater than the 3 lines than the compiler does not made it inline altjough if we write a inline keyword with it .
inline int getMax(int&a , int& b){
    return (a>b)?a:b;
}
int main(){
    int a = 1;
    int b= 3;
    int ans = 0;

    ans = getMax(a,b);
    cout<<ans<<endl;
    a = a + 2;
    b = b + 1;

    ans = getMax(a,b);
    cout<<ans<<endl;
}