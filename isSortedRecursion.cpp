#include<iostream> 
using namespace std;

bool isSorted(int arr[],int size){
    //base case
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remainingpart = isSorted(arr+1,size-1);
        return remainingpart;
    }
}

int main(){
    int arr[5]={2,3,5,6,7};
    int size = 5;
    int ans = isSorted(arr,5);
    if(ans){
        cout<<"The array is sorted "<<endl;
    }  
    else{
        cout<<"The array is not sorted "<<endl;
    }
}