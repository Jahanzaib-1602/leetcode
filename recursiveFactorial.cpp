#include <iostream>
using namespace std;

/*there are two pattern of recursion 
one is head recursion and the other one is tail

if base case is on the top and than recursive relation is written and at the last processing is done than it is the head recursion and if the base case is on the top and at the second number is processing and at the end there is a recursive relation than it is the tail recursion*/

int factorial(int n){
    //base case 
    if(n == 0)
        return 1;

    //recursive relation

    int smallerProblem = factorial(n-1);
    int biggerProblem = n * smallerProblem;

    return biggerProblem;
    
}
int main(){
    int n;
    cout<<"Enter the number to find the factorial"<<endl;
    cin>>n;

    int ans = factorial(n);

    cout<<ans<<endl;

}