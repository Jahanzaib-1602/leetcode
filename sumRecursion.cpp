#include<iostream> 
using namespace std;

int sumRecursion(int arr[],int size){
    //base case
    if(size == 0){
        return 0;
    }

    return arr[0] + sumRecursion(arr+1,size-1);

}

int main(){
    int arr[5]={2,3,5,6,7};
    int size = 5;
    int sum = sumRecursion(arr,5);

    cout<<"The sum of an array is : "<<sum<<endl;
}