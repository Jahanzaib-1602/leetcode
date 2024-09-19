#include <iostream>
using namespace std;


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